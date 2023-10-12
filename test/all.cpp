#include "../src/CppDB.h"
#include <vector>

using namespace std;

bool Test_OperateInsert() {
	Table &tb = SingleTable::getInstance().getTable("BOOK");

	if (tb.isNewTable()) {
		cerr << "New Table set" << endl;
		std::vector<String> thead = {"name", "author", "pages", "price"};
		std::vector<String> ttype = {"string", "string", "int", "double"};
		tb.setName("BOOK");
		tb.setByHead(thead, ttype);
		tb.show();
	}

	/* 
	 * CREATE TABLE DEFAULT (
	 *	name string,
	 *	author string,
	 *	pages int,
	 *	price double,
	 * );
	 */

	String s = R"(insert into Book (name, author, pages, price) values ("The Da Vinci Code", "Dan Brown", "454", "16.96"))";

	OperateFactory operateFactory;
	Operate *op = operateFactory.getOperateFromString(s);
	op->show();
	op->execute();

	SingleTable::getInstance().getTable("BOOK").show();

	return true;
}

bool Test_String_align() {
	String s = "Hello";
	cerr << s.alignFront("To") << endl;
}

bool Test_String_stagger() {
	String s = "Hello World";
	cerr << s.staggerFront("Hello W") << endl;
}

bool Test_String_split() {
	String s = "hello,I,am,Sam";
	std::vector<String> v = s.split(',');
	for (const auto & i : v) {
		cerr << "[" << i << "]" << std::endl;
	}
	return true;
}

bool Test_String_split_1() {
	String s = "(hello,I,am,Sam)";
	std::vector<String> v = s.split('(')[1].split(')')[0].split(',');
    Function::show(v);
	return true;
}

bool Test_String_split_2() {
	String s = R"(insert into Book (name, author, pages, price) values ("The Da Vinci Code", "Dan Brown", "454", "16.96"))";
	std::vector<String> v = s.split('(')[2].split(')')[0].split(',');
    Function::show(v);
	return true;
}

bool Test_Operate() {
	OperateFactory operateFactory;
	Operate *op = operateFactory.getOperateFromCommand();
	op->show();
	return true;
}

bool Test_CSV() {

	std::vector<std::vector<String>> t;

	std::vector<String> l;
	l.emplace_back("Name");
	l.emplace_back("Age");
	l.emplace_back("Sex");

	t.emplace_back(l);

	std::vector<String> l1;
	l1.emplace_back("Sam");
	l1.emplace_back("19");
	l1.emplace_back("Male");

	t.emplace_back(l1);

	std::vector<String> l2;
	l2.emplace_back("Alice");
	l2.emplace_back("16");
	l2.emplace_back("Female");

	t.emplace_back(l2);

	CSV csv(t);

	csv.writeByFileName("test.csv");

	CSV test = CSV::getCSVByFileName("test.csv");

    test.show();

	return true;
}

bool Test_OperateCreateTable() {
    OperateFactory operateFactory;
    Operate* op = operateFactory.getOperateByFileName("test_operate_create.sql");
    op->show();

    op->execute();

    return true;
}

bool Test_CSV_1() {
    std::vector<std::vector<String>> t;

    std::vector<String> l;
    l.emplace_back("Nam,e");
    l.emplace_back("A,ge");
    l.emplace_back("Se,x");

    t.emplace_back(l);

    std::vector<String> l1;
    l1.emplace_back(R"(S"a,m)");
    l1.emplace_back("19");
    l1.emplace_back("Male");

    t.emplace_back(l1);

    std::vector<String> l2;
    l2.emplace_back("Alice");
    l2.emplace_back("16");
    l2.emplace_back("Female");

    t.emplace_back(l2);

    CSV csv(t);

    csv.writeByFileName("test_1.csv");

    CSV test = CSV::getCSVByFileName("test_1.csv");

    test.show();
    return true;
}

int main() {
    Test_OperateCreateTable();
	return 0;
}
