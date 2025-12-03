#pragma once
#include <stdexcept>
#include <iostream> // for std::cout

namespace my_flist {

	template <typename T>
	struct node {
		T data;
		node* next;
		node(const T& value) : data(value), next(nullptr) {}
	};

	// Forward declaration of iterator
	template <typename T>
	class Iterator;

	template <typename T>
	class forward_list {
	private:
		node<T>* head;

	public:
		forward_list() : head(nullptr) {}
		~forward_list() { clear(); }

		void push_front(const T& value) {
			node<T>* new_node = new node<T>(value);
			new_node->next = head;
			head = new_node;
		}

		void pop_front() {
			if (empty())
				throw std::underflow_error("List is empty");
			node<T>* temp = head;
			head = head->next;
			delete temp;
		}

		bool empty() const { return head == nullptr; }

		void display() const {
			for (node<T>* current = head; current; current = current->next)
				std::cout << current->data << " -> ";
			std::cout << "NULL" << std::endl;
		}

		void clear() {
			while (!empty()) pop_front();
		}

		forward_list(const forward_list& other) : head(nullptr) {
			node<T>* temp = other.head;
			node<T>** current = &head;
			while (temp) {
				*current = new node<T>(temp->data);
				current = &((*current)->next);
				temp = temp->next;
			}
		}

		forward_list& operator=(const forward_list& other) {
			if (this != &other) {
				clear();
				node<T>* temp = other.head;
				node<T>** current = &head;
				while (temp) {
					*current = new node<T>(temp->data);
					current = &((*current)->next);
					temp = temp->next;
				}
			}
			return *this;
		}

		// Iterator types
		using iterator = Iterator<T>;

		iterator begin() const { return iterator(head); }
		iterator end() const { return iterator(nullptr); }
	};

	// Custom Iterator class
	template <typename T>
	class Iterator {
	private:
		node<T>* current;

	public:
		Iterator(node<T>* node) : current(node) {}

		T& operator*() const { return current->data; }
		T* operator->() const { return &(current->data); }

		Iterator& operator++() {
			if (current) current = current->next;
			return *this;
		}

		Iterator operator++(int) {
			Iterator temp = *this;
			++(*this);
			return temp;
		}

		bool operator==(const Iterator& other) const {
			return current == other.current;
		}

		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}
	};
}
