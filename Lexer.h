#ifndef CALCULATOR_LEXER_H
#define CALCULATOR_LEXER_H


#include <queue>
#include "Token.h"

class Lexer {
private:
    Token getTok();

    std::string code;
    char current = -2;


    int curIndex = -1;

    char getNextChar() { return current = code[++curIndex]; }

public:
    Lexer(std::string code, ILogger *logger) :
            code(std::move(code)) {};

    std::queue<Token> compile();
};


#endif //CALCULATOR_LEXER_H
