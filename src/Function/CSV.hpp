#ifndef _CSV_H
#define _CSV_H

#include <iostream>
#include <fstream>
#include <vector>
#include "String.hpp"

class CSV {
public:
	String name;
	std::vector<std::vector<String> > text;

	CSV();
	CSV(std::vector<std::vector<String> >);

	void show();

	bool readFromFile(std::ifstream &fin);
	bool readByFileName(String file_name);
	bool readByTableName(String table_name);
	bool writeToFile(std::ofstream &fout);
	bool writeByFileName(String file_name);
	bool writeByTableName(String table_name);

	static CSV getCSVByFileName(String file_name);

	std::vector<String>& operator [] (int x) { return text[x]; }
	std::vector<std::vector<String> > getData() { return text; }
	int getRowNum() { return text.size(); }
};

#endif
