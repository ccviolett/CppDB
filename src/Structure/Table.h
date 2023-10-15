#ifndef _TABLE_H
#define _TABLE_H

#include <iostream>
#include <vector>
#include "../Function/String.hpp"
#include "../Function/CSV.hpp"

class Field {
public:
    Field() {
        Null = true;
        Default = String::getNullString();
    }
    Field(String th, String tt) {
        this->name = th;
        this->type = tt;
    }

    String name;
    String type;
    bool Null;
    String Key;
    String Default;
    String Extra;
};

class Table {
private:
    std::vector<Field> field;
    std::vector<std::vector<String> > data;
public:

    String name;
    Table();
    Table(String s);
    Table(String s, std::vector<String> th, std::vector<String> tt);

    bool setName(String s);
    bool setByHead(std::vector<String> th, std::vector<String> tt);
    bool setByCSV(CSV csv);
    void show();
    bool checkName(String s);
    bool insert(std::vector<String> column, std::vector<String> values);
    bool sync();

    bool desc();

    bool isNewTable();
};

class SingleTable {
private:
    SingleTable() {
    };
    ~SingleTable() {};
    std::vector<Table> table_list;

public:
    static SingleTable& getInstance() {
        static SingleTable instance;
        return instance;
    };

    // SingleTable(const SingleTable&);
    // SingleTable& operate=(const SingleTable&);

public:
    Table& initTable(String s);
    Table& getTable(const String& s);
    bool insertTable(Table tb);
    bool checkTable(const String& table_name);
};

#endif
