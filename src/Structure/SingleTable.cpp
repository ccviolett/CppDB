#include "Table.hpp"

using namespace std;

bool SingleTable::checkTable(const String& table_name) {
    LOG(TRACE);
    for (auto & t : table_list) {
        if (t.checkName(table_name)) {
            return true;
        }
    }
    CSV csv;
    if (csv.readByTableName(table_name)) return true;
    return false;
}

Table& SingleTable::initTable(const String s) {
    LOG(TRACE);
    CSV csv;
    Table tb(s);
    if (csv.readByTableName(s)) {
        LOG(TRACE) << "Get CSV by table name " << s << " correct. Set it.";
        tb.setByCSV(csv);
    } else {
        LOG(TRACE) << "Get CSV by table name " << s << " failed. Use default.";
    }
    insertTable(tb);
    return table_list.back();
}

Table& SingleTable::getTable(const String& s) {
    LOG(TRACE);
    for (auto & t : table_list) {
        if (t.checkName(s)) {
            return t;
        }
    }
    LOG(TRACE) << "Get Table by name '" + s + "' failed. Init it.";
    return initTable(s);
}

bool SingleTable::insertTable(Table tb) {
    LOG(TRACE);
    tb.sync();
    table_list.push_back(tb);
    return true;
}