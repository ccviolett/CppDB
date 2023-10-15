#ifndef _OPERATE_H
#define _OPERATE_H

#include "../Function/Logger.hpp"
#include "../Function/String.hpp"
#include "../Structure/Database.h"
#include "../Structure/Table.h"
#include <vector>
#include <iostream>
#include <fstream>

class OperateBase {
public:
    int id, ver;

    virtual ~OperateBase() {}

    virtual bool execute() = 0;
    virtual void show() = 0;

    static bool checker(String s, String type) {
        return s.cleanFrontSpace().alignFront(type).toUpperCase() == type.toUpperCase();
    }

};

class OperateType {
public:
    std::function<bool(String s)> checker;
    std::function<OperateBase*(String s)> builder;
};

class OperateFactory {
private:
    std::vector<OperateType> op_type_list;
    OperateFactory();

public:
    static OperateFactory& getInstance() {
        static OperateFactory instance;
        return instance;
    }
    bool loadOperateType();
    bool appendOperateType(OperateType type);
    bool appendOperateType(std::vector<OperateType> type_list);
    OperateBase* getOperateFromCommand();
    OperateBase* getOperateFromFile(std::ifstream &fin);
    OperateBase* getOperateByFileName(String file_name);
    OperateBase* getOperateFromString(String text);
};

#endif
