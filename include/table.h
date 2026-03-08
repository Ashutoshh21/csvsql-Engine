#ifndef TABLE_H
#define TABLE_H

#include<string>
#include<vector>
#include<unordered_map>

class Table{

    private:
        std::vector<std::string> header;
        std::vector<std::vector<std::string>> rows;
        std::unordered_map<std::string, size_t> col_index_map;
        void BuildColIndex();
    public: 
        Table()= default;
        Table(std::vector<std::string> headers,
          std::vector<std::vector<std::string>> rows);

        const std::vector<std::string>& getheader() const;
        const std::vector<std::vector<std::string>>& getrows() const;

        size_t columnIndex(const std::string& col) const;
        
        size_t col_count() const;
        size_t rows_count() const;

};

#endif