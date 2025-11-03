#pragma once
#include <stdexcept>
#include <iostream>

namespace my_flist {

    // Node structure for the forward list
    template <typename T>
    struct node {
        T data;
        node* next;

        node(const T& value) : data(value), next(nullptr) {}
    };

    // Forward list class
    template <typename T>
    class forward_list {
    private:
        node<T>* head;
        std::size_t size; // Corrected type to std::size_t

    public:
        // Constructor
        forward_list() : head(nullptr), size(0) {}

        // Destructor
        ~forward_list() {
            clear();
        }

        // Push front
        void push_front(const T& value) {
            node<T>* new_node = new node<T>(value);
            new_node->next = head;
            head = new_node;
            ++size;
        }

        // Pop front
        void pop_front() {
            if (empty()) {
                throw std::underflow_error("List is empty");
            }
            node<T>* temp = head;
            head = head->next;
            delete temp;
            --size;
        }

        bool empty() const {
            return head == nullptr;
        }

        std::size_t get_size() const {
            return size;
        }

        void display() const {
            node<T>* current = head;
            while (current != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "NULL" << std::endl;
        }

        // Clear All
        void clear() {
            while (!empty()) {
                pop_front();
            }
        }

        // Copy Constructor
        forward_list(const forward_list& other) : head(nullptr), size(0) {
            node<T>* temp = other.head;
            node<T>** current = &head;
            while (temp) {
                *current = new node<T>(temp->data);
                current = &((*current)->next);
                temp = temp->next;
                ++size;
            }
        }

        // Assignment operator
        forward_list& operator=(const forward_list& other) {
            if (this != &other) {
                clear();
                node<T>* temp = other.head;
                node<T>** current = &head;
                while (temp) {
                    *current = new node<T>(temp->data);
                    current = &((*current)->next);
                    temp = temp->next;
                    ++size;
                }
            }
            return *this;
        }

        // Iterator class definition
        class iterator {
            node<T>* ptr;
            friend forward_list;

        public:
            iterator() : ptr(nullptr) {}
            iterator(node<T>* node_ptr) : ptr(node_ptr) {}

            T* operator->() {
                return &this->ptr->data;
            }

            T& operator*() const {
                return this->ptr->data;
            }

            iterator& operator++() {
                if (ptr) ptr = ptr->next;
                return *this;
            }

            iterator operator++(int) {
                iterator temp = *this;
                if (ptr) ptr = ptr->next;
                return temp;
            }

            bool operator==(const iterator& rhs) const {
                return this->ptr == rhs.ptr;
            }

            bool operator!=(const iterator& rhs) const {
                return this->ptr != rhs.ptr;
            }
        };

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator(nullptr);
        }

        const T& at(std::size_t index) const {
            if (index >= size) {
                throw std::out_of_range("Index out of bounds");
            }

            iterator it = begin();
            for (std::size_t i = 0; i < index; ++i) {
                ++it;
            }
            return *it;
        }

        T& at(int index) {
            if (index >= size) {
                throw std::out_of_range("Index out of bounds");
            }

            iterator it = begin();
            for (int i = 0; i < index; ++i) {
                ++it;
            }
            return *it;
        }
    };
}
