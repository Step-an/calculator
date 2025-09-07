#ifndef CALCULATOR_BINARYEXPRAST_H
#define CALCULATOR_BINARYEXPRAST_H

#include <string>
#include <memory>
#include "ExprAST.h"

class BinaryExprAST : public ExprAST {
private:
    std::string op;
    std::unique_ptr<ExprAST> LHS;
    std::unique_ptr<ExprAST> RHS;

public:
    const std::string &getOp() const {
        return op;
    }

    const ExprAST *getLHS() const {
        return LHS.get();
    }

    const ExprAST *getRHS() const {
        return RHS.get();
    }

    BinaryExprAST(std::string op, std::unique_ptr<ExprAST> LHS,
                  std::unique_ptr<ExprAST> RHS) : op(std::move(op)),
                                                  LHS(std::move(LHS)), RHS(std::move(RHS)) {}

};
#endif //CALCULATOR_BINARYEXPRAST_H
