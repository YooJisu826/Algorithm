#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;

// 어떤 숫자 n을 2부터 루트 n까지 나눴을 때 
// 나누어떨어지지 않는다면 그 수는 소수임
bool find(int n) {
	if (n == 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	
	for (int i = M; i <= N; i++) {
		// 소수인 경우만 
		if (find(i)) {
			cout << i << "\n";
		}
	}

	return 0;
}


