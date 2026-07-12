#include "tokenizer.h"
#include<cctype>
#include<unordered_map>

namespace {
    const std::unordered_map<std::string, TokenType> keywords = {
        {"SELECT", TokenType::SELECT},
        {"FROM",   TokenType::FROM},
        {"WHERE",  TokenType::WHERE},
        {"ORDER",  TokenType::ORDER},
        {"BY",     TokenType::BY},
        {"LIMIT",  TokenType::LIMIT},
        {"AND",    TokenType::AND},
        {"OR",     TokenType::OR}
    };
}

std::vector<Token> Tokenizer::tokenize(const std::string& query) {

    current = 0;
    std::vector<Token> tokens;

    while (current < query.length()) {

        char c = query[current];

        if (std::isspace(c)) {
            current++;
        }

        else if (std::isalpha(c) || c == '_') {
            tokens.push_back(identifier(query));
        }
        else if(c == ','){
            tokens.push_back({TokenType::COMMA, std::string(1,c)});
            current++;
        }
        else {
            tokens.push_back({TokenType::UNKNOWN, ""});
            current++;
        }
    }

    tokens.push_back({TokenType::END_OF_INPUT, ""});

    return tokens;
}

Token Tokenizer::identifier(const std::string& query){
    size_t start = current;
    while(current < query.length() && (std::isalnum(query[current]) || query[current] == '_')) current++;

    std::string lexeme = query.substr(start, current-start);
    std::string upperlexeme = lexeme;

    for(char& c : upperlexeme){
        c = toupper(static_cast<unsigned char>(c));
    }

    auto it = keywords.find(upperlexeme);
    if(it != keywords.end()) return {it->second, lexeme};

    return {TokenType::IDENTIFIER , lexeme};
}

//For pretty printing my TokenType : lexeme While testing my lexer.
std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::SELECT:         return "SELECT";
        case TokenType::FROM:           return "FROM";
        case TokenType::WHERE:          return "WHERE";
        case TokenType::ORDER:          return "ORDER";
        case TokenType::BY:             return "BY";
        case TokenType::LIMIT:          return "LIMIT";

        case TokenType::IDENTIFIER:     return "IDENTIFIER";
        case TokenType::NUMBER:         return "NUMBER";
        case TokenType::STRING:         return "STRING";

        case TokenType::COMMA:          return "COMMA";
        case TokenType::STAR:           return "STAR";

        case TokenType::EQUAL:          return "EQUAL";
        case TokenType::NOT_EQUAL:      return "NOT_EQUAL";
        case TokenType::LESS:           return "LESS";
        case TokenType::GREATER:        return "GREATER";
        case TokenType::LESS_EQUAL:     return "LESS_EQUAL";
        case TokenType::GREATER_EQUAL:  return "GREATER_EQUAL";

        case TokenType::AND:            return "AND";
        case TokenType::OR:             return "OR";

        case TokenType::END_OF_INPUT:   return "END_OF_INPUT";
        case TokenType::UNKNOWN:        return "UNKNOWN";
    }

    return "INVALID_TOKEN";
}