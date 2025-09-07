#ifndef CALCULATOR_NUMBEREXPRAST_H
#define CALCULATOR_NUMBEREXPRAST_H

#include "ExprAST.h"

class NumberExprAST : public ExprAST {
private:
    int value;
public:
    const int &getValue() const {
        return value;
    }

    NumberExprAST(int value) : value(value) {}
};
#endif //CALCULATOR_NUMBEREXPRAST_H
