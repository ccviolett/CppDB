#include "OperateFactory.hpp"

using namespace std;

OperateFactory::OperateFactory() {
	loadOperateType();
}

bool OperateFactory::loadOperateType() {
	appendOperateType(OperateInsert::getChecker());
	// appendOperateType(OperateCreate::getChecker());
	return true;
}

bool OperateFactory::appendOperateType(OperateChecker checker) {
	op_type_list.push_back(checker);
	return true;
}

bool OperateFactory::checkOperateType(String s, String type) {
	return s.substr(0, type.size()) == type;
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
		OperateChecker checker = op_type_list[i];
		if (checkOperateType(text, checker.type)) {
			return checker.bind(text);
		}
	}

	return nullptr;
}
