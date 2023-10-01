#ifndef _OPERATEFACTORY_H
#define _OPERATEFACTORY_H

#include "Operate.hpp"

class OperateFactory {
	private:
		std::vector<OperateType> op_type_list;

	public:
		OperateFactory();
		bool loadOperateType();
		bool appendOperateType(OperateType checker);
		bool checkOperateType(String s, String type);
		Operate* getOperateFromCommand();
		Operate* getOperateFromString(String text);
};

#endif