#include <iostream>
using namespace std;
typedef int Data;
#define ERROR -1

class ArrayQueue {
private:
	Data* elements;
	int capacity;
	int n;
	int frontIdx;
	int rearIdx;

public:
	ArrayQueue(int N) : elements(new Data[N]), capacity(N), n(0), frontIdx(0), rearIdx(0) {}
	~ArrayQueue() { delete[] elements; }
	int size() { return n; }
	bool empty() { return size() == 0; }
	void push(Data& val) {
		if (size() == capacity) return;
		elements[rearIdx] = val;
		rearIdx = (rearIdx + 1) % capacity;
		n++;
	}
	void pop() {
		if (empty()) return;
		frontIdx = (frontIdx + 1) % capacity;
		n--;
	}
	Data front() { return !empty() ? elements[frontIdx] : ERROR; }
	Data rear() { return !empty() ? elements[(rearIdx - 1 + capacity) % capacity] : ERROR; }
	Data* frontPtr() { return !empty() ? &elements[frontIdx] : nullptr; }
	Data* rearPtr() { return !empty() ? &elements[(rearIdx - 1 + capacity) % capacity] : nullptr; }
};



struct Node {
	Data dat;
	Node* nxt;
};

class ListQueue {
private:
	Node* frontNode;
	Node* rearNode;
	int n;

public:
	ListQueue() : frontNode(nullptr), rearNode(nullptr), n(0) {}
	~ListQueue() {
		Node* curNode = frontNode;
		while (curNode != nullptr) {
			Node* delNode = curNode;
			curNode = curNode->nxt;
			delete delNode;
		}
	}
	int size() { return n; }
	bool empty() { return size() == 0; }
	void push(Data& val) {
		Node* newNode = new Node{ val, nullptr };
		if (empty()) frontNode = rearNode = newNode;
		else {
			rearNode->nxt = newNode;
			rearNode = rearNode->nxt;
		}
		n++;
	}
	void pop() {
		if (empty()) return;
		Node* delNode = frontNode;
		if (size() == 1) frontNode = rearNode = nullptr;
		else frontNode = frontNode->nxt;
		delete delNode;
		n--;
	}
	Data front() { return !empty() ? frontNode->dat : ERROR; }
	Data rear() { return !empty() ? rearNode->dat : ERROR; }
	Node* frontPtr() { return !empty() ? frontNode : nullptr; }
	Node* rearPtr() { return !empty() ? rearNode : nullptr; }
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	ArrayQueue q(2000005);

	while (n--) {
		string query; cin >> query;
		if (query == "push") { 
			int x; cin >> x;
			q.push(x); 
		}
		else if (query == "pop") {
			cout << (!q.empty() ? q.front() : ERROR) << '\n';
			q.pop();
		}
		else if (query == "size") cout << q.size() << '\n';
		else if (query == "empty") cout << int(q.empty()) << '\n';
		else if (query == "front") cout << q.front() << '\n';
		else cout << q.rear() << '\n';
	}

	return 0;
}