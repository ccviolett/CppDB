#include "OperateFactory.hpp"

using namespace std;

OperateFactory::OperateFactory() {
	loadOperateType();
}

bool OperateFactory::loadOperateType() {
	appendOperateType(OperateInsert::getType());
	// appendOperateType(OperateCreate::getType());
	return true;
}

bool OperateFactory::appendOperateType(OperateType type) {
	op_type_list.push_back(type);
	return true;
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
