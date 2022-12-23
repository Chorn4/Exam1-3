#include <iostream>
#include <time.h>

using namespace std;

// n � ��������� ����� ��� ������ ������
const int n = 5;

int function(int plates[n]) {
	int minimum, minutes = 0, allPlatesEmpty = 0;

	// ��������� ����������, ���� �� ������ �� ������ ��������
	while (allPlatesEmpty != 1) {
		for (int i = 0; i < n; i++) {
			if (plates[i] > 0) {
				minimum = plates[i];
				break;
			}
		}

		// ������� �������� ������� ������ �� �������
		for (int i = 0; i < n; i++) {
			if (minimum > plates[i] && plates[i] > 0) {
				minimum = plates[i];
			}
		}

		// ������ �������� ������� ������ �� ��� ������
		for (int i = 0; i < n; i++) {
			plates[i] = plates[i] - minimum;
		}

		// ������� ������� ������, ���������� �� ����������� ������
		minutes++;

		// �������� �� ������ �� ���������
		int fullPlate = 0;
		for (int i = 0; i < n; i++) {
			if (plates[i] > 0) {
				fullPlate = plates[i];
			}
		}

		if (fullPlate == 0) {
			allPlatesEmpty = 1;
		}
	}

	// �������� ��������� (�������)
	return minutes;
}

int main() {
	srand(time(NULL));
	// plates - ����� ������ � ��������
	int plates[n]{};

	// �������� ����� ������ ���������� ������� ������ ����� ������
	for (int i = 0; i < n; i++) {
		plates[i] = rand() % 9 + 1;
		cout << plates[i] << endl;
	}

	// ��������� ���������, ���������� ��������, � ��� ��� ��������� ����� ������
	cout << "Count of minutes which Petryk needs to empty all of the plates: " << function(plates) << "m." << endl;

	return 0;
}