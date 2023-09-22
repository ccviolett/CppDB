#ifndef _TABLE_H
#define _TABLE_H

#include <iostream>
#include <vector>
#include "String.hpp"
#include "CSV.hpp"

class Table {
public:
	String name;
	std::vector<String> head;
	std::vector<String> type;
	std::vector<std::vector<String> > data;

	Table();
	Table(String s);
	Table(String s, std::vector<String> th, std::vector<String> tt);

	void show();
};

#endif
