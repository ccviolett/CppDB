#ifndef _TABLE_H
#define _TABLE_H

#include "String.h"
#include "CSV.h"

class Table {
public:
	String name;
	vector<String> head;
	vector<String> type;
	vector<vector<String>> data;

	Table();
	Table(String s);
	Table(String s, vector<String> th, vector<String> tt);

	void show();
};

#include "Table.cpp"

#endif
