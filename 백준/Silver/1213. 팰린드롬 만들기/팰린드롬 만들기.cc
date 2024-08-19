#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str;
	cin >> str;

	int size = str.size();
	for (int i = 0; i < size; i++)
		arr[str[i] - 'A']++;

	int oddcnt = 0;
	char tmp = '\0';
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 != 0) {
			oddcnt++;
			tmp = i + 'A';
		}
	}

	string ans;
	if (oddcnt <= 1) {
		for (int i = 0; i < 26; i++)
			for (int j = 1; j <= arr[i] / 2; j++)
				ans += i + 'A';
        
        if (oddcnt == 1) ans += tmp;
        
		for (int i = 25; i >= 0; i--)
			for (int j = 1; j <= arr[i] / 2; j++)
				ans += i + 'A';
	}
    
	else if (oddcnt > 1) ans = "I'm Sorry Hansoo";

	cout << ans << '\n';
	return 0;
}