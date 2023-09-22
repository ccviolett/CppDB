#ifndef _OPERATE_CREATE_H
#define _OPERATE_CREATE_H

#include "Operate.hpp"

class OperateCreate : public Operate {
	public:
		OperateCreate(String s) {
		}

		static bool checkType(String s, String type = "CREATE") {
			return Operate::checkType(s, type);
		}
};

#endif
