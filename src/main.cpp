
#include"tokenizer.h"
#include<iostream>

int main() {
    Tokenizer tok1;
    std::vector<Token> tokens = tok1.tokenize("select name,age");

    for(const auto &token : tokens){
        std::cout<<tokenTypeToString(token.type)<< " : "<<token.lexeme<<std::endl;
    }
    return 0;
}


// Testing Table creation
/*

#include "csv_reader.h"
#include <iomanip>
#include <stdexcept>



std::cout << "csvsql-engine started\n\n";

try {
    std::string filename;
    std::cout << "Enter the file name of the CSV to be fetched: "
                    "(for eg: employeesalary.csv) ";
    std::cin >> filename;

    CSVReader reader("data/" + filename);
    Table tab1 = reader.read();

    const std::vector<std::string>& header = tab1.getheader();
    const std::vector<std::vector<std::string>>& rows = tab1.getrows();

    for (size_t j = 0; j < tab1.col_count(); j++) {
        std::cout << std::setw(20) << header[j];
    }
    std::cout << std::endl;

    for (size_t i = 0; i < tab1.rows_count(); i++) {
        for (size_t j = 0; j < tab1.col_count(); j++) {
            std::cout << std::setw(20) << rows[i][j];
        }
        std::cout << std::endl;
    }

    std::cout<<"Prog execution successful"<<std::endl;

} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
*/