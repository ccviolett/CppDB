#ifndef _OPERATEFACTORY_H
#define _OPERATEFACTORY_H

#include "Operate.hpp"

class OperateFactory {
	private:
		std::vector<OperateType> op_type_list;

	public:
		OperateFactory();
		bool loadOperateType();
		bool appendOperateType(OperateType type);
		bool appendOperateType(std::vector<OperateType> type_list);
		bool checkOperateType(String s, String type);
		Operate* getOperateFromCommand();
		Operate* getOperateFromFile(std::ifstream &fin);
		Operate* getOperateByFileName(String file_name);
		Operate* getOperateFromString(String text);
};

#endif