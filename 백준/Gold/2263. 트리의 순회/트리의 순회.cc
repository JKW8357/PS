#include <bits/stdc++.h>
using namespace std;

int inOrder[100005];
int inOrderPos[100005];
int postOrder[100005];

void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd) return;

	int root = postOrder[postEnd];
	int rootIdx = inOrderPos[root];
	int leftSize = rootIdx - inStart;

	cout << root << ' ';
	preOrder(inStart, rootIdx - 1, postStart, postStart + leftSize - 1);
	preOrder(rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inOrder[i];
		inOrderPos[inOrder[i]] = i;
	}
	for (int i = 0; i < n; i++) cin >> postOrder[i];

	preOrder(0, n - 1, 0, n - 1);
	cout << '\n';

	return 0;
}