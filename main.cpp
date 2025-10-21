#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
#include <sstream>

#include "ArrayStack.h"

int main() {
    Stack<5> stack;

    stack.Push(9);

    stack.PrintAll();

    std::cout << "-----------------" << std::endl;

    stack.Push(8);
    stack.Push(2);
    stack.Push(40);
    stack.Push(15);
    stack.Push(99);

    stack.PrintAll();

    std::cout << "-----------------" << std::endl;

    stack.Pop();
    stack.Pop();
    stack.PrintAll();
    
    return 0;
}