#include "OperateFactory.hpp"

using namespace std;

OperateFactory::OperateFactory() {
	loadOperateType();
}

bool OperateFactory::loadOperateType() {
	appendOperateType(OperateInsert::getType());
	appendOperateType(OperateCreate::getType());
	return true;
}

bool OperateFactory::appendOperateType(OperateType type) {
	op_type_list.push_back(type);
	return true;
}

bool OperateFactory::appendOperateType(vector<OperateType> type_list) {
	for (size_t i = 0; i < type_list.size(); ++i) {
		appendOperateType(type_list[i]);
	}
	return true;
}

Operate* OperateFactory::getOperateByFileName(String file_name) {
	ifstream fin(file_name);
	if (!fin.good()) {
		fin.close();
		return nullptr;
	}
	Operate* res = getOperateFromFile(fin);
	fin.close();
	return res;
}

Operate* OperateFactory::getOperateFromFile(ifstream &in) {
	String text, s;
	do {
		in >> s;
		text.append(s);
		text.append(" ");
	} while (s.back() != ';');
	return getOperateFromString(text);
}

Operate* OperateFactory::getOperateFromCommand() {
	String text, s;
	do {
		cin >> s;
		text.append(s);
		text.append(" ");
	} while (s.back() != ';');
	return getOperateFromString(text);
};

Operate* OperateFactory::getOperateFromString(String text) {
	text = text.toUpperCase();
	for (size_t i = 0; i < op_type_list.size(); ++i) {
		if (op_type_list[i].checker(text)) {
			return op_type_list[i].builder(text);
		}
	}

	return nullptr;
}
