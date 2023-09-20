#include "String.h"
using namespace std;

String::String() { 
	split_char = 0;
	split_text.clear();
}

String::String(char c) {
	text = string(1, c);
	String();
}

String::String(const char *s) {
	text = s;
	String();
}

String::String(string s) {
	text = s;
	String();
}

void String::append(String s) { text.append(s.text); }
void String::append(const char *s) { text.append(s); }
char String::back() { return text.back(); }
size_t String::size() { return text.size(); }
String String::substr(int pos, int len) { return text.substr(pos, len); }
String::operator string() { return text; }

char & String::operator [] (size_t t) { return text[t]; }
String operator + (String a, String b) { return String(a.text + b.text); }

String& String::operator += (String s) { 
	text += s.text; 
	return *this;
}
bool String::operator == (String s) { return text == s.text; }
bool String::operator != (String s) { return text != s.text; }

vector<String> String::split(char c) {
	if (c == split_char) return split_text;
	split_char = c;

	if (c == ' ') return split("\\s+");
	if (c == '(') return split("\\(");
	if (c == ')') return split("\\)");

	string s(1, c);
	return split(s);
}

vector<String> String::split(string c) {
	regex re;
	re = c;

	split_text = vector<String> (
			sregex_token_iterator(text.begin(), text.end(), re, -1), 
			sregex_token_iterator()
			);

	return split_text;
}

String String::toUpperCase() {
	String s = *this;
	for (size_t i = 0; i < text.size(); ++i) {
		s.text[i] = toupper(text[i]);
	}
	s.split_text.clear();
	return s;
}

istream & operator >> (istream &in, String &s) {
	in >> s.text;
	return in;
}

ostream & operator << (ostream &out, String s) {
	out << s.text;
	return out;
}

istream& getline(ifstream &in, String s) {
	return std::getline(in, s.text);
}

void String::pop_back() {
	text.pop_back();
}

void String::pop_front() {
	*this = substr(1);
}
