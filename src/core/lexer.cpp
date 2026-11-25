#include <iostream>
#include <fstream>
#include "lexer.h"
enum Lexicals{
    IDENTIFIER,
    STATEMENTEND,
    PARANTHESIS,
    BRACKET,
    CURLY,
    OP,
    DOUBLEOP
};

struct LexicalObject{
    Lexicals type;
    char value;
};

void Lexer::lex_file(std::ifstream &filestream){
    std::string line;
    while (std::getline(filestream, line)){
        std::cout << line << "\n";
    }
}