#ifndef _STRING_H
#define _STRING_H

#include <bits/stdc++.h>
using namespace std;

class String {
	private:
		string text;
		char split_char;
		vector<String> split_text;

	public:
		String();
		String(char c);
		String(const char *s);
		String(string s);

		void append(String s);
		void append(const char *s);
		void pop_back();
		void pop_front();
		char back();
		size_t size();
		String substr(int pos, int len = 0x3f);

		operator string();
		bool operator == (String s);
		bool operator != (String s);
		char & operator [] (size_t t);
		String& operator += (String s);

		vector<String> split(char c);
		vector<String> split(string c);

		String toUpperCase();

		friend String operator + (String a, String b);
		friend istream & operator >> (istream &in, String &s);
		friend ostream & operator << (ostream &out, String s);
		friend istream& getline(ifstream &in, String s);
};

#include "String.cpp"

#endif
