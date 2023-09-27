#ifndef _TABLE_H
#define _TABLE_H

#include <iostream>
#include <vector>
#include "Function/String.hpp"
#include "Function/CSV.hpp"

class Table {
	private:
		String name;
		std::vector<String> head;
		std::vector<String> type;
		std::vector<std::vector<String> > data;
	public:

		Table();
		Table(String s);
		Table(String s, std::vector<String> th, std::vector<String> tt);
		Table(CSV csv);

		void show();
		bool checkName(String s);
		bool init();
		bool insert(std::vector<String> column, std::vector<String> values);
};

class SingleTable {
	private:
		SingleTable() {
		};
		~SingleTable() {};
		std::vector<Table> table_list;

	public:
		static SingleTable& getInstance() {
			static SingleTable instance;
			return instance;
		};

		// SingleTable(const SingleTable&);
		// SingleTable& operate=(const SingleTable&);
		
	public:
		Table& initTable(String s);
		bool insertTable(Table tb);
		Table& getTable(String s);
};

#endif
