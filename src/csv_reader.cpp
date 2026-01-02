#include "csv_reader.h"
#include<iostream>
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
        if(!row.empty()) data.push_back(row);
    }

    file.close();
    return true;   
}

void CSVReader::display(int limit) const{
    if(headers.empty()) return;

    for(const auto &col : headers){
        std::cout<<col<<"  |  ";
    }
    std::cout<<std::endl;

    for(size_t i= 0; i < headers.size(); i++){
        std::cout<<"------------------";
    }
    std::cout<<std::endl;

    int rows = std::min(limit, (int)data.size());

    for(int i = 0; i < rows; i++){
        for(const auto &cell : data[i]){
            std::cout<<cell<<"    |   ";
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