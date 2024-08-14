#include "Stack.h"
#include <iostream>
#include <string>

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Integer Stack:\n";
    while (!intStack.isEmpty()) {
        std::cout << "Top: " << intStack.peek() << std::endl;
        intStack.pop();
    }

    // Stack for floats
    Stack<float> floatStack;
    floatStack.push(1.1f);
    floatStack.push(2.2f);
    floatStack.push(3.3f);

    std::cout << "Float Stack:\n";
    while (!floatStack.isEmpty()) {
        std::cout << "Top: " << floatStack.peek() << std::endl;
        floatStack.pop();
    }
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("!");

    std::cout << "String Stack:\n";
    while (!stringStack.isEmpty()) {
        std::cout << "Top: " << stringStack.peek() << std::endl;
        stringStack.pop();
    }

    return 0;
}
