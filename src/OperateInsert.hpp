#ifndef _OPERATE_INSERT_H
#define _OPERATE_INSERT_H

#include "String.hpp"
#include "Operate.hpp"
#include <vector>

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

#endif
