#include <iostream>
#include "forward_list.h"

int main() {
    try {
        my_flist::forward_list<int> flist;

        flist.push_front(10);
        flist.push_front(20);
        flist.push_front(30);

        std::cout << "Value at index 2: " << flist.at(2) << std::endl;

        my_flist::forward_list<int>::iterator it;

        it = flist.begin();

        std::cout << "List after push_front operations: ";
        while (it != flist .end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        flist.pop_front();

        it = flist.begin();
        std::cout << "List after pop_front operation: ";
        while (it != flist.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
