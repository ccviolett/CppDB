#ifndef _OPERATEINSERT_H
#define _OPERATEINSERT_H

#include "Operate.hpp"

class OperateInsert : public Operate {
	private:
		String table;
		String column;
		String values;
		std::vector<String> col_v;
		std::vector<String> val_v;

	public:
		static OperateChecker getChecker() {
			return (OperateChecker) { "INSERT INTO", buildFromString };
		}

		static String getType() { return "INSERT INTO"; }
		static Operate* buildFromString(String s);

		OperateInsert() {}
		OperateInsert(String s);
		virtual bool execute();
		virtual void show();

		bool execute(Table &tb);
};

#endif