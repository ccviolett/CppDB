#include "OperateCreate.hpp"

#include <utility>

using namespace std;

vector<OperateType> OperateCreate::getType() {
    LOG(TRACE);
    vector<OperateType> type_list;
    type_list.push_back(OperateCreateTable::getType());
    // type_list.push_back(OperateCreateDatabase::getType());
    return type_list;
}

OperateCreateTable::OperateCreateTable() {
    LOG(TRACE);
    name = "";
    head.clear();
    type.clear();
}

OperateCreateTable::OperateCreateTable(String s) {
    LOG(TRACE);
    s = s.split(';')[0].cleanFrontSpace().cleanBackSpace();
    s = s.staggerFront("CREATE TABLE").cleanFrontSpace();
    name = s.split('(')[0].cleanBackSpace();
    s = s.staggerFront(name).cleanFrontSpace();
    s = s.staggerFront("(").staggerBack(")").cleanFrontSpace().cleanBackSpace();

    for (int i = 0; i < 7; ++i) {
        String ts = s.seekOrFront(',', '(').cleanFrontSpace().cleanBackSpace();
        s = s.staggerFront(s.seekOrFront(',', '('));
        String th = ts.split(' ')[0];
        String tt = ts.split(' ')[1].toLowerCase();
        String tsize = "";
        if (tt == "varchar") {
            tsize = s.split(')')[0].split('(')[1];
            s = s.staggerFront(s.seekFront(')'));
            s = s.staggerFront(s.seekFront(','));
        }
        if (tt == "double") {
            tsize = s.split(')')[0].split('(')[1];
            s = s.staggerFront(s.seekFront(')'));
            s = s.staggerFront(s.seekFront(','));
        }
        head.push_back(th);
        if (tsize == "") type.push_back(tt);
        else type.push_back(tt + "(" + tsize + ")");

        s = s.staggerFront(", ").cleanFrontSpace().cleanBackSpace();
        if (s == "") break;
    }
}

bool OperateCreateTable::execute() {
    LOG(TRACE);
    SingleTable::getInstance().insertTable(Table(name, head, type));
    return true;
}

void OperateCreateTable::show() {
    LOG(TRACE);
    cerr << "Name: " << name << endl;
    Function::show(head);
    cerr << endl;
    Function::show(type);
    cerr << endl;
}