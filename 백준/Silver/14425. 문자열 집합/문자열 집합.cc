#include <iostream>
#include <set>
using namespace std;

int main() {

	cin.tie(NULL); ios::sync_with_stdio(false);

	int N, M;
	string str;
	int count = 0;
	set<string> S;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		S.insert(str);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (S.find(str) != S.end()) {
			count++;
		}
	}
	cout << count << "\n";
	
}