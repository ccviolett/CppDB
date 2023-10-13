#include "OperateFactory.hpp"

using namespace std;

OperateFactory::OperateFactory() {
    LOG(TRACE);
    loadOperateType();
}

// TODO Dynamically load Operate Type
bool OperateFactory::loadOperateType() {
    LOG(TRACE);
    appendOperateType(OperateInsert::getType());
    appendOperateType(OperateCreate::getType());
    return true;
}

bool OperateFactory::appendOperateType(OperateType type) {
    LOG(TRACE);
    op_type_list.push_back(type);
    return true;
}

bool OperateFactory::appendOperateType(vector<OperateType> type_list) {
    LOG(TRACE);
    for (size_t i = 0; i < type_list.size(); ++i) {
        appendOperateType(type_list[i]);
    }
    return true;
}

Operate* OperateFactory::getOperateByFileName(String file_name) {
    LOG(TRACE);
    ifstream fin(file_name.getRawString());
    if (!fin.good()) {
        fin.close();
        return nullptr;
    }
    Operate* res = getOperateFromFile(fin);
    fin.close();
    return res;
}

Operate* OperateFactory::getOperateFromFile(ifstream &in) {
    LOG(TRACE);
    String text, s;
    do {
        in >> s;
        text.append(s);
        text.append(" ");
    } while (s.back() != ';');
    return getOperateFromString(text);
}

Operate* OperateFactory::getOperateFromCommand() {
    LOG(TRACE);
    String text, s;
    do {
        cin >> s;
        text.append(s);
        text.append(" ");
    } while (s.back() != ';');
    return getOperateFromString(text);
};

Operate* OperateFactory::getOperateFromString(String text) {
    LOG(TRACE);
    for (size_t i = 0; i < op_type_list.size(); ++i) {
        if (op_type_list[i].checker(text)) {
            return op_type_list[i].builder(text);
        }
    }
    return nullptr;
}
