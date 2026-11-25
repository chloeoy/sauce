#include <iostream>
#include <fstream>
#include <memory>
#include <unordered_map>
#include "interpreter.h"

// scope -> variables, subroutines
// subroutines -> ast, parameters
// ast -> std::vector<Node>
// node -> Node* children = [] | list of pointers to other nodes
// node -> new Node | Node tree lives in heap

typedef std::unordered_map<std::string, std::unique_ptr<ValueBase>> ValuePointerHashmap;
