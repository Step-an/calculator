#ifndef CALCULATOR_TOKEN_H
#define CALCULATOR_TOKEN_H


#include <string>
#include "ToeknId.h"

class Token {
    TokenID tokenId;
    std::string tokenValue;
public:
    Token(TokenID tokenId, std::string tokenValue);

    TokenID getTokenId() const;

    const std::string &getTokenValue() const;
};


#endif //CALCULATOR_TOKEN_H
