#include "csv_reader.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<algorithm>

std::vector<std::string> CSVReader::split(const std::string& line, char delimiter){
    std::vector<std::string> tokens;
    std::string token;

    std::stringstream ss(line);

    while(std::getline(ss, token, ',')){
        tokens.push_back(token);
    }
    
    return tokens;
}

bool CSVReader::load(const std::string& filename){
    std::ifstream file("data/employeesalary.csv");
    if(!file.is_open()) return false;

    std::string line;

    if(std::getline(file, line)){
        headers = split(line, ',');
    }

    while(std::getline(file,line)){
        auto row = split(line,',');
        if(!row.empty()) data.push_back(row); //this will make sure no empty str is pushed
    }                                         //careful that data[i].size() != headers.size() possible

    file.close();
    return true;   
}

void CSVReader::display(int limit) const{
    if(headers.empty()) return;

    size_t col = headers.size();

    //setting a fixed column width for presentation
    std::vector<int> maxw(headers.size(), 0);

    for(size_t i = 0; i < col; i++)
        if(maxw[i] < headers[i].size()) maxw[i] = headers[i].size();

    int rows = std::min(limit, (int)data.size());

    for(const auto& row: data){
        for(size_t j = 0; j < row.size(); j++){
            if(maxw[j] < row[j].size()){
                maxw[j] = row[j].size();
            }
        }
    }

    for(size_t i = 0; i < col; i++){
        std::cout<<std::left<<std::setw(maxw[i]+3)<<headers[i]<<" | ";
    }
    std::cout<<std::endl;

    for(size_t i= 0; i < col; i++){
        std::cout<<std::setfill('-')<<std::setw(maxw[i]+3)<<"";
    }
    std::cout<<std::endl;
    std::cout<<std::setfill(' ');

    for(int i = 0; i < rows; i++){
        for(size_t j = 0; j <data[i].size(); j++){
            std::cout<<std::left<<std::setw(maxw[j]+3)<<data[i][j]<<" | ";
        }
        std::cout<<std::endl;
    }

}

const std::vector<std::string>& CSVReader::getHeader() const{
    return headers;
}

const std::vector<std::vector<std::string>>& CSVReader::getData() const{
    return data;
}