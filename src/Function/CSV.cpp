#include "CSV.hpp"

using namespace std;

CSV::CSV() = default;

bool CSV::readFromFile(ifstream &fin) {
    LOG(TRACE);
    String s;
    while (s.readLineFromFile(fin)) {
        vector<String> tline = s.split(' ');
        vector<String> tres;
        for (auto t : tline) {
            t = t.staggerFront(t.seekFront('"') + '"')
                    .alignFront(t.seekBack('"'));
            String os = "";
            vector<String> tv = t.split('"');
            for (auto v : tv) {
                if (v == "") os += '"';
                else os += v;
            }
            tres.push_back(os);
        }
        text.push_back(tres);
    }
    return true;
}

bool CSV::readByTableName(const String& table_name) {
    LOG(TRACE) << table_name;
    this->name = table_name;
    return readByFileName(table_name + ".csv");
}

bool CSV::readByFileName(String file_name) {
    LOG(TRACE) << file_name;
    this->name = file_name.splitByChar('.')[0];
    ifstream fin(file_name.getRawString());
    if (!fin.good()) {
        fin.close();
        return false;
    }
    bool res = readFromFile(fin);
    fin.close();
    return res;
}

bool CSV::writeToFile(ofstream &fout) {
    LOG(TRACE);
    for (auto & x : text) {
        size_t tsize = x.size();
        for (size_t i = 0; i < tsize; ++i) {
            String ts = x[i];
            String rs = "";
            vector<String> dq = ts.split('"');
            for (const auto & i : dq) {
                rs += "\"" + i + "\"";
            }
            fout << rs << (i == tsize - 1 ? "\n" : ", ");
        }
    }
    return true;
}

bool CSV::writeByFileName(String file_name) {
    LOG(TRACE) << file_name;
    ofstream fout(file_name.getRawString());
    if (!fout.good()) {
        fout.close();
        return false;
    }
    bool res = writeToFile(fout);
    fout.close();
    return res;
}

CSV CSV::getCSVByFileName(String s) {
    LOG(TRACE) << s;
    CSV csv;
    csv.readByFileName(s);
    return csv;
}

CSV::CSV(vector<vector<String> > t) {
    LOG(TRACE);
    text = t;
}

bool CSV::writeByTableName(String table_name) {
    LOG(TRACE) << table_name;
    return writeByFileName(table_name + ".csv");
}

void CSV::show() {
    LOG(TRACE);
    cerr << "CSV name: " << name << endl;
    for (size_t i = 0; i < text.size(); ++i) {
        for (size_t j = 0; j < text[i].size(); ++j) {
            cerr << text[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
}