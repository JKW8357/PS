#include <bits/stdc++.h>
using namespace std;

vector<string> vec;

bool cmp(const string& s1, const string& s2) {
	if (s1.size() != s2.size()) return s1.size() < s2.size();
	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;

		string tmp;
		for (char c : str) {
			if (isdigit(c)) tmp += c;
			else if (!tmp.empty()) {
				tmp.erase(0, tmp.find_first_not_of('0'));
				if (tmp.empty()) tmp = "0"; // 숫자가 모두 '0'인 경우에는 빈 문자열 대신 "0"으로 처리
				vec.push_back(tmp);
				tmp.clear();
			}
		}
		if (!tmp.empty()) {
			tmp.erase(0, tmp.find_first_not_of('0'));
			if (tmp.empty()) tmp = "0";
			vec.push_back(tmp);
		}
	}

	sort(vec.begin(), vec.end(), cmp);
	for (const string& i : vec) cout << i << '\n';
	return 0;
}

/*
"002", "000" 등 문자열 앞부분의 '0'을 제거하는 방법:

while 문을 통해 tmp[0] == '0'인 동안 erase(0, 1) 할 경우, 
첫 번째 문자를 제거하고, 그 뒤에 남은 모든 문자들이 왼쪽으로 한 칸씩 이동한다.
따라서, 문자열 길이가 n이라면 각 호출에서 O(n)의 시간이 소요되며 시간복잡도는 O(n^2)다. 

find_first_not_of는 첫 번째 '0'이 아닌 문자를 한 번에 찾을 수 있어, O(n) 시간 복잡도로 처리할 수 있다.
문자열 앞에서부터 탐색: find_first_of, find_first_not_of
문자열 뒤에서부터 탐색: find_last_of, find_last_not_of

More references: https://cplusplus.com/reference/string/string/
*/
