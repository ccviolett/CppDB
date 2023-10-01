#include "Operate.hpp"

using namespace std;

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
	if (OperateInsert::checkType(text)) {
    return new OperateInsert(text);
	}
  /*
	if (OperateUpdate::checkType(text)) {
		return new OperateUpdate(text);
	}
	if (OperateDelete::checkType(text)) {
		return new OperateDelete(text);
	}
	if (OperateSelect::checkType(text)) {
    return new OperateSelect(text);
	}
	if (OperateCreate::checkType(text)) {
    return new OperateCreate(text);
	}
  */
	return nullptr;
}
