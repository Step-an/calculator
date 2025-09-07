#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H


#include <queue>
#include <unordered_map>
#include <memory>
#include "Token.h"
#include "ExprAST.h"

class Parser {
    using tokens = std::queue<Token> &;

private:
    std::unordered_map<std::string, int> precedence{
            {"+", 1},
            {"-", 1},
            {"/", 2},
            {"*", 2},
    };

    std::queue<Token> data;

    std::unique_ptr<ExprAST> parseNumber(tokens toks);

    std::unique_ptr<ExprAST> parseBinOp(tokens toks, std::unique_ptr<ExprAST> LHS);

    std::unique_ptr<ExprAST> parseExpression(std::queue<Token> &toks);


    std::unique_ptr<ExprAST> parsePrecedence(std::queue<Token> &toks, int precedence);

    std::unique_ptr<ExprAST> parsePrecedence(std::queue<Token> &toks, int precedence, std::unique_ptr<ExprAST> left);

    std::unique_ptr<ExprAST> parsePrimary(std::queue<Token> &toks);

    int getCurPrecedence(std::queue<Token> &toks);
public:
    std::unique_ptr<ExprAST> generateAST();
    Parser(std::queue<Token> tokens) : data(std::move(tokens)){}
};


#endif //CALCULATOR_PARSER_H
