#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
};
class iterator {
	node* it;
public:
	iterator() {
		it = NULL;
	}
	iterator& operator++() {
		if (it != NULL) {
			it = it->next;
		}
		return *this;
	}
	bool operator==(const iterator& other) {
		bool found = false;
		if (it->data == other.it->data) {
			found = true;
		}
		else {
			found = false;
		}
		return found;
	}
	bool& operator!=(const iterator& other) {
		bool result = false;
		if (it->data != other.it->data) {
			result = true;
		}
		return result;
	}

	int operator*() {
		int value = -1;
		if (it != NULL) {
			value = it->data;
		}
		return value;
	}
	iterator begin(forwardlist& a) {
		iterator it;
		it.it = a.head;
		return it;
	}
	iterator end(forwardlist& a) {
		iterator it;
		it.it = a.head;
		while (it.it != NULL && it.it->next != NULL) {
			it.it = it.it->next;
		}
		return it;
	}
	void iterateposition(int position) {
		if (position < 0 || position >= count) {
			cout << "Invalid position!" << endl;
			return;
		}

		iterator it = begin();
		int currentPos = 0;

		while (it != end() && currentPos < position) {
			++it;
			currentPos++;
		}

		if (it != end()) {
			cout << "Element at position " << position << ": " << *it << endl;
		}
		else {
			cout << "Position out of range" << endl;
		}
	}


	friend class forwardlist;



};
const int SIZE = 5;
class forwardlist {
private:
	node* head;
	int count;
public:
	forwardlist() {
		head = NULL;
		count = 0;
	}
	~forwardlist() {
		node* a;
		while (head != NULL) {
			a = head;
			head = head->next;
			delete a;
		}
	}
	void push_front(int val) {
		node* t;
		t = new node;
		t->data = val;
		t->next = head;
		head = t;
		count++;
	}

	void push_pos(int val) {
		int num;
		cin >> num;
		node* t;
		t = head;
		bool found = false;

		while (t != NULL && found == false) {
			if (t->data == num) {
				found = true;
				break;
			}
			else {
				t = t->next;
			}
		}

		if (found == true && t != NULL) {
			node* q;
			q = new node;
			q->data = val;
			q->next = t->next;
			t->next = q;
			count++;
		}
		else {
			cout << "Position not found" << endl;
		}
	}

	void pop(int num) {
		node* temp;
		temp = head;
		if (head == NULL) {
			cout << "empty" << endl;
			return;
		}
		if (head->data == num) {
			head = head->next;
			delete temp;
			temp = NULL;
		}
	}
	void pop_from() {
		if (head == NULL) {
			cout << "empty";
		}
		else if (head->next == NULL) {
			delete head;
			head = NULL;
		}
		else {
			node* temp;
			temp = head;
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;

		}
	}

	void empty() {
		head = NULL;
		count = 0;
	}
	int size() {
		return count;
	}
	void full() {
		if (count == SIZE) {
			cout << "list full";
		}
		else {
			cout << "list not full";
		}
	}
	void sort() {
		if (head == NULL || head->next == NULL) {
			return;
		}

		node* i = head;
		node* j = NULL;
		int temp;

		while (i != NULL) {
			j = i->next;
			while (j != NULL) {
				if (i->data > j->data) {
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
				j = j->next;
			}
			i = i->next;
		}
	}
	void merge(forwardlist& list2) {
		node* temp1 = head;
		node* temp2 = list2.head;
		forwardlist mergedList;

		while (temp1 != NULL && temp2 != NULL) {
			if (temp1->data < temp2->data) {
				mergedList.push_front(temp1->data);
				temp1 = temp1->next;
			}
			else {
				mergedList.push_front(temp2->data);
				temp2 = temp2->next;
			}
		}

		while (temp1 != NULL) {
			mergedList.push_front(temp1->data);
			temp1 = temp1->next;
		}

		while (temp2 != NULL) {
			mergedList.push_front(temp2->data);
			temp2 = temp2->next;
		}

		head = mergedList.head;
		count = mergedList.count;
	}


	void print() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

};
int main() {
	forwardlist list1;

	list1.push_front(10);
	list1.push_front(20);
	list1.push_front(30);
	list1.push_front(40);
	list1.push_front(50);

	iterator it = list1.begin();
	iterator last = list1.end();

	while (it != last) {
		cout << *it << " ";
		++it;
	}

	cout << endl;
	iterateposition(list1, 3);

	return 0;
} remove all the errors code chnge na kros