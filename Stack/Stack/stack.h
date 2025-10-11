#pragma once
#include <stdexcept>

namespace my_stk {

	template <typename T>
	class stack {
	private:
		T* data;
		int size;
		int Top;
	public:
		stack(int s = 100) : size(s), Top(-1) {
			data = new T[size];
		}
		~stack();
		
		//Member functions
		bool empty() const;
		void push(T);
		void pop();
		T top() const;	
		void swap(stack&);
		stack<T>& operator=(const stack<T>& );

		// Non-member functions 
		template <typename T>
		friend bool operator==(const stack<T>& lhs, const stack<T>& rhs);
		template <typename T>
		friend bool operator!=(const stack<T>& lhs, const stack<T>& rhs);
		template <typename T>
		friend bool operator<(const stack<T>& lhs, const stack<T>& rhs);
		template <typename T>
		friend bool operator>(const stack<T>& lhs, const stack<T>& rhs);
		template <typename T>
		friend bool operator<=(const stack<T>& lhs, const stack<T>& rhs);
		template <typename T>
		friend bool operator>=(const stack<T>& lhs, const stack<T>& rhs);
	};

	template <typename T>
	stack<T>::~stack(){
		delete[]data;
	}
	template <typename T>
	bool stack<T>::empty() const{
		return Top < 0;
	}

	template <typename T>
	void stack<T>::push(T value) {
		if (Top + 1 == size) {
			throw std::overflow_error("Stack Overflow");
		}
		data[++Top] = value;
	}

	template <typename T>
	void stack<T>::pop() {
		if (Top == -1)
		{
			throw std::underflow_error("Stack Underflow");
		}
		--Top;
	}
	template <typename T>
	T stack<T>::top() const {
		if (Top == -1) {
			throw std::exception("Stack is empty");
		}
		return data[Top];
	}	

	template <typename T>
	void stack<T>::swap(stack<T>& other) {
		if (size == other.size)
		{
			T* tempdata = data;
			data = other.data;
			other.data = tempdata;

			int temptop = Top;
			Top = other.Top;
			other.Top = temptop;
		}
		//TODO : implement the function for different size stack
		else
		{
			throw std::exception("stacks have different size");
		}
	}

	template <typename T>
	stack<T>& stack<T>::operator=(const stack<T>& other) {
		if (this!= &other) {
			delete[]data;

			size = other.size;
			Top = other.Top;

			data = new T[size];
			for (int i = 0; i <= Top; ++i)
			{
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	template <typename T>
	bool operator==(const stack<T>& lhs, const stack<T>& rhs) {
		if (lhs.Top != rhs.Top)
			return false;
		for (int i = 0; i <= lhs.Top; ++i) { 
			if (lhs.stk[i] != rhs.stk[i])
				return false;
		}
		return true; 
	}

	template <typename T>
	bool operator!=(const stack<T>& lhs, const stack<T>& rhs) {
		return !(lhs == rhs);
	}


	template <typename T>
	bool operator<(const stack<T>& lhs, const stack<T>& rhs) {
		int minTop = lhs.Top < rhs.Top ? lhs.Top : rhs.Top;

		for (int i = 0; i <= minTop; ++i) {
			if (lhs.data[i] < rhs.data[i])
				return true;
			else if (lhs.data[i] > rhs.data[i])
				return false;
		}

		return lhs.Top < rhs.Top;
	}


	template <typename T>
	bool operator>(const stack<T>& lhs, const stack<T>& rhs) {
		return lhs < rhs;
	}

	template <typename T>
	bool operator<=(const stack<T>& lhs, const stack<T>& rhs) {
		return (lhs < rhs) || (lhs == rhs);
	}

	template <typename T>
	bool operator>=(const stack<T>& lhs, const stack<T>& rhs) {
		return (lhs > rhs) || (lhs == rhs);
	}
}