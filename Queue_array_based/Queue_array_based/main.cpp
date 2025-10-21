#include "Queue.h"
#include <iostream>
#include <stdexcept>

int main() {
    try
    {
        my_queue::queue<int> que1;
        my_queue::queue<int> que2(5);

        my_queue::queue<int> que3(5);

        que1.push(1);
        que1.push(2);
        que1.push(3);
        que1.push(4);
        
        que2.push(10);
        que2.push(20);
        que2.push(30);
        que2.push(40);
        que2.push(50);

        que3 = que1;
        std::cout << "Front element Queue3 : " << que3.front() << std::endl;
        std::cout << "Front element Queue2 : " << que1.front() << std::endl;
        que1.pop();
        std::cout << "Front element after pop in Queue2 : " << que1.front() << std::endl;
        
        std::cout << "Front element Queue1 : " << que2.front() << std::endl;
        que2.pop();
        std::cout << "Front element after pop in Queue1 : " << que2.front() << std::endl;

        std::cout << "Size of Queue1: " << que1.size() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}