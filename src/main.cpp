
#include<optional>
#include"parser.h"
#include<iostream>
#include<iomanip>
#include"table.h"
#include"executor.h"
#include"csv_reader.h"

int main() {

    std::cout << "csvsql-engine started\n\n";

    try {
        std::string filename;
        std::cout << "Enter the file name of the CSV to be fetched: "
                        "(for eg: employeesalary.csv) ";
        std::cin >> filename;

        CSVReader reader("data/" + filename);
        Table mainTable = reader.read();
        
        std::string query;
        std::cout<<"Enter The SQL Query you want to execute: "<<std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //consume the extra line from above cin>> first
        std::getline(std::cin, query);
        
        Tokenizer tok;

        std::vector<Token> tokens = tok.tokenize(query);

        Parser p;
        auto q = p.parse(tokens);

        Executor exec;
        Table projectedTable = exec.execute(mainTable, q);
        const auto& header = projectedTable.getheader();
        const auto& rows = projectedTable.getrows();

        for (size_t j = 0; j < projectedTable.col_count(); j++) {
            std::cout << std::setw(20) << header[j];
        }
        std::cout << std::endl;

        for (size_t i = 0; i < projectedTable.rows_count(); i++) {
            for (size_t j = 0; j < projectedTable.col_count(); j++) {
                std::cout << std::setw(20) << rows[i][j];
            }
            std::cout << std::endl;
        }

        std::cout<<"Prog execution successful"<<std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
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







/*

//testing Tokenizer on Query

#include"tokenizer.h"
#include "query.h"

Tokenizer tok1;
    std::vector<Token> tokens = tok1.tokenize("select name,age");

    for(const auto &token : tokens){
        std::cout<<tokenTypeToString(token.type)<< " : "<<token.lexeme<<std::endl;
    }
    return 0;
*/








//Testing parser's parse returning query
/*
    Parser p;
    const std::string q = "SELECT NAME, AGE";
    Tokenizer t;
    std::vector<Token> tokens = t.tokenize(q);
    Query Q = p.parse(tokens);

    std::vector<std::string> cols = Q.getSelectedColumns();

    for(auto col : cols){
        std::cout<<col<<" | ";
    }
*/







//testing everything till select statement execution
/*
#include"parser.h"
#include<iostream>
#include<iomanip>
#include"table.h"
#include"executor.h"
#include"csv_reader.h"


std::cout << "csvsql-engine started\n\n";

    try {
        std::string filename;
        std::cout << "Enter the file name of the CSV to be fetched: "
                        "(for eg: employeesalary.csv) ";
        std::cin >> filename;

        CSVReader reader("data/" + filename);
        Table mainTable = reader.read();
        
        std::string query;
        std::cout<<"Enter The SQL Query you want to execute: "<<std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //consume the extra line from above cin>> first
        std::getline(std::cin, query);
        
        Tokenizer tok;

        std::vector<Token> tokens = tok.tokenize(query);

        Parser p;
        auto q = p.parse(tokens);

        Executor exec;
        Table projectedTable = exec.execute(mainTable, q);
        const auto& header = projectedTable.getheader();
        const auto& rows = projectedTable.getrows();

        for (size_t j = 0; j < projectedTable.col_count(); j++) {
            std::cout << std::setw(20) << header[j];
        }
        std::cout << std::endl;

        for (size_t i = 0; i < projectedTable.rows_count(); i++) {
            for (size_t j = 0; j < projectedTable.col_count(); j++) {
                std::cout << std::setw(20) << rows[i][j];
            }
            std::cout << std::endl;
        }

        std::cout<<"Prog execution successful"<<std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
*/