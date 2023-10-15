#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long N;
int T;

// 어떤 숫자 n을 2부터 루트 n까지 나눴을 때 
// 나누어떨어지지 않는다면 그 수는 소수임
bool find(long long n) {
	if (n < 2) {
		return false;
	}
	for (long long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N;
		
		long long i = N;

		while (1) {
			if (find(i)) {
				cout << i << "\n";
				break;
			}
			i++;
		}
	}
	

	return 0;
}


