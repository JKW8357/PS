#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	cin.ignore(); 
	// cin 다음으로 getline을 사용할 때는 cin.ignore()를 통해
	// getline이 버퍼에 남아 있던 '\n'까지 읽어들이지 않도록 하자.

	for (int i = 1;i <= tc; i++) {
		string line, word;
		getline(cin, line);

		// std::stringstream은 입력값을 쉽게 파싱하고, 출력값을 문자열로 처리하는 데 매우 유용하다.
		stringstream ss(line);
		vector<string> words;

		// 입력값을 white space를 기준으로 단어로 나눈다.
		while (ss >> word) words.push_back(word);
		cout << "Case #" << i << ": ";

		reverse(words.begin(), words.end());
		for (auto s : words) cout << s << ' ';
		cout << '\n';
	}

	return 0;
}

/*
std::stringstream은 입력값을 쉽게 파싱하고, 출력값을 문자열로 처리하는 데 매우 유용하다.

예시:
input:
str = "apple,banana,cherry";
while (std::getline(ss, str, ',')) { std::cout << word << '\n'; }

output:
apple
banana
cherry
*/