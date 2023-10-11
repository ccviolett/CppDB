#include "OperateCreate.hpp"

#include <utility>

using namespace std;

vector<OperateType> OperateCreate::getType() {
  vector<OperateType> type_list;
  type_list.push_back(OperateCreateTable::getType());
  // type_list.push_back(OperateCreateDatabase::getType());
  return type_list;
}

bool OperateCreateTable::checker(String s) {
	String type = "CREATE TABLE";
  return s.alignFront(type) == type;
}

Operate* OperateCreateTable::builder(String s) {
  return new OperateCreateTable(std::move(s));
}

OperateCreateTable::OperateCreateTable() {
    name = "";
    head.clear();
    type.clear();
}

OperateCreateTable::OperateCreateTable(String s) {
    s = s.split(';')[0].cleanFrontSpace().cleanBackSpace();
    s = s.staggerFront("CREATE TABLE").cleanFrontSpace();
    name = s.split('(')[0].cleanBackSpace();
    s = s.staggerFront(name).cleanFrontSpace();
    s = s.staggerFront("(").staggerBack(")").cleanFrontSpace().cleanBackSpace();

    for (int i = 0; i < 7; ++i) {
        String ts = s.seekOrFront(',', '(').cleanFrontSpace().cleanBackSpace();
        s = s.staggerFront(s.seekOrFront(',', '('));
        cerr << "S: " << s << endl;
        String th = ts.split(' ')[0];
        String tt = ts.split(' ')[1];
        String tsize = "";
        if (tt == "VARCHAR") {
            tsize = s.split(')')[0].split('(')[1];
            s = s.staggerFront(s.seekFront(')'));
            s = s.staggerFront(s.seekFront(','));
        }
        if (tt == "DOUBLE") {
            tsize = s.split(')')[0].split('(')[1];
            s = s.staggerFront(s.seekFront(')'));
            s = s.staggerFront(s.seekFront(','));
        }
        cerr << th << " " << tt << " " << tsize << endl;
        head.push_back(th);
        if (tsize == "") type.push_back(tt);
        else type.push_back(tt + "(" + tsize + ")");

        s = s.staggerFront(", ").cleanFrontSpace().cleanBackSpace();
        if (s == "") break;
    }
}

bool OperateCreateTable::execute() {
    SingleTable::getInstance().insertTable(Table(name, head, type));
    return true;
}

void OperateCreateTable::show() {
    cerr << "Name: " << name << endl;
    Function::show(head);
    cerr << endl;
    Function::show(type);
    cerr << endl;
}