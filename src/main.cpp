#include<iostream>
#include "csv_reader.h"

int main(){
    std::cout<<"csvsql-engine started"<<"\n \n";

    CSVReader reader;
    if(!reader.load("data/employeesalary.csv")){
        std::cout<<"Failed to load the file"<<std::endl;
        return 1;
    } 

    reader.display();
    return 0;
}

