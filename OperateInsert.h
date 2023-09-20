#ifndef _OPERATE_INSERT_H
#define _OPERATE_INSERT_H

#include "String.h"
#include "Operate.h"

class OperateInsert : public Operate {
	private:
		String table;
		String column;
		String values;
		vector<String> col_v;
		vector<String> val_v;

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

#include "OperateInsert.cpp"

#endif
