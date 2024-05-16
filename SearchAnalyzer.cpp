#include "SearchAnalyzer.h"
#include <string>
#include <chrono>
#include <random>
#include <iostream>
using namespace std;

SearchAnalyzer::SearchAnalyzer(int* values, int size)
	: Analyzer(values, size) {
	selectionSort(pIntArray, size);
}

string SearchAnalyzer::analyze() { 

	// Use system clock to generate an RNG seed
	// Same thing as when we create the array to write to the binary file
	// Use binarySearch function to search for the numbers
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	minstd_rand0 generator(seed);
	int count = 100;
	int found = 0;
	while (count > 0) {
		int randNum = generator() % 1000;
		if (binarySearch(pIntArray, randNum, size)) {
			found++;
		}
		count--;
	}

	string str = to_string(found) + " out of 100 random numbers found.";
	return str;
}

bool SearchAnalyzer::binarySearchRecursive(int* values, int toFind, int start, int end) {
	
	if (start > end) {
		return false;
	}

	int mid = (start + end) / 2;

	if (values[mid] == toFind) {
		return true;
	}
	else if (values[mid] < toFind) {
		return binarySearchRecursive(values, toFind, mid + 1, end);
	}
	else {
		return binarySearchRecursive(values, toFind, start, mid - 1);
	}

}

bool SearchAnalyzer::binarySearch(int* values, int toFind, int size) {
	
	int start = 0;
	int end = size - 1;
	return binarySearchRecursive(values, toFind, start, end);

}