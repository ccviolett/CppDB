#include "String.hpp"

using namespace std;

String::String() {
    text = "";
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

vector<String> String::splitByChar(char c) {
    return split(c);
}

vector<String> String::split(char c) {
    char split_char = c;
    std::vector<String> split_text;

    if (c == ' ') return split("\\s+");
    if (c == '(') return split("\\(");
    if (c == ')') return split("\\)");
    if (c == '.') return split("\\.");

    string s(1, c);
    return split(s);
}

vector<String> String::split(string c) {
    regex re;
    re = c;

    vector<String> split_text = vector<String> (
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

void String::pop_back() {
    text.pop_back();
}

void String::pop_front() {
    *this = substr(1);
}

istream& String::readLineFromFile(ifstream &in) {
    return getline(in, this->text);
}

istream& String::readLineFromCommand() {
    return getline(cin, this->text);
}

String String::lrSubstr(int l, int r) {
    if (l > r) return "";
    return substr(l, r - l + 1);
}

String String::alignFront(String s) {
    if (s.size() >= this->size()) return *this;
    return this->substr(0, s.size());
}

String String::alignBack(String s) {
    if (s.size() >= this->size()) return *this;
    return this->substr(this->size() - s.size(), s.size());
}

String String::staggerFront(String s) {
    if (s.size() >= this->size()) return "";
    return this->substr(s.size(), this->size() - s.size());
}

String String::staggerBack(String s) {
    if (s.size() >= this->size()) return "";
    return this->substr(0, this->size() - s.size());
}

String String::cleanFrontSpace() {
    for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] != ' ') {
            return lrSubstr(i, text.size());
        }
    }
    return *this;
}

String String::cleanBackSpace() {
    for (size_t i = text.size() - 1; i >= 0; --i) {
        if (text[i] != ' ') {
            return lrSubstr(0, i);
        }
    }
    return *this;
}

String String::seekFront(char c) {
    if (text[0] == c) return "";
    for (int i = 1; i < text.size(); ++i) {
        if (text[i] == c) {
            return lrSubstr(0, i - 1);
        }
    }
    return *this;
}

String String::seekBack(char c) {
    for (int i = text.size() - 1; i > 0; --i) {
        if (text[i] == c) {
            return lrSubstr(0, i - 1);
        }
    }
    return "";
}

String String::seekOrFront(char a, char b) {
    if (text[0] == a || text[0] == b) return "";
    for (int i = 1; i < text.size(); ++i) {
        if (text[i] == a || text[i] == b) {
            return lrSubstr(0, i - 1);
        }
    }
    return *this;
}

String String::seekAndFront(char a, char b) {
    bool showA = false, showB = false;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == a) showA = true;
        if (text[i] == b) showB = true;
        if (showA && showB) {
            return lrSubstr(0, i - 1);
        }
    }
    return *this;
}

bool String::have(char c) {
    for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] == c) return true;
    }
    return false;
}