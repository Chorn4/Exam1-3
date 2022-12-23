#include <iostream>
#include <time.h>

using namespace std;

// n Ц глобальна зм≥нна дл€ розм≥ру масив≥в
const int n = 5;

int function(int plates[n]) {
	int minimum, minutes = 0, allPlatesEmpty = 0;

	// обчиленн€ виконуЇтьс€, поки вс≥ тар≥лки не будуть порожн≥ми
	while (allPlatesEmpty != 1) {
		for (int i = 0; i < n; i++) {
			if (plates[i] > 0) {
				minimum = plates[i];
				break;
			}
		}

		// д≥знаюс€ м≥н≥мальну к≥льк≥сть гор≥шк≥в на тар≥лках
		for (int i = 0; i < n; i++) {
			if (minimum > plates[i] && plates[i] > 0) {
				minimum = plates[i];
			}
		}

		// в≥дн≥маю м≥н≥мальну к≥льк≥сть гор≥шк≥в в≥д ус≥х тар≥лок
		for (int i = 0; i < n; i++) {
			plates[i] = plates[i] - minimum;
		}

		// зб≥льшую к≥льк≥сть хвилин, необх≥дних на спустошенн€ тар≥лок
		minutes++;

		// перев≥р€ю ус≥ тар≥лки на порожн≥сть
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

	// повертаю результат (хвилини)
	return minutes;
}

int main() {
	srand(time(NULL));
	// plates - масив тар≥лок з гор≥шками
	int plates[n]{};

	// заповнюю кожну тар≥лку випадковою к≥льк≥стю гор≥шк≥в через рандом
	for (int i = 0; i < n; i++) {
		plates[i] = rand() % 9 + 1;
		cout << plates[i] << endl;
	}

	// в≥дображаю результат, обчислений функц≥Їю, у €ку був переданий масив тар≥лок
	cout << "Count of minutes which Petryk needs to empty all of the plates: " << function(plates) << "m." << endl;

	return 0;
}