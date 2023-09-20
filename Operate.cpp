#include "Operate.h"

bool Operate::checkType(String s, String type) {
	return s.substr(0, type.size()) == type;
}

bool Operate::excute(Database &db) { 
	return false; 
}

void Operate::show() { 
}

Operate* Operate::getOperateFromCommand() {
	String text, s;
	do {
		cin >> s;
		text.append(s);
		text.append(" ");
	} while (s.back() != ';');
	return getOperateFromString(text);
};

Operate* Operate::getOperateFromString(String text) {
	text = text.toUpperCase();
	if (OperateInsert::checkType(text)) {
		static OperateInsert opi(text);
		return &opi;
	}
	if (OperateUpdate::checkType(text)) {
		static OperateUpdate opu(text);
		return &opu;
	}
	if (OperateDelete::checkType(text)) {
		static OperateDelete opd(text);
		return &opd;
	}
	if (OperateSelect::checkType(text)) {
		static OperateSelect ops(text);
		return &ops;
	}
	if (OperateCreate::checkType(text)) {
		static OperateCreate opc(text);
		return &opc;
	}
	return nullptr;
}
