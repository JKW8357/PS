#include <iostream>
#include <string>
using namespace std;
typedef string Data;

class ArrayStack {
private:
	Data* elements;
	int capacity;
	int top_idx;

public:
	ArrayStack(int N) : elements(new Data[N]), capacity(N), top_idx(-1) {}
	~ArrayStack() { delete[] elements; }
	int size() { return top_idx + 1; }
	bool empty() { return size() == 0; }
	void push(Data val) {
		if (size() >= capacity) return;
		elements[++top_idx] = val;
	}
	void pop() {
		if (empty()) return;
		--top_idx;
	}
	Data top() { return !empty() ? elements[top_idx] : ""; }
};



struct Node {
	Data dat;
	Node* nxt;
};

class ListStack {
private:
	Node* topNode;
	int siz;

public:
	ListStack() : topNode(nullptr), siz(0) {}
	~ListStack() {
		Node* cur = topNode;
		while (cur != nullptr) {
			Node* tmpNode = cur;
			cur = cur->nxt;
			delete tmpNode;
		}
	}
	int size() { return siz; }
	bool empty() { return siz == 0; }
	void push(Data val) {
		Node* newNode = new Node{ val, topNode };
		topNode = newNode;
		siz++;
	}
	void pop() {
		if (empty()) return;
		Node* delNode = topNode;
		topNode = topNode->nxt;
		delete delNode;
		siz--;
	}
	Data top() { return !empty() ? topNode->dat : ""; }
};

int main() {
	string str;
	getline(cin, str);
	
	ListStack st;
	string tmp;
	bool tag = false;
	for (char c : str) {
		if (c == '<') {
			tmp = "<";
			tag = true;
			
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
		}

		else if (c == '>') {
			tmp.push_back('>');
			tag = false;
			cout << tmp;
			tmp.clear();
		}

		else if (tag) tmp.push_back(c);

		else if (c == ' ') {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << ' ';
		}
			
		else st.push(string(1, c));
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}