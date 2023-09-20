#include "Test.h"

int main() {
	// Test_CSV();
	Test_OperateInsert();

	return 0;
}

bool Test_OperateInsert() {
	vector<String> thead = {"name", "author", "pages", "price"};
	vector<String> ttype = {"string", "string", "int", "double"};
	Table table("default", thead, ttype);
	/* 
	 * CREATE TABLE DEFAULT (
	 *	name string,
	 *	author string,
	 *	pages int,
	 *	price double,
	 * );
	 */

	String s = "insert into Book (name, author, pages, price) values (\"The Da Vinci Code\", \"Dan Brown\", \"454\", \"16.96\")";
	Operate *op = Operate::getOperateFromString(s);
	op->show();
	return true;
}

bool Test_String_split() {
	String s = "hello,I,am,Sam";
	vector<String> v = s.split(',');
	for (size_t i = 0; i < v.size(); ++i) {
		cerr << "[" << v[i] << "]" << endl;
	}
	return true;
}

bool Test_String_split_1() {
	String s = "(hello,I,am,Sam)";
	vector<String> v = s.split('(')[1].split(')')[0].split(',');
	for (auto t: v) {
		cerr << t << endl;
	}
	return true;
}

bool Test_String_split_2() {
	String s = "insert into Book (name, author, pages, price) values (\"The Da Vinci Code\", \"Dan Brown\", \"454\", \"16.96\")";
	vector<String> v = s.split('(')[2].split(')')[0].split(',');
	for (auto t: v) {
		cerr << t << endl;
	}
	cerr << s << endl;
	return true;
}

bool Test_Operate() {
	Operate *op = Operate::getOperateFromCommand();
	op->show();
	return true;
}

bool Test_CSV() {

	vector<vector<String>> t;

	vector<String> l;
	l.push_back("Name");
	l.push_back("Age");
	l.push_back("Sex");

	t.push_back(l);

	vector<String> l1;
	l1.push_back("Sam");
	l1.push_back("19");
	l1.push_back("Male");

	t.push_back(l1);

	vector<String> l2;
	l2.push_back("Alice");
	l2.push_back("16");
	l2.push_back("Female");

	t.push_back(l2);

	CSV csv(t);

	csv.writeByFileName("test.csv");

	CSV test = CSV::getCSVByFileName("test.csv");

	return true;
}
