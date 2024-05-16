#include "DuplicatesAnalyzer.h"
#include <string>
#include <map>

using namespace std;

DuplicatesAnalyzer::DuplicatesAnalyzer(int* pArr, int size)
	: Analyzer(pArr, size) {
}

string DuplicatesAnalyzer::analyze() {
	
	// Create map to map values from array to a count
	map<int, int> map;
	
	// Iterate through array adding values to the map if not already in map
	// If value is already in map, increment the count for the that value
	for (int i = 0; i < size; i++) {
		int val = pIntArray[i];
		if (map.find(val) == map.end()) {
			map[val] = 1;
		}
		else {
			map[val]++;
		}
	}
	
	// Iterate through map and count values that appeared more than once
	int count = 0;
	for (auto const& pair : map) {
		if (pair.second > 1) {
			count++;
		}
	}

	string str = "There were a total of " + to_string(count) + " duplicate values";

	return str;
}