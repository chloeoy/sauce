#include <iostream>
#include <vector>
#include "utils/utils.h"
#include "core/lexer.h"
// use pass by reference as often as possible
// use const parameters with pass by reference

// ASSIGNING VALUES MAKES COPIES


int main(){
    using std::cout;
    using std::cin;
    using std::string;
    cout << "sauce\n";
    cout << add_ints(10, 12);


    std::vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
        std::cout << "size " << v.size() << ", capacity " << v.capacity() << "\n";
    }

    return 0;
}
