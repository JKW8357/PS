#include <iostream>
#include <string>
using namespace std;
typedef char Data;

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
	Data top() { return !empty() ? elements[top_idx] : ' '; }
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
	Data top() { return !empty() ? topNode->dat : ' '; }
};

int main() {
	int n; cin >> n;
	while (n--) {
		ArrayStack st(55);
		string str; cin >> str;
		bool isCorrect = true;
		for (char c : str) {
			if (c == '(') st.push(c);
			else {
				if (!st.empty()) st.pop();
				else {
					isCorrect = false;
					break;
				}
			}
		}

		if (!st.empty()) isCorrect = false;
		cout << (isCorrect ? "YES\n" : "NO\n");
	}

	return 0;
}