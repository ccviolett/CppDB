#include "Table.hpp"

using namespace std;

Table::Table() {
    LOG(TRACE);
    this->name = "";
    field.clear();
}

Table::Table(String s) {
    LOG(TRACE);
    Table();
    this->setName(std::move(s));
}

Table::Table(String s,
             vector<String> tn,
             vector<String> tt) {
    LOG(TRACE);
    Table();
    this->setName(std::move(s));
    this->setByHead(std::move(tn), std::move(tt));
}

bool Table::setByHead(vector<String> th, vector<String> tt) {
    LOG(TRACE);
    if (th.size() != tt.size()) {
        LOG(WARNING) << "The length of 'name'(" << th.size()
                << ") and the length of 'type'" << tt.size()
                << " is different. The 'name' shall prevail";
    }
    for (size_t i = 0; i < th.size(); ++i) {
        if (th[i].haveUpperCase()) {
            LOG(WARNING) << "The name " << th[i]
                    << " contains uppercase letters. "
                    << "It may cause case sensitivity issues due to the cross-platform";
        }
        this->field.emplace_back(Field(th[i], tt[i].toLowerCase()));
    }
    return true;
}

void Table::show() {
    LOG(TRACE);
    String tlog = "| ";
    for (size_t i = 0; i < field.size(); ++i) {
        tlog += field[i].name + "(" + field[i].type + ") | ";
    }
    cerr << tlog << endl;
    for (size_t i = 0; i < field.size(); ++i) {
        cerr << "----------------";
    }
    cerr << endl;
    for (auto & tl : data) {
        tlog = "| ";
        for (const auto & tv : tl) {
            tlog += tv + " | ";
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

    if (column.empty()) {
        for (auto & f : this->field) {
            column.push_back(f.name);
        }
    }
    if (column.size() != values.size()) {
        LOG(WARNING) << "The length of 'column'(" << column.size()
                     << ") and the length of 'values'" << values.size()
                     << " is different. The 'column' shall prevail";
    }

    vector<String> new_data;

    for (size_t i = 0; i < field.size(); ++i) {
        bool ok = false;
        for (size_t j = 0; j < column.size(); ++j) {
            if (column[j] == field[i].name) {
                ok = true;
                new_data.push_back(values[j]);
                break;
            }
        }
        if (!ok) {
            new_data.emplace_back(field[i].Default);
        }
    }

    data.push_back(new_data);
    return sync();
}

bool Table::sync() {
    LOG(TRACE);
    vector<vector<String> > text;

    vector<String> name, type;
    for (auto t : field) {
        name.emplace_back(t.name);
        type.emplace_back(t.type);
    }

    text.emplace_back(name);
    text.emplace_back(type);
    for (auto tl : data) {
        text.push_back(tl);
    }
    return CSV(text).writeByTableName(this->name);
}

bool Table::isNewTable() {
    LOG(TRACE);
    return this->field.size() == 0;
}

bool Table::setByCSV(CSV csv) {
    LOG(TRACE);
    csv.show();
    if (csv.name.size()) this->name = csv.name;
    setByHead(csv[0], csv[1]);
    for (int i = 2; i < csv.getRowNum(); ++i) {
        data.push_back(csv[i]);
    }
    return init();
}

bool Table::setName(String s) {
    LOG(TRACE);
    if (s.haveUpperCase()) {
        LOG(WARNING) << "The name " << s
                     << " contains uppercase letters. "
                     << "It may cause case sensitivity issues due to the cross-platform";
    }
    this->name = s;
    return true;
}

bool Table::desc() {
    LOG(TRACE);

    return true;
}