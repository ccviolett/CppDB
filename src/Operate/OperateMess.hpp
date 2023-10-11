//
// Created by 罗潇阳 on 2023/10/11.
//

#ifndef CPPDB_OPERATEMESS_HPP
#define CPPDB_OPERATEMESS_HPP

#include <vector>
#include "Operate.hpp"
#include "../Structure/Table.hpp"

class OperateMess : public Operate {
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
        return s.cleanFrontSpace().toUpperCase().alignFront("DESC") == "DESC";
    }

    static Operate* builder(String s) {
        return new OperateMessDesc(std::move(s));
    }

public:
    OperateMessDesc();
    OperateMessDesc(String s);

    virtual bool execute();
    virtual void show();

};


#endif //CPPDB_OPERATEMESS_HPP
