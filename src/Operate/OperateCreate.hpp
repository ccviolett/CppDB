#ifndef _OPERATECREATE_H
#define _OPERATECREATE_H

#include "Operate.hpp"
#include "../Function/Function.hpp"
#include "../Table.hpp"

class OperateCreate : public Operate {
	public:
		OperateCreate();

		static std::vector<OperateType> getType();
		
		virtual bool execute() = 0;
		virtual void show() = 0;
};

class OperateCreateTable : public OperateCreate {
    private:
        String name;
        std::vector<String> head;
        std::vector<String> type;

	public:
		static OperateType getType() {
			return (OperateType) { checker, builder };
		}

		static bool checker(String s);
		static Operate* builder(String s);

		OperateCreateTable();
		OperateCreateTable(String s);

		virtual bool execute();
		virtual void show();
};

class OperateCreateDatabase : public OperateCreate {

};

#endif