#include "Table.h"

Table::Table() { }

Table::Table(String s) { name = s; }

Table::Table(String s, vector<String> th, vector<String> tt) {
	name = s; 
	head = th;
	type = tt;
}

void Table::show() {
	cerr << "Table name: " << name << endl;
	cerr << "| ";
	for (size_t i = 0; i < head.size(); ++i) {
		cerr << head[i] << "(" << type[i] << ") | ";
	}
	cerr << endl;
	for (size_t i = 0; i < head.size(); ++i) {
		cerr << "------";
	}
	cerr << endl;
	for (size_t i = 0; i < data.size(); ++i) {
		cerr << "| ";
		for (size_t j = 0; j < data[i].size(); ++j) {
			cerr << data[i][j] << " | ";
		}
		cerr << endl;
	}
}
