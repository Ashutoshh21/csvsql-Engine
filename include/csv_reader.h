#ifndef CSV_READER_H
#define CSV_READER_H

#include "table.h"
#include<string>
#include<vector>
#include<unordered_map>

class CSVReader{
    private:
        std::string filename;
        std::vector<std::string> split(const std::string& line, char delimiter);
    public:
        CSVReader(const std::string& filename);
        Table read();  //reads the data into a table object and returns it
};

#endif