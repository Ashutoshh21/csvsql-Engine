#ifndef CSV_READER_H
#define CSV_READER_H

#include<string>
#include<vector>

class CSVReader{
    private:
        std::vector<std::string> headers;
        std::vector<std::vector<std::string>> data;

        std::vector<std::string> split(const std::string& line, char delimiter);
    public:
        bool load(const std::string& filename);
        void display(int limit = 10) const;

        const std::vector<std::string>& getHeader() const;
        const std::vector<std::vector<std::string>>& getData() const;
};

#endif