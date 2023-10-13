#include <iostream>
#include <string>
using namespace std;

int back[100][100];
int result = 0;
int T, x, y;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			back[i][j] = 0;
		}
	}

	while (T--) {
		cin >> x >> y;

		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {
				if (back[i][j] != 1) {
					back[i][j] = 1;
					result++;
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}