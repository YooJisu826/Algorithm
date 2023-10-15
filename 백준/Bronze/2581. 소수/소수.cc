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

	int sum = 0; // 소수들의 합
	int min = -1; // 소수인 것 중 최솟값
	
	for (int i = M; i <= N; i++) {
		// 소수인 경우만 
		if (find(i)) {
			sum += i; // sum에 더해주기
			if (min == -1) { // 첫 소수라면 (= 최솟값이라면)
				min = i;
			}
		}
	}

	// 소수가 존재한다면
	if (min != -1) {
		cout << sum << "\n" << min << "\n";
	}
	// 존재하지 않는다면
	else {
		cout << min << "\n";
	}

	return 0;
}


