#ifndef CPPDB_OPERATEINSERT_H
#define CPPDB_OPERATEINSERT_H

#include "OperateBase.hpp"

class OperateInsert : public OperateBase {
private:
    String table;
    String column;
    String values;
    std::vector<String> col_v;
    std::vector<String> val_v;

public:
    static OperateType getType() {
        return (OperateType) { checker, builder };
    }

    static bool checker(String s) {
        return OperateBase::checker(s, "insert into");
    }
    static OperateBase* builder(String s) {
        return new OperateInsert(s);
    }

    OperateInsert() {}
    OperateInsert(String s);
    virtual bool execute();
    virtual void show();

    bool execute(Table &tb);
};

#endif