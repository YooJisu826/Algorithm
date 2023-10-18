#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	string str;
	cin >> T;

	while (T--) {
		stack<char> s;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (s.size() == 0) {
				s.push(str[i]);
			}
			else {
				if (str[i] == ')') {
					if (s.top() == '(') {
						s.pop();
					}
				} else {
					s.push(str[i]);
				}
			}
		}

		if (s.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}


