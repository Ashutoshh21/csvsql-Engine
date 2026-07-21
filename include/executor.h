#ifndef EXECUTOR_H
#define EXECUTOR_H

#include"table.h"
#include"query.h"

class Executor{
    public:
        Table execute(const Table& t, const Query& q);

};
#endif