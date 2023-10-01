#include "OperateCreate.hpp"

using namespace std;

OperateCreate::OperateCreate() {

}

vector<OperateType> OperateCreate::getType() {
  vector<OperateType> type_list;
  type_list.push_back(OperateCreateTable::getType());
  // type_list.push_back(OperateCreateDatabase::getType());
  return type_list;
}

bool OperateCreateTable::checker(String s) {
	String type = "CREATE TABLE";
	return s.substr(0, type.size()) == type;
}

Operate* OperateCreateTable::builder(String s) {
  return new OperateCreateTable(s);
}

OperateCreateTable::OperateCreateTable() {
}

OperateCreateTable::OperateCreateTable(String s) {
}

bool OperateCreateTable::execute() {
  return true;
}

void OperateCreateTable::show() {
}