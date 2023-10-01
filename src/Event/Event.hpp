#ifndef _EVENT_H
#define _EVENT_H

#include "../Operate/Operate.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class Event {
  private:
    std::vector<Operate*> op_list;

  public:
    Event();
    bool getEventByFileName(String file_name);
    bool getEventFromFile(std::ifstream &fin);
};

#endif