#include <bits/stdc++.h>
using namespace std;

class cmp {
public:
	bool operator() (int a, int b) {
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		return a > b;
	}
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int x;
		cin >> x;

		if (x != 0) pq.push(x);
		if (x == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}

/*
sort() 등과 달리, priority_queue는 3번째 인자로 함수 포인터 대신 함수 객체(functor)를 받는다. 
struct나 class를 만들고 operator()을 오버로딩해야 한다. 
*/