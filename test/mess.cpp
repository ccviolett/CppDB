//
// Created by 罗潇阳 on 2023/10/11.
//

#include "../src/CppDB.h"

using namespace std;

int main() {
    Operate::Factory().appendOperateType(OperateMessDesc::getType());
    Operate::Factory().getOperateByFileName("test_operate_create.sql")->execute();
    Operate::Factory().getOperateFromString("desc student;")->execute();

    /*
    OperateFactory of;
    of.appendOperateType(OperateMessDesc::getType());
    of.getOperateByFileName("test_operate_create.sql")->execute();
    OperateBase* op = of.getOperateFromString("desc student;");
    op->execute();
     */

    return 0;
}