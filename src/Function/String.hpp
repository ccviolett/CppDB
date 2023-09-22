#ifndef _STRING_H
#define _STRING_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>

class String {
	private:
		std::string text;
		char split_char;
		std::vector<String> split_text;

	public:
		String();
		String(char c);
		String(const char *s);
		String(std::string s);

		void append(String s);
		void append(const char *s);
		void pop_back();
		void pop_front();
		char back();
		size_t size();
		String substr(int pos, int len = 0x3f);

		operator std::string();
		bool operator == (String s);
		bool operator != (String s);
		char & operator [] (size_t t);
		String& operator += (String s);

		std::vector<String> split(char c);
		std::vector<String> split(std::string c);

		String toUpperCase();

		friend String operator + (String a, String b);
		friend std::istream & operator >> (std::istream &in, String &s);
		friend std::ostream & operator << (std::ostream &out, String s);
		friend std::istream& getline(std::ifstream &in, String s);
};

#endif
