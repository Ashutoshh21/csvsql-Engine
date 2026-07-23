#ifndef PARSER_H
#define PARSER_H

#include"query.h"
#include"tokenizer.h"

class Parser{
    public:
    Query parse(const std::vector<Token>& tokens);

    private:
    size_t current = 0;
    const Token& peek(const std::vector<Token>& tokens) const; //returns the current token type being pointed at;
    bool check(const std::vector<Token>& tokens, TokenType type) const; //check if current token type equal to given type
    bool match(const std::vector<Token>& tokens, TokenType type); //if same tokentype, consumes and move to next token
    const Token& previous(const std::vector<Token>& tokens) const; //previous to current token

    Query parseSelect(const std::vector<Token>& tokens);
    Condition parseCondition(const std::vector<Token>& tokens);
    Condition parseWhereClause(const std::vector<Token>& tokens);
};

#endif