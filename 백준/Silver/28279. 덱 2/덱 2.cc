#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	deque<int> dq;
	cin >> N;

	while (N--) {
		int command, num = 0;
		cin >> command;

		switch (command) {
		case 1:
			cin >> num;
			dq.push_front(num);
			break;
		case 2:
			cin >> num;
			dq.push_back(num);
			break;
		case 3:
			if (!dq.empty()) {
				num = dq.front();
				dq.pop_front();
			}
			else if (dq.empty()) {
				num = -1;
			}
			cout << num << "\n";
			break;
		case 4:
			if (!dq.empty()) {
				num = dq.back();
				dq.pop_back();
			}
			else if (dq.empty()) {
				num = -1;
			}
			cout << num << "\n";
			break;
		case 5:
			cout << dq.size() << "\n";
			break;
		case 6:
			if (!dq.empty()) {
				num = 0;
			}
			else if (dq.empty()){
				num = 1;
			}
			cout << num << "\n";
			break;
		case 7:
			if (!dq.empty()) {
				num = dq.front();
			}
			else if (dq.empty()) {
				num = -1;
			}
			cout << num << "\n";
			break;
		case 8:
			if (!dq.empty()) {
				num = dq.back();
			}
			else if (dq.empty()) {
				num = -1;
			}
			cout << num << "\n";
			break;
		default:
			break;
		}
	}

	return 0;
}


