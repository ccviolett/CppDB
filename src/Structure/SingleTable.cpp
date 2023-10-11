#include "Table.hpp"

using namespace std;

bool SingleTable::checkTable(const String& table_name) {
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
	CSV csv;
	Table tb(s);
	if (csv.readByTableName(s)) {
        cerr << "Get CSV correct, set it." << endl;
        tb.setByCSV(csv);
	}
    insertTable(tb);
	return table_list.back();
}

Table& SingleTable::getTable(const String& s) {
    for (auto & t : table_list) {
        if (t.checkName(s)) {
            return t;
        }
    }
    cerr << "Get Table Failed, init it." << endl;
    return initTable(s);
}

bool SingleTable::insertTable(Table tb) {
    tb.sync();
    table_list.push_back(tb);
    return true;
}