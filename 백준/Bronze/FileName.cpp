#include <iostream>
#include <algorithm>
using namespace std;

int N;
float score[1000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	float a;
	float max = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		score[i] = a;
		if (score[i] > max) {
			max = score[i];
		}
	}

	float sum = 0;
	for (int i = 0; i < N; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}

	cout << sum / N << "\n";


	return 0;
}