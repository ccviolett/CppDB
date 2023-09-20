#include "CSV.h"

CSV::CSV() { }

bool CSV::readFromFile(ifstream &fin) {
	String s;
	while (getline(fin, s)) {
		getline(fin, s);
		vector<String> tline = s.split(',');
		text.push_back(tline);
	}
	return true;
}

bool CSV::readByFileName(String file_name) {
	ifstream fin(file_name);
	bool res = readFromFile(fin);
	fin.close();
	return res;
}

bool CSV::writeToFile(ofstream &fout) {
	for (size_t x = 0; x < text.size(); ++x) {
		int tsize = text[x].size();
		for (size_t i = 0; i < tsize; ++i) {
			fout << text[x][i] 
				<< (i == tsize - 1 ? '\n' : ',');
		}
	}
	return true;
}

bool CSV::writeByFileName(String file_name) {
	ofstream fout(file_name);
	bool res = writeToFile(fout);
	fout.close();
	return res;
}

CSV CSV::getCSVByFileName(String s) {
	CSV csv;
	csv.readByFileName(s);
	return csv;
}

CSV::CSV(vector<vector<String>> t) {
	text = t;
}
