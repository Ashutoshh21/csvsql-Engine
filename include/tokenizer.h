#ifndef TOKENIZER_H
#define TOKENIZER_H

#include<string>
#include<vector>

enum class TokenType{
    SELECT,
    FROM,
    WHERE,
    ORDER,
    BY,
    LIMIT,
    
    IDENTIFIER,
    NUMBER,
    STRING,

    COMMA,
    STAR,

    EQUAL,
    LESS,
    GREATER,
    LESS_EQUAL,
    GREATER_EQUAL,
    NOT_EQUAL,

    AND,
    OR,

    END_OF_INPUT,
    UNKNOWN
};

struct Token{
    TokenType type;
    std::string lexeme;
};

class Tokenizer{
    public:
    std::vector<Token> tokenize(const std::string& query);

    private:
    size_t current = 0; //same synchronized pointer across all function calls

    Token identifier(const std::string& query);
    Token number(const std::string& query);
    Token string(const std::string& query);
};

std::string tokenTypeToString(TokenType type);
#endif