#ifndef _CSV_H
#define _CSV_H

#include <iostream>
#include <fstream>
#include <vector>
#include "String.hpp"

class CSV {
public:
	std::vector<std::vector<String> > text;

	CSV();
	CSV(std::vector<std::vector<String> >);

	bool readFromFile(std::ifstream &fin);
	bool readByFileName(String file_name);
	bool writeToFile(std::ofstream &fout);
	bool writeByFileName(String file_name);

	static CSV getCSVByFileName(String file_name);
};

#endif
