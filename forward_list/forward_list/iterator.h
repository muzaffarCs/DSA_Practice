#pragma once

namespace my_flist {

    template <typename T>
    class forward_list; // Forward declaration

    // Custom Iterator Class
    template <typename T>
    class Iterator {
    private:
        Node<T>* current;

        friend class forward_list<T>;

    public:
        // Constructor
        Iterator(Node<T>* node) : current(node) {}

        // Dereference operator
        T& operator*() const {
            return current->data;
        }

        // Arrow operator
        T* operator->() const {
            return &(current->data);
        }

        // Prefix increment
        Iterator& operator++() {
            if (current != nullptr)
                current = current->next;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Equality comparison
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        // Inequality comparison
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };
}