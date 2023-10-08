#ifndef _OPERATE_H
#define _OPERATE_H

#include "../Function/String.hpp"
#include "../Structure/Database.hpp"
#include "../Structure/Table.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class Operate {
	public:
		int id, ver;

		virtual ~Operate() {}
		virtual bool execute() = 0;
		virtual void show() = 0;
};

class OperateType {
	public:
		std::function<bool(String s)> checker;
		std::function<Operate*(String s)> builder;
};

#include "OperateInsert.hpp"
#include "OperateCreate.hpp"

class OperateUpdate : public Operate {
	public:
		OperateUpdate() {}
		OperateUpdate(String s) {
		}
		static String getType() { return "UPDATE"; }
};

class OperateSelect : public Operate {
	public:
		OperateSelect() {
		}
		OperateSelect(String s) {
		}
		static String getType() { return "SELECT"; }
};

class OperateDelete : public Operate {

	public:
		OperateDelete() {
		}
		OperateDelete(String s) {
		}
		static String getType() { return "DELETE"; }
};

#include "OperateFactory.hpp"

#endif
