#include "Lexer.h"
Token Lexer::getTok() {
    if (current == -2)
        getNextChar();
    while (isspace(current)) {
        if (current == '\n'){
            break;
        }
        getNextChar();
    }

    if (isdigit(current)) {
        std::string numberStr;
        while (true) {
            numberStr += current;
            getNextChar();
            if (!isdigit(current) && (current != '.'))
                break;
        }
        return Token(TokenID::number, std::move(numberStr));
    }




    if (current == '+' || current == '-' || current == '*' || current == '/' || current == '(' || current == ')') {
        std::string curVal;
        curVal.push_back(current);
        getNextChar();
        return Token(TokenID::op, std::move(curVal));
    }

    if (current == '\n'){
        return Token(TokenID::eof, "");
    }
    throw std::exception();

}

std::queue<Token> Lexer::compile() {
    std::queue<Token> result;
    while (true) {
        auto tok = getTok();
        auto tokinf = tok.getTokenId();
        result.push(tok);
        if (tokinf == TokenID::eof)
            break;
    }
    return result;
}
