#include "parser.h"

Query Parser::parse(const std::vector<Token>& tokens){
    current = 0;
    return parseSelect(tokens); //further when we have INSERT, DELETE , UPDATE etc We'll include it here
}

const Token& Parser::peek(const std::vector<Token>& tokens) const{
    return tokens[current];
}

bool Parser::check(const std::vector<Token>& tokens, TokenType type) const{ 
    return peek(tokens).type == type;
}

bool Parser::match(const std::vector<Token>& tokens, TokenType type){
    if(check(tokens, type)){
        current++;
        return true;
    }
    return false;
}

const Token& Parser::previous(const std::vector<Token>& tokens) const{
    if(current == 0) throw std::runtime_error("Invalid index access");
    return tokens[current-1];
}
Query Parser::parseSelect(const std::vector<Token>& tokens){
    Query Q;
    if(!match(tokens, TokenType::SELECT)) throw std::runtime_error("Expected SELECT");
    while(true){
        if(match(tokens, TokenType::IDENTIFIER)){
            Q.addSelectedColumn(previous(tokens).lexeme);
        }
        else throw std::runtime_error("Expected a Column");
        if(!match(tokens, TokenType::COMMA)) break;
    }
    
    if(!match(tokens, TokenType::END_OF_INPUT)) throw std::runtime_error("Wrong Syntax");
    return Q;
}