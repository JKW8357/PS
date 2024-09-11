#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	um["Algorithm"] = "204";
	um["DataAnalysis"] = "207";
	um["ArtificialIntelligence"] = "302";
	um["CyberSecurity"] = "B101";
	um["Network"] = "303";
	um["Startup"] = "501";
	um["TestStrategy"] = "105";

	int n;
	cin >> n;

	while (n--) {
		string q;
		cin >> q;
		cout << um[q] << '\n';
	}

	return 0;
}