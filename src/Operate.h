#ifndef _OPERATE_H
#define _OPERATE_H

#include "String.h"
#include "Database.h"

class Operate {
	public:
		int id, ver;

		static bool checkType(String s, String type);
		virtual bool excute(Database &db);
		virtual void show();
		static Operate* getOperateFromCommand();
		static Operate* getOperateFromString(String text);
};

#include "OperateInsert.h"
#include "OperateUpdate.h"
#include "OperateDelete.h"
#include "OperateSelect.h"
#include "OperateCreate.h"

#include "Operate.cpp"

#endif
