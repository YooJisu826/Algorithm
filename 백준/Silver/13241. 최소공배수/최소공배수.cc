#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long A, B;

long long gcd(long long a, long long b) {
	long long c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	cout << lcm(A, B) << "\n";

	return 0;
}


