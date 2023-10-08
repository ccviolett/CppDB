#include "Function.hpp"

using namespace std;

void Function::show(std::vector<String> v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cerr << v[i] << " ";
    }
}