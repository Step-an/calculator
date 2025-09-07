#include <memory>
#include "Parser.h"
#include "ExprAST.h"
#include "BinaryExprAST.h"
#include "NumberExprAST.h"

std::unique_ptr<ExprAST> Parser::parseNumber(tokens toks) {
    int value;
    std::from_chars(toks.front().getTokenValue().data(), toks.front().getTokenValue().data() + toks.front().getTokenValue().size(),
                    value);
    auto expr = std::make_unique<NumberExprAST>
            (value);
    toks.pop();
    return expr;
}
std::unique_ptr<ExprAST> Parser::parsePrimary(tokens toks) {
    if (toks.front().getTokenId() == TokenID::number){
        return parseNumber(toks);
    }
    if (toks.front().getTokenId() == TokenID::op && toks.front().getTokenValue() == "(") {
        toks.pop();
        auto ret = parseExpression(toks);
        toks.pop();
        return ret;
    }
    throw std::runtime_error("");
}
std::unique_ptr<ExprAST> Parser::parseBinOp(tokens toks, std::unique_ptr<ExprAST> LHS) {
    std::string curOp = toks.front().getTokenValue();
    toks.pop();
    return std::make_unique<BinaryExprAST>(std::move(curOp), std::move(LHS), parsePrecedence(toks, precedence[curOp]));

}

std::unique_ptr<ExprAST> Parser::parseExpression(tokens toks) {
    return parsePrecedence(toks, 0);
}


std::unique_ptr<ExprAST> Parser::parsePrecedence(std::queue<Token> &toks, int precedence) {
    auto left = parsePrimary(toks);

    return parsePrecedence(toks, precedence, std::move(left));
}


std::unique_ptr<ExprAST> Parser::parsePrecedence(std::queue<Token> &toks, int precedence, std::unique_ptr<ExprAST> left) {
    while (precedence < getCurPrecedence(toks)){
        left = parseBinOp(toks, std::move(left));
    }

    return left;
}

int Parser::getCurPrecedence(tokens toks){
    if(auto it = precedence.find(toks.front().getTokenValue()); it != precedence.end()){
        return it->second;
    }

    return 0;
}

std::unique_ptr<ExprAST> Parser::generateAST() {
    return parseExpression(data);
}

