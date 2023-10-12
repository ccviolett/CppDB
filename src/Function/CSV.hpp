#ifndef _CSV_H
#define _CSV_H

#include <iostream>
#include <fstream>
#include <vector>
#include "String.hpp"
#include "Logger.hpp"

class CSV {
public:
    String name;
    std::vector<std::vector<String> > text;

    CSV();
    CSV(std::vector<std::vector<String> >);

    void show();

    bool readFromFile(std::ifstream &fin);
    bool readByFileName(String file_name);
    bool readByTableName(const String& table_name);
    bool writeToFile(std::ofstream &fout);
    bool writeByFileName(String file_name);
    bool writeByTableName(String table_name);

    static CSV getCSVByFileName(String file_name);

    std::vector<String>& operator [] (int x) { return text[x]; }
    int getRowNum() const { return text.size(); }
};

#endif
