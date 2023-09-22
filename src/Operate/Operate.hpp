#ifndef _OPERATE_H
#define _OPERATE_H

#include "../Function/String.hpp"
#include "../Database.hpp"
#include <vector>

class Operate {
	public:
		int id, ver;

		static bool checkType(String s, String type);
		virtual bool excute(Database &db);
		virtual void show();
		static Operate* getOperateFromCommand();
		static Operate* getOperateFromString(String text);
};

class OperateCreate : public Operate {
	public:
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
		virtual bool excute(Database &db);
		virtual void show();
		friend OperateInsert BuildOperateInsertByString(String s);
};

class OperateUpdate : public Operate {
	public:
		OperateUpdate(String s) {
		}
		static bool checkType(String s, String type = "UPDATE") {
			return Operate::checkType(s, type);
		}
};

class OperateSelect : public Operate {
	public:
		OperateSelect(String s) {
		}
		static bool checkType(String s, String type = "SELECT") {
			return Operate::checkType(s, type);
		}
};

class OperateDelete : public Operate {
	public:
		OperateDelete(String s) {
		}
		static bool checkType(String s, String type = "DELETE") {
			return Operate::checkType(s, type);
		}
};

#endif
