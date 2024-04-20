#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, v;
	int days;

	cin >> a >> b >> v;
	
	days = (v - a) / (a - b) + 1;
	
	if ((v - a) % (a - b) != 0) {
		days++;
	}
	
	if (a >= v) { 
		cout << 1 << "\n"; 
		return 0; }

	cout << days << "\n";
}