#include "parser.h"

Query Parser::parse(const std::vector<Token>& tokens){
    current = 0;
    if(check(tokens, TokenType::SELECT)){
        return parseSelect(tokens);
    }
    else throw std::runtime_error("unknown SQL statements");
    //further when we have INSERT, DELETE , UPDATE etc We'll include it here
    // --
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

    if(!match(tokens, TokenType::SELECT)) throw std::runtime_error("Expected SELECT");
    Query Q;

    //parse the selected Columns
    while(true){
        if(match(tokens, TokenType::IDENTIFIER)){
            Q.addSelectedColumn(previous(tokens).lexeme);
        }
        else throw std::runtime_error("Expected a Column");
        if(!match(tokens, TokenType::COMMA)) break;
    }
    
    //Check for where condition -> if yes , parse its conditions
    if(match(tokens , TokenType::WHERE)){
        Q.setWhereCondition(parseCondition(tokens));
    }

    //now check for EOF
    if(!match(tokens, TokenType::END_OF_INPUT)) throw std::runtime_error("Expected End of Input ");

    return Q;
}

Condition Parser::parseCondition(const std::vector<Token> &tokens){

    Condition condition;

    if(!match(tokens, TokenType::IDENTIFIER)) throw std::runtime_error("Expected a Column ");
    condition.column = previous(tokens).lexeme;
    if (
        match(tokens, TokenType::GREATER) ||
        match(tokens, TokenType::LESS) ||
        match(tokens, TokenType::GREATER_EQUAL) ||
        match(tokens, TokenType::LESS_EQUAL) ||
        match(tokens, TokenType::EQUAL) ||
        match(tokens, TokenType::NOT_EQUAL)
    )
    {
        condition.op = previous(tokens).type;
    }
    else
    {
        throw std::runtime_error("Expected comparison operator");
    }

    //check value -> a literal or identifier (not implementing identifier part for now)
    if (
        match(tokens, TokenType::IDENTIFIER) ||
        match(tokens, TokenType::NUMBER) ||
        match(tokens, TokenType::STRING)
    )
    {
        condition.value = previous(tokens).lexeme;
    }
    else
    {
        throw std::runtime_error("Expected a literal value");
    }

    return condition;
}