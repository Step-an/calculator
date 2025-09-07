#include "Token.h"

Token::Token(TokenID tokenId, std::string tokenValue) : tokenId(tokenId), tokenValue(tokenValue) {}

TokenID Token::getTokenId() const {
    return tokenId;
}

const std::string &Token::getTokenValue() const {
    return tokenValue;
}
