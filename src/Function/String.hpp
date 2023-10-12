#ifndef _STRING_H
#define _STRING_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

class String {
private:
    bool nullFlag;
    std::string text;

public:
    String();
    String(const char *s);
    explicit String(char c);
    explicit String(std::string s);

    std::string getRawString();

    void append(String s);
    void append(const char *s);
    void pop_back();
    void pop_front();
    char back();
    size_t size();
    bool have(char c);
    bool isNull();
    String substr(int pos, int len = 0x3f);
    String lrSubstr(int l, int r);

    String align(String s) { return alignFront(s); }
    String stagger(String s) { return staggerFront(s); }
    String seek(char c) { return seekFront(c); }

    String alignFront(String s);
    String staggerFront(String s);
    String alignBack(String s);
    String staggerBack(String s);
    String seekFront(char c);
    String seekOrFront(char a, char b);
    String seekAndFront(char a, char b);
    String seekBack(char c);
    String seekOrBack(char a, char b);
    String cleanFrontSpace(); // 去除开头空格
    String cleanBackSpace(); // 去除结尾空格

    bool operator == (String s);
    bool operator != (String s);
    char & operator [] (size_t t);
    String& operator += (String s);
    String& operator + (char c);
    String& operator += (char c);


    std::istream& readLineFromFile(std::ifstream &fin);
    std::istream& readLineFromCommand();

    std::vector<String> splitByChar(char c);
    std::vector<String> split(char c);
    std::vector<String> split(std::string c);

    bool haveUpperCase();
    bool haveLowerCase();
    String toUpperCase();
    String toLowerCase();

    friend String operator + (String a, String b);
    friend std::istream & operator >> (std::istream &in, String &s);
    friend std::ostream & operator << (std::ostream &out, String s);

    static String getNullString();
    static String getEmptyString();

};

#endif