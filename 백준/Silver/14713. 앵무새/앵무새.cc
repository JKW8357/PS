#include <bits/stdc++.h>
using namespace std;

queue<string> parrots[105];
string arr[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string sentence;
		getline(cin, sentence);
		stringstream ss(sentence);
		string word;
		while (getline(ss, word, ' ')) parrots[i].push(word);
	}

	string word;
	int wordCnt = 0;
	while (cin >> word) arr[wordCnt++] = word;

	for (int i = 0; i < wordCnt; i++) {
		bool found = false;

		for (int j = 0; j < n; j++) {
			if (parrots[j].front() == arr[i]) {
				found = true;
				parrots[j].pop();
				break;
			}
		}

		if (!found) {
			cout << "Impossible\n";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!parrots[i].empty()) {
			cout << "Impossible\n";
			return 0;
		}
	}

	cout << "Possible\n";
	return 0;
}