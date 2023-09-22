#ifndef _OPERATE_H
#define _OPERATE_H

#include "String.hpp"
#include "Database.hpp"

class Operate {
	public:
		int id, ver;

		static bool checkType(String s, String type);
		virtual bool excute(Database &db);
		virtual void show();
		static Operate* getOperateFromCommand();
		static Operate* getOperateFromString(String text);
};


#include "OperateInsert.hpp"
#include "OperateUpdate.hpp"
#include "OperateDelete.hpp"
#include "OperateSelect.hpp"
#include "OperateCreate.hpp"

#endif
