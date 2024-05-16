#include "MissingAnalyzer.h"
#include <string>
#include <map>

using namespace std;

MissingAnalyzer::MissingAnalyzer(int* pArr, int size)
	: Analyzer(pArr, size){
}

string MissingAnalyzer::analyze() {

	// Create map to map values from array to a count
	map<int, int> map;

	// Fill map with possible values
	for (int i = 0; i < 1000; i++) {
		map[i] = 0;
	}

	// Iterate through array counting values that we find
	for (int i = 0; i < size; i++) {
		int val = pIntArray[i];
		map[val]++;
	}

	// Iterate through map and count values that appeared more than once
	int count = 0;
	for (auto const& pair : map) {
		if (pair.second == 0) {
			count++;
		}
	}

	string str = "There were a total of " + to_string(count) + " missing values";

	return str;
}