#ifndef _OPERATE_SELECT_H
#define _OPERATE_SELECT_H

#include "Operate.h"

class OperateSelect : public Operate {
	public:
		OperateSelect(String s) {
		}
		static bool checkType(String s, String type = "SELECT") {
			return Operate::checkType(s, type);
		}
};

#endif
