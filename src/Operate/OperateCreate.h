#ifndef CPPDB_OPERATECREATE_H
#define CPPDB_OPERATECREATE_H

#include "OperateBase.hpp"
#include "../Function/Function.hpp"
#include "../Structure/Table.h"

class OperateCreate : public OperateBase {
public:
    static std::vector<OperateType> getType();
};

class OperateCreateTable : public OperateCreate {
private:
    String name;
    std::vector<String> head;
    std::vector<String> type;

public:
    OperateCreateTable();
    OperateCreateTable(String s);
    static bool checker(String s) {
        return OperateBase::checker(std::move(s), "create table");
    }
    static OperateBase* builder(String s) {
        return new OperateCreateTable(std::move(s));
    }

    virtual bool execute();
    virtual void show();
};

class OperateCreateDatabase : public OperateCreate {

public:
    OperateCreateDatabase();
    OperateCreateDatabase(String s);

    static bool loadOperate() {
        OperateFactory::getInstance().appendOperateType(getType());
        return true;
    }
    static OperateType getType() {
        return (OperateType) { checker, builder };
    }
    static bool checker(String s) {
        return OperateBase::checker(std::move(s), "create database");
    }
    static OperateBase* builder(String s) {
        return new OperateCreateDatabase(std::move(s));
    }
    bool execute();
    void show();
};

#endif