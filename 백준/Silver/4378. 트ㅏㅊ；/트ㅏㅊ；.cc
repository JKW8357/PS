#include <bits/stdc++.h>
using namespace std;

string str[4] = { "`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./" };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string sentence;
	while (getline(cin, sentence)) {
		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] == ' ') cout << ' ';
			else {
				for (int j = 0; j < 4; j++) {
					auto idx = str[j].find(sentence[i]);
					if (idx == string::npos) continue;
					cout << str[j][idx - 1];
					break;
				}
			}
		}
		cout << '\n';
	}
	
	return 0;
}