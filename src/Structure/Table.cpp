#include "Table.hpp"

using namespace std;

Table::Table() {
    LOG(TRACE);
    this->name = "";
    head.clear();
    type.clear();
}

Table::Table(String s) {
    LOG(TRACE);
    Table();
    this->setName(s);
}

Table::Table(String s,
             vector<String> th,
             vector<String> tt) {
    LOG(TRACE);
    Table();
    this->setName(s);
    this->setByHead(th, tt);
}

bool Table::setByHead(vector<String> th, vector<String> tt) {
    LOG(TRACE);
    this->head = th;
    this->type = tt;
    return init();
}

bool Table::init() {
    LOG(TRACE);
    for (size_t i = 0; i < head.size(); ++i) {
        head[i] = head[i].toUpperCase();
    }
    for (size_t i = 0; i < type.size(); ++i) {
        type[i] = type[i].toUpperCase();
    }
    return true;
}

void Table::show() {
    LOG(TRACE);
    cerr << "Table name: " << name << endl;
    String tlog = "| ";
    for (size_t i = 0; i < head.size(); ++i) {
        tlog += head[i] + "(" + type[i] + ") | ";
    }
    cerr << tlog << endl;
    for (size_t i = 0; i < head.size(); ++i) {
        cerr << "----------------";
    }
    cerr << endl;
    for (size_t i = 0; i < data.size(); ++i) {
        tlog = "| ";
        for (size_t j = 0; j < data[i].size(); ++j) {
            tlog += data[i][j] + " | ";
        }
        cerr << tlog << endl;
    }
    cerr << endl;
}

bool Table::checkName(String s) {
    LOG(TRACE);
    return s == name;
}

bool Table::insert(vector<String> column, vector<String> values) {
    LOG(TRACE);
    vector<String> new_data;
    if (!column.size()) {
        new_data = values;
        for (size_t i = values.size(); i < head.size(); ++i) {
            new_data.push_back("");
        }
    } else {
        if (column.size() != values.size()) return false;
        for (size_t i = 0; i < head.size(); ++i) {
            bool ok = false;
            for (size_t j = 0; j < column.size(); ++j) {
                if (column[j].toUpperCase() == head[i].toUpperCase()) {
                    ok = true;
                    new_data.push_back(values[j]);
                    break;
                }
            }
            if (!ok) new_data.push_back("");
        }
    }
    data.push_back(new_data);
    return sync();
}

bool Table::sync() {
    LOG(TRACE);
    vector<vector<String> > text;
    text.push_back(this->head);
    text.push_back(this->type);
    for (size_t i = 0; i < this->data.size(); ++i) {
        text.push_back(this->data[i]);
    }
    return CSV(text).writeByTableName(this->name);
}

bool Table::isNewTable() {
    LOG(TRACE);
    return this->head.size() == 0;
}

bool Table::setByCSV(CSV csv) {
    LOG(TRACE);
    csv.show();
    if (csv.name.size()) this->name = csv.name;
    this->head = csv[0];
    this->type = csv[1];
    for (int i = 2; i < csv.getRowNum(); ++i) {
        data.push_back(csv[i]);
    }
    return init();
}

bool Table::setName(String s) {
    LOG(TRACE);
    this->name = s.toUpperCase();
    return true;
}