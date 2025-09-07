#include <iostream>
#include "Lexer.h"
#include "Parser.h"

int main() {
    std::cout << "Enter expression: ";
    std::string expr;
    std::getline(std::cin, expr);
    Lexer lexer(expr + '\n');
    auto toks = lexer.compile();
    Parser parser(std::move(toks));
    auto ast = parser.generateAST();
    return 0;
}