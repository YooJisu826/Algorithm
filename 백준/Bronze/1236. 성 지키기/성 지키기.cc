#include <iostream>
using namespace std;

int N, M;
int countCol = 0;
int countRow = 0;
char matrix[50][50];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	char a;
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			matrix[i][j] = a;
		}
	}

	for (int i = 0; i < N; i++) {
		bool check = false;
		for (int j = 0; j < M; j++) {
			if (matrix[i][j] == 'X') {
				check = true;
			}
		}
		if (check == false) {
			countCol++;
		}
	}

	for (int i = 0; i < M; i++) {
		bool check = false;
		for (int j = 0; j < N; j++) {
			if (matrix[j][i] == 'X') {
				check = true;
			}
		}
		if (check == false) {
			countRow++;
		}
	}

	result = countCol <= countRow ? countRow : countCol;

	cout << result << "\n";

	return 0;
}