#include "StatisticsAnalyzer.h"
#include "SearchAnalyzer.h"
#include <string>
#include <map>

using namespace std;

StatisticsAnalyzer::StatisticsAnalyzer(int* pArr, int s)
	: Analyzer(pArr, s) {
}

string StatisticsAnalyzer::analyze() {
	
	selectionSort(pIntArray, size);

	// Initialize variables needed for calculations
	double sum = 0;
	double mean = 0;
	double median = 0;
	int mode = 0;
	int min = pIntArray[0];
	int max = pIntArray[size - 1];

	map<int, int> map;

	// Loop through array calculating the mean
	// Also adding stuff to a map to count
	for (int i = 0; i < size; i++) {
		sum += pIntArray[i];
		if (map.find(pIntArray[i]) == map.end()) {
			map[pIntArray[i]] = 1;
		}
		else {
			map[pIntArray[i]]++;
		}
	}
	mean = sum / size;

	// Find the mode
	mode = pIntArray[0];
	int occurances = map[mode];
	for (auto const& pair : map) {
		if (pair.second > map[mode]) {
			mode = pair.first;
			occurances = pair.second;
		}
	}
	
	// Calculate the median
	int mid = size / 2;
	if (size % 2 == 0) {
		int num1 = pIntArray[mid];
		int num2 = pIntArray[mid - 1];
		median = (num1 + num2) / 2;
	}
	else {
		median = pIntArray[mid];
	}

	string analysis = "The minimum value is: " + to_string(min) + "\nThe maximum value is: " + to_string(max) + "\nThe mean value is: " + to_string(mean) + "\nThe median value is: " + to_string(median) + "\nThe mode value is: " + to_string(mode) + " which occured " + to_string(occurances) + " times";

	return analysis;
}
