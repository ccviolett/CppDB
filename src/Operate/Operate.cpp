#include "Operate.hpp"

using namespace std;

bool Operate::checkType(String s, String type) {
	return s.substr(0, type.size()) == type;
}