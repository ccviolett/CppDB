//
// Created by 罗潇阳 on 2023/10/11.
//

#include "OperateMess.hpp"

using namespace std;

vector<OperateType> OperateMess::getType() {
    LOG(TRACE);
    vector<OperateType> v;
    v.push_back(OperateMessDesc::getType());
    return v;
}

OperateMessDesc::OperateMessDesc() {
    LOG(TRACE);

}

OperateMessDesc::OperateMessDesc(String s) {
    LOG(TRACE);
    table_name = s.cleanFrontSpace().staggerFront("DESC")
            .cleanFrontSpace().cleanBackSpace();
}

bool OperateMessDesc::execute() {
    LOG(TRACE);
    if (!SingleTable::getInstance().checkTable(table_name)) {
        return false;
    }
    Table tb = SingleTable::getInstance().getTable(table_name);
    tb.show();
    return true;
}

void OperateMessDesc::show() {
    LOG(TRACE);
    cerr << "Table name: " << table_name << endl;
}