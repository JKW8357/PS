#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string message;
	getline(cin, message);

	int happy = 0, sad = 0, i = 0;
	while (i < message.size()) {
		i = min(message.find(":-)", i), message.find(":-(", i));
		if (i == string::npos) break;
		message[i + 2] == ')' ? happy++ : sad++;
		i += 3;
	}

	if (happy > sad) cout << "happy\n";
	else if (happy < sad) cout << "sad\n";
	else if (happy != 0) cout << "unsure\n";
	else cout << "none\n";

	return 0;
}