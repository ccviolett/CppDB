#include "OperateInsert.hpp"

using namespace std;

bool OperateInsert::checker(String s) {
	String type = "INSERT";
	return s.align(type) == type;
}

Operate* OperateInsert::builder(String s) {
	return new OperateInsert(s);
}

OperateInsert::OperateInsert(String s) {
	vector<String> v = s.split(' ');
	table = v[2];
	column = "";
	values = "";
	col_v.clear();
	val_v.clear();

	for (size_t i = 3; i < v.size(); ++i) {
		if (v[i] == "VALUES") { break; } 
		column += v[i];
	}

	if (column.size()) {
		col_v = s.split('(')[1].split(')')[0].split(',');
		val_v = s.split('(')[2].split(')')[0].split(',');
	} else {
		val_v = s.split('(')[1].split(')')[0].split(',');
	}

	for (size_t i = 0; i < col_v.size(); ++i) {
		if (col_v[i][0] == ' ') col_v[i].pop_front();
	}
	for (size_t i = 0; i < val_v.size(); ++i) {
		if (val_v[i][0] == ' ') val_v[i].pop_front();
		val_v[i].pop_front();
		val_v[i].pop_back();
	}
}

bool OperateInsert::execute() {
	return this->execute(SingleTable::getInstance().getTable(this->table));
}

bool OperateInsert::execute(Table &tb) {
	if (col_v.size() && col_v.size() != val_v.size()) return false;
	if (!tb.checkName(this->table)) return false;
	return tb.insert(col_v, val_v);
}

void OperateInsert::show() {
	cerr << table;
	cerr << column;
	cerr << values;

	String tlog = "";
	if (column.size()) {
		tlog += "{ \n";
		for (size_t i = 0; i < col_v.size(); ++i) {
			tlog += "	" + col_v[i] + ": " + val_v[i] + "\n";
		}
		tlog += "} \n";
	} else {
		tlog += "[ ";
		for (auto t: val_v) {
			tlog += t + " ";
		}
		tlog += "]";
	}
	cerr << tlog << endl;
}