#ifndef _OPERATE_UPDATE_H
#define _OPERATE_UPDATE_H

#include "Operate.h"

class OperateUpdate : public Operate {
	public:
		OperateUpdate(String s) {
		}
		static bool checkType(String s, String type = "UPDATE") {
			return Operate::checkType(s, type);
		}
};

#endif
