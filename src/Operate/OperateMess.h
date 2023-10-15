//
// Created by 罗潇阳 on 2023/10/11.
//

#ifndef CPPDB_OPERATEMESS_H
#define CPPDB_OPERATEMESS_H

#include <vector>
#include "OperateBase.hpp"
#include "../Structure/Table.h"
#include "../Function/Logger.hpp"

class OperateMess : public OperateBase {
public:
    static std::vector<OperateType> getType();
};

class OperateMessDesc : public OperateMess {
private:
    String table_name;
public:
    static OperateType getType() {
        return (OperateType) { checker, builder };
    }

    static bool checker(String s) {
        return OperateBase::checker(s, "DESC");
    }

    static OperateBase* builder(String s) {
        return new OperateMessDesc(std::move(s));
    }

public:
    OperateMessDesc();
    OperateMessDesc(String s);

    virtual bool execute();
    virtual void show();

};


#endif //CPPDB_OPERATEMESS_H
