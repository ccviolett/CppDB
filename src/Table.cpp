#include "Table.hpp"

using namespace std;

Table::Table() { 
	name = "";
	head.clear();
	type.clear();
}

Table::Table(String s) { 
	name = s; 
}

Table::Table(String s, 
	vector<String> th, 
	vector<String> tt) {
	Table();
	name = s.toUpperCase(); 
	for (size_t i = 0; i < th.size(); ++i) {
		head.push_back(th[i].toUpperCase());
	}
	for (size_t i = 0; i < tt.size(); ++i) {
		type.push_back(tt[i].toUpperCase());
	}
}

void Table::show() {
	cerr << "Table name: " << name << endl;
	String tlog = "| ";
	for (size_t i = 0; i < head.size(); ++i) {
		tlog += head[i] + "(" + type[i] + ") | ";
	}
	cerr << tlog << endl;
	for (size_t i = 0; i < head.size(); ++i) {
		cerr << "----------------";
	}
	cerr << endl;
	for (size_t i = 0; i < data.size(); ++i) {
		tlog = "| ";
		for (size_t j = 0; j < data[i].size(); ++j) {
			tlog += data[i][j] + " | ";
		}
		cerr << tlog << endl;
	}
	cerr << endl;
}

bool Table::checkName(String s) {
	return s == name;
}

bool Table::insert(vector<String> column, vector<String> values) {
	cerr << "==== Table Insert ====" << endl;
	cerr << "COLUMN: ";
	for (size_t i = 0; i < column.size(); ++i) {
		cerr << column[i] << " ";
	}
	cerr << endl;

	vector<String> new_data;
	if (!column.size()) {
		new_data = values;
		for (size_t i = values.size(); i < head.size(); ++i) {
			new_data.push_back("");
		}
	} else {
		if (column.size() != values.size()) return false;
		for (size_t i = 0; i < head.size(); ++i) {
			bool ok = false;
			for (size_t j = 0; j < column.size(); ++j) {
				if (column[j].toUpperCase() == head[i].toUpperCase()) {
					ok = true;
					new_data.push_back(values[j]);
					break;
				}
			}
			cerr << head[i] << " - " << ok << endl;
			if (!ok) new_data.push_back("");
		}
	}
	data.push_back(new_data);
	return true;
}

bool SingleTable::insertTable(Table tb) {
	table_list.push_back(tb);
	return true;
}

Table& SingleTable::getTable(String s) {
	for (size_t i = 0; i < table_list.size(); ++i) {
		if (table_list[i].checkName(s)) {
			return table_list[i];
		}
	}
}