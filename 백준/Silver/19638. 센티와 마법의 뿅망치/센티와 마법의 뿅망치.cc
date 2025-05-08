#include <bits/stdc++.h>
using namespace std;

struct Compare {
	bool operator()(int a, int b) { return a > b; }
};

class HeapPQ {
private:
	Compare cmp;
	vector<int> elements;
	void swap(int i, int j) {
		int tmp = elements[i];
		elements[i] = elements[j];
		elements[j] = tmp;
	}
	void upHeap(int idx) {
		if (idx == 0) return;

		int pIdx = (idx - 1) / 2;
		if (!cmp(elements[pIdx], elements[idx])) {
			swap(idx, pIdx);
			upHeap(pIdx);
		}
	}
	void downHeap(int idx) {
		int lIdx = idx * 2 + 1;
		int rIdx = idx * 2 + 2;
		if (lIdx >= size()) return;

		int cIdx;
		if (lIdx == size() - 1) cIdx = lIdx;
		else cIdx = cmp(elements[lIdx], elements[rIdx]) ? lIdx : rIdx;

		if (!cmp(elements[idx], elements[cIdx])) {
			swap(idx, cIdx);
			downHeap(cIdx);
		}
	}

public:
	HeapPQ() = default;
	int size() { return (int)elements.size(); }
	bool empty() { return size() == 0; }
	void push(int val) {
		elements.push_back(val);
		upHeap(size() - 1);
	}
	void pop() {
		swap(0, size() - 1);
		elements.pop_back();
		downHeap(0);
	}
	int top() { return elements.front(); }
};

HeapPQ pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, h, t;
	cin >> n >> h >> t;
	
	while (n--) {
		int x; cin >> x;
		pq.push(x);
	}

	int cnt = 0;
	while (cnt < t && pq.top() >= h) {
		int m = pq.top(); pq.pop();
		pq.push(m > 1 ? m / 2 : 1);
		cnt++;
	}

	if (pq.top() < h) cout << "YES\n" << cnt << '\n';
	else cout << "NO\n" << pq.top() << '\n';
	return 0;
}