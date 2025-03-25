#include <bits/stdc++.h>
using namespace std;

int preOrder[1005];
int inOrder[1005];
int inOrderPos[1005];

void postOrder(int preStart, int preEnd, int inStart, int inEnd) {
	if (preStart > preEnd || inStart > inEnd) return;

	int root = preOrder[preStart];
	int rootIdx = inOrderPos[root];
	int leftSize = rootIdx - inStart;

	postOrder(preStart + 1, preStart + leftSize, inStart, rootIdx - 1);
	postOrder(preStart + leftSize + 1, preEnd, rootIdx + 1, inEnd);
	cout << root << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;

		for (int i = 0; i < n; i++) cin >> preOrder[i];
		for (int i = 0; i < n; i++) {
			cin >> inOrder[i];
			inOrderPos[inOrder[i]] = i;
		}

		postOrder(0, n - 1, 0, n - 1);
		cout << '\n';
	}

	return 0;
}