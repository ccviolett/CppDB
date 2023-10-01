#ifndef _OPERATE_H
#define _OPERATE_H

#include "../Function/String.hpp"
#include "../Database.hpp"
#include "../Table.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class Operate {
	public:
		int id, ver;

		virtual ~Operate() {}
		virtual bool execute() = 0;
		virtual void show() = 0;

		static bool checkType(String s, String type);
};

class OperateCreate : public Operate {
	public:
		OperateCreate() {
		}
		OperateCreate(String s) {
		}

		static bool checkType(String s, String type = "CREATE") {
			return Operate::checkType(s, type);
		}
};

class OperateInsert : public Operate {
	private:
		String table;
		String column;
		String values;
		std::vector<String> col_v;
		std::vector<String> val_v;

	public:
		static bool checkType(String s, String type = "INSERT INTO") {
			return Operate::checkType(s, type);
		}

		OperateInsert() {}
		OperateInsert(String s);
		virtual bool execute();
		virtual void show();

		bool execute(Table &tb);
		friend OperateInsert BuildOperateInsertByString(String s);
};

class OperateUpdate : public Operate {
	public:
		OperateUpdate() {}
		OperateUpdate(String s) {
		}
		static bool checkType(String s, String type = "UPDATE") {
			return Operate::checkType(s, type);
		}
};

class OperateSelect : public Operate {
	public:
		OperateSelect() {
		}
		OperateSelect(String s) {
		}
		static bool checkType(String s, String type = "SELECT") {
			return Operate::checkType(s, type);
		}
};

class OperateDelete : public Operate {
	public:
		OperateDelete() {
		}
		OperateDelete(String s) {
		}
		static bool checkType(String s, String type = "DELETE") {
			return Operate::checkType(s, type);
		}
};

class OperateFactory {
	public:
		Operate* getOperateFromCommand();
		Operate* getOperateFromString(String text);
};

#endif
