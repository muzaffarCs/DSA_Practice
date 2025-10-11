#include "stack.h"
#include <iostream>
#include <stdexcept>

int main() {
    try
    {
        my_stk::stack<int> stk1(3);
        my_stk::stack<int> stk2(5);

        stk1.push(1);
        stk1.push(2);
        stk1.push(3);

        stk2.push(10);
        stk2.push(20);
        stk2.push(30);
        stk2.push(40);
        stk2.push(50);
        
        std::cout << "Top element: " << stk2.top() << std::endl;
        stk2.pop();
        std::cout << "Top element: " << stk2.top() << std::endl;

        std::cout << "stk1 == stk2: " << (stk1 == stk2 ? "True" : "False") << std::endl;
        std::cout << "stk1 < stk2: " << (stk1 < stk2 ? "True" : "False") << std::endl;
    }
    catch (const std::exception& e) { 
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}