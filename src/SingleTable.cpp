#include "Table.hpp"

using namespace std;

Table& SingleTable::initTable(String s) {
	CSV csv;
	Table tb(s);
	if (csv.readByTableName(s)) {
        cerr << "Get CSV correct, set it." << endl;
        tb.setByCSV(csv);
	}
    insertTable(tb);
	return table_list.back();
}

Table& SingleTable::getTable(String s) {
    for (size_t i = 0; i < table_list.size(); ++i) {
        if (table_list[i].checkName(s)) {
            return table_list[i];
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