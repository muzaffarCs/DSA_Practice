#pragma once
#include <stdexcept>
const int SIZE = 5;

class stack {
private:
    int top;
    int data[SIZE];

public:
    stack() : top(-1) {}

    void push(const int value) {
        if (top + 1 == SIZE) {
            throw std::exception("stack overflow");
        }
        data[++top] = value;
    }

    void pop() {
        if (top < 0) {
            throw std::exception("stack underflow");
        }
        --top;
    }

    int Top() {
        if (top < 0) {
            throw std::exception("stack is empty");
        }
        return data[top];
    }

    int size() const {
        return SIZE;
    }

    bool empty() const {
        return top < 0;
    }

    void make_empty() {
        top = -1;
    }

    stack& operator=(const stack& other) {
        if (this != &other) {
            top = other.top;
            for (int i = 0; i <= top; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    bool operator==(const stack& other) const {
        if (top != other.top) {
            return false;
        }
        for (int i = 0; i <= top; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const stack& other) const {
        return !(*this == other);
    }

    bool operator<(const stack& other) const {
        if (top != other.top) {
            return top < other.top; 
        }
        for (int i = 0; i <= top; ++i) {
            if (data[i] != other.data[i]) {
                return data[i] < other.data[i]; 
            }
        }
        return false;
    }

    bool operator>(const stack& other) const {
        return other < *this;
    }

    bool operator<=(const stack& other) const {
        return !(other < *this); 
    }

    bool operator>=(const stack& other) const {
        return !(*this < other); 
    }

};
