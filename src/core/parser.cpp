#include <iostream>
#include <fstream>
#include <unordered_map>
#include "parser.h"

// scope -> variables, subroutines
// subroutines -> ast, parameters
// ast -> std::vector<Node>
// node -> Node* children = [] | list of pointers to other nodes
// node -> new Node | Node tree lives in heap