#ifndef _OPERATEINSERT_H
#define _OPERATEINSERT_H

#include "Operate.hpp"

class OperateInsert : public Operate {
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

    static bool checker(String s);
    static Operate* builder(String s);

    OperateInsert() {}
    OperateInsert(String s);
    virtual bool execute();
    virtual void show();

    bool execute(Table &tb);
};

#endif