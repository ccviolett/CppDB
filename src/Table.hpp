#ifndef _TABLE_H
#define _TABLE_H

#include <iostream>
#include <vector>
#include "Function/String.hpp"
#include "Function/CSV.hpp"

class Table {
	private:
		std::vector<String> head;
		std::vector<String> type;
		std::vector<std::vector<String> > data;
	public:

		String name;
		Table();
		Table(String s);
		Table(String s, std::vector<String> th, std::vector<String> tt);

		bool init();
		bool setName(String s);
		bool setByHead(std::vector<String> th, std::vector<String> tt);
		bool setByCSV(CSV csv);
		void show();
		bool checkName(String s);
		bool insert(std::vector<String> column, std::vector<String> values);
		bool sync();

		bool isNewTable();
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
		Table& getTable(String s);
};

#endif
