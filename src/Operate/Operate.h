#ifndef CPPDB_OPERATE_H
#define CPPDB_OPERATE_H

#include "OperateBase.hpp"
#include "OperateInsert.h"
#include "OperateCreate.h"
#include "OperateUpdate.h"
#include "OperateSelect.h"
#include "OperateDelete.h"
#include "OperateMess.h"

class Operate {
private:

public:
    static OperateFactory& Factory() {
        return OperateFactory::getInstance();
    }
};

#endif