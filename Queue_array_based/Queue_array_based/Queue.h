#pragma once
#include <stdexcept>

namespace my_queue {

	template <typename T>
	class queue {
	private:
		T* data;
		int Size, Front, rear;
	public:
		queue(int s = 20) : Size(s), Front(0), rear(-1) {
			data = new T[Size];
		}
		~queue();

		//Member functions
		void push(const T);
		void pop();
		bool empty() const;
		T front() const;
		T back() const;
		T size() const;
		void make_empty();
		queue<T>& operator=(const queue<T>&);

		// Non-member functions 
		template <typename T>
		friend bool operator==(const queue<T>& lhs, const queue<T>& rhs);
		template <typename T>
		friend bool operator!=(const queue<T>& lhs, const queue<T>& rhs);
		template <typename T>
		friend bool operator<(const queue<T>& lhs, const queue<T>& rhs);
		template <typename T>
		friend bool operator>(const queue<T>& lhs, const queue<T>& rhs);
		template <typename T>
		friend bool operator<=(const queue<T>& lhs, const queue<T>& rhs);
		template <typename T>
		friend bool operator>=(const queue<T>& lhs, const queue<T>& rhs);
	};

	template <typename T>
	bool queue<T>::empty() const {
		return Front > rear;
	}
	
	template <typename T>
	void queue<T>::make_empty() {
		this->Front = 0;
		this->rear = -1;
	}

	template <typename T>
	queue<T>::~queue() {
		delete[]data;
	}

	template <typename T>
	void queue<T>::push(const T value) {
		if (rear == Size -1)
		{
			throw std::overflow_error("Queue Overflow");
		}

		data[++rear] = value;
	}

	template <typename T>
	void queue<T>::pop() {
		if (empty())
		{
			throw std::overflow_error("Queue Underflow");
		}
		++Front;
	}

	template <typename T>
	T queue<T>::front() const {
		if (empty())
		{
			throw std::exception("Queue is empty");
		}
		return data[Front];
	}

	template <typename T>
	T queue<T>::back() const {
		if (empty())
		{
			throw std::exception("Queue is empty");
		}
		return data[rear];
	}

	template <typename T>
	T queue<T>::size() const {
		return Size;
	}

	template <typename T>
	queue<T>& queue<T>::operator=(const queue<T>& other) {
		if (this != &other) {
			delete[]data;

			Size = other.Size;
			Front = other.Front;
			rear = other.rear;

			data = new T[Size];
			for (int i = Front; i <= rear; ++i)
			{
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	template <typename T>
	bool operator==(const queue<T>& lhs, const queue<T>& rhs) {
		if ((lhs.rear - lhs.Front) != (rhs.rear - rhs.Front))
			return false;

		for (int i = 0; i <= lhs.rear - lhs.Front; ++i) {
			if (lhs.data[lhs.Front + i] != rhs.data[rhs.Front + i])
				return false;
		}

		return true;
	}

	template <typename T>
	bool operator!=(const queue<T>& lhs, const queue<T>& rhs) {
		return !(lhs == rhs);
	}
}