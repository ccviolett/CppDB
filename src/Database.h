#ifndef _DATABASE_H
#define _DATABASE_H

#include "CSV.h"
#include "Table.h"

int n_id, n_ver;
int cur_id, cur_ver;

class Database {
public:
	String name;
};

#include "Database.cpp"

#endif
