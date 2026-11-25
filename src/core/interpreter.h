#ifndef INTERPRETER
#define INTERPRETER

#include <string>
#include <memory>

namespace Interpreter{
}

enum ValueType{
    STRING,
    NUMBER
};


struct ValueBase {
    ValueType type;

    virtual ~ValueBase() = default;
};


template <typename T>
struct Value : ValueBase {
    T v;
    Value(T content, ValueType _type) : v(content) {type=_type;}
    ~Value() = default; // default destructor
    T get_value(){return v;}
};

typedef std::unordered_map<std::string, std::unique_ptr<ValueBase>> ValuePointerHashmap;

struct Scope{
    ValuePointerHashmap variables;
};


#endif