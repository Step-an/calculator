#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "BinaryExprAST.h"
#include "NumberExprAST.h"
double evaluateAST(const ExprAST* ast);
int main() {
    std::cout << "Enter expression: ";
    std::string expr;
    std::getline(std::cin, expr);
    Lexer lexer(expr + '\n');
    std::queue<Token> toks;
    try {
        toks = lexer.compile();
    } catch (std::exception &error){
        std::cout << "Incorrect expression" << std::endl;
        return 0;
    }
    Parser parser(std::move(toks));
    std::unique_ptr<ExprAST> ast;
    try {
        ast = parser.generateAST();
    } catch (std::exception &error){
        std::cout << "Incorrect expression" << std::endl;
        return 0;
    }

    double res = evaluateAST(ast.get());
    std::cout << "Result: " << res << std::endl;
    return 0;
}

double evaluateAST(const ExprAST* ast){
    if(auto it = dynamic_cast<const BinaryExprAST*>(ast)){
        double lhs = evaluateAST(it->getLHS());
        double rhs = evaluateAST(it->getRHS());
        if(it->getOp() == "+"){
                return lhs + rhs;
        } else if(it->getOp() == "-"){
            return lhs - rhs;
        } else if(it->getOp() == "*"){
            return lhs*rhs;
        } else if(it->getOp() == "/"){
            return lhs / rhs;
        }
        
    } else if(auto it = dynamic_cast<const NumberExprAST*>(ast)){
        return it->getValue();
    }
    throw std::runtime_error("");
}