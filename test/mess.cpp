//
// Created by 罗潇阳 on 2023/10/11.
//

#include "../src/CppDB.h"

using namespace std;

int main() {
    OperateFactory of;
    of.appendOperateType(OperateMessDesc::getType());
    // of.getOperateByFileName("test_operate_create.sql")->execute();
    Operate* op = of.getOperateFromString("desc student");
    op->show();
    op->execute();
    return 0;
}