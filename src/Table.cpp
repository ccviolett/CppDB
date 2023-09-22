#include "Table.hpp"

using namespace std;

Table::Table() { }

Table::Table(String s) { name = s; }

Table::Table(String s, 
	vector<String> th, 
	vector<String> tt) {
	name = s; 
	head = th;
	type = tt;
}

void Table::show() {
	cerr << "Table name: " << name;
	String tlog = "| ";
	for (size_t i = 0; i < head.size(); ++i) {
		tlog += head[i] + "(" + type[i] + ") | ";
	}
	cerr << tlog;
	for (size_t i = 0; i < head.size(); ++i) {
		cerr << "------";
	}
	for (size_t i = 0; i < data.size(); ++i) {
		tlog = "| ";
		for (size_t j = 0; j < data[i].size(); ++j) {
			tlog += data[i][j] + " | ";
		}
		cerr << tlog;
	}
}