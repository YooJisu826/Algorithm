#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	set<int> A,B;

	int num;
	int count = 0;

	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		cin >> num;
		A.insert(num);
	}
	for (int i = 0; i < b; i++) {
		cin >> num;
		B.insert(num);
	}

	for (auto iterA = A.begin(); iterA != A.end(); iterA++) {
		if (B.find(*iterA) == B.end()) {
			count++;
		}
	}
	for (auto iterB = B.begin(); iterB != B.end(); iterB++) {
		if (A.find(*iterB) == A.end()) {
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}


