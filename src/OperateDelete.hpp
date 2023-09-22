#ifndef _OPERATE_DELETE_H
#define _OPERATE_DELETE_H

#include "Operate.hpp"

class OperateDelete : public Operate {
	public:
		OperateDelete(String s) {
		}
		static bool checkType(String s, String type = "DELETE") {
			return Operate::checkType(s, type);
		}
};

#endif
