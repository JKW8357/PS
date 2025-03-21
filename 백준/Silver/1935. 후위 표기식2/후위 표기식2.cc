#include <iostream>
using namespace std;
typedef double Data;

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
	int top() { return !empty() ? elements[top_idx] : -1; }
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
	Data top() { return !empty() ? topNode->dat : -1; }
};

Data mapping[26];

int main() {
	int n; cin >> n;
	string postfix; cin >> postfix;
	for (int i = 0; i < n; i++) cin >> mapping[i];

	ListStack st;
	for (char c : postfix) {
		if (c - 'A' >= 0 && c - 'A' < 26) st.push(mapping[c - 'A']);
		else {
			double second = st.top(); st.pop();
			double first = st.top(); st.pop();

			double result = 0;
			if (c == '+') result = first + second;
			if (c == '-') result = first - second;
			if (c == '*') result = first * second;
			if (c == '/') result = first / second;

			st.push(result);
		}
	}

	double ans = st.top(); st.pop();
	cout.precision(2);
	cout << fixed << ans << '\n';
}