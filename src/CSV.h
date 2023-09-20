#ifndef _CSV_H
#define _CSV_H

#include "String.h"

class CSV {
public:
	vector<vector<String>> text;

	CSV();
	CSV(vector<vector<String>>);

	bool readFromFile(ifstream &fin);
	bool readByFileName(String file_name);
	bool writeToFile(ofstream &fout);
	bool writeByFileName(String file_name);

	static CSV getCSVByFileName(String file_name);
};

#include "CSV.cpp"

#endif
