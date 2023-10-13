#include "Event.hpp"

using namespace std;

Event::Event() {
    op_list.clear();
}

bool Event::getEventByFileName(String file_name) {
    ifstream fin(file_name.getRawString());
    if(!fin.good()) return false;
    getEventFromFile(fin);
    return true;
}

bool Event::getEventFromFile(ifstream &fin) {
    Event();
    OperateFactory operateFactory;
    String s;
    while (s.readLineFromFile(fin)) {
        this->op_list.push_back(operateFactory.getOperateFromString(s));
    }
    return true;
}