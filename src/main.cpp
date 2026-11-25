#include <iostream>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>
#include "utils/utils.h"
#include "core/lexer.h"
#include "core/interpreter.h"
// use pass by reference as often as possible
// use const parameters with pass by reference

// ASSIGNING VALUES MAKES COPIES
typedef std::unordered_map<std::string, std::unique_ptr<ValueBase>> ValuePointerHashmap;
namespace meta{
    std::string version = "0.1.0a";
}

void cout_help(){
    // replace with command and flag list
    std::cout << "Help! I need somebody, help!" << "\n";
}
void cout_version(){
    // if we ever have to change how the version is displayed.
    std::cout << meta::version << "\n";
}
int main(int argnum, char* argvalue[]){
    // argvalue is an array of pointers where each element points to an array of characters.
    using std::string;

    if (argnum<2){
        std::cout << "sauce " << meta::version << "\n\n";
        std::cerr << "Too few arguments. Try 'sauce --help' for a list of flags and arguments." << "\n";
        return 1;
    }

    char* fileName = argvalue[1];

    for (int i = 1; i < argnum; i++){
        string argString = argvalue[i]; // convert c string to std string
        if (argString == "--help"){
            cout_help();
            return 0;
        } else if (argString == "--version"){
            cout_version();
            return 0;
        }
    }

    std::ifstream in(fileName);
    if (!in) {
        std::cerr << "could not open " << fileName << "\n";
        return 1;
    }

    Lexer::lex_file(in);

    Scope testscope;
    const string help = "whats up";
    Value<string> some_value = Value(help, STRING);
    testscope.variables["test"] = std::make_unique<Value<string>>(some_value);

    ValueType& vt = (*testscope.variables["test"]).type;
    if (vt == NUMBER){
        std::cout << "The value is a number!" << "\n";
    } else if (vt == STRING){
        std::cout << "The value is a string!" << "\n";
    }
    
    
    
    return 0;
}
