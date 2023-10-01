#ifndef _OPERATEFACTORY_H
#define _OPERATEFACTORY_H

#include "Operate.hpp"

class OperateFactory {
	private:
		std::vector<OperateChecker> op_type_list;

	public:
		OperateFactory();
		bool loadOperateType();
		bool appendOperateType(OperateChecker checker);
		bool checkOperateType(String s, String type);
		Operate* getOperateFromCommand();
		Operate* getOperateFromString(String text);
};

#endif