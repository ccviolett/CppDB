#include "Table.hpp"

using namespace std;

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