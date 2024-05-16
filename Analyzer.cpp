#include "Analyzer.h"
#include <string>
#include <iostream>

using namespace std;

Analyzer::Analyzer(int* pArr, int s) {
	size = s;
	pIntArray = cloneValues(pArr, size); // I guess just do this?
}

Analyzer::~Analyzer() {
	delete[] pIntArray;
	pIntArray = nullptr;
}

int* Analyzer::cloneValues(int* pIntArray, int size) {
	int* pCloneArray = new int[size];
	for (int i = 0; i < size; i++) {
		pCloneArray[i] = pIntArray[i];
	}

	return pCloneArray;
}

void Analyzer::selectionSort(int* values, int size) {

	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (values[j] < values[minIndex]) {
				minIndex = j;
			}
		}
		int temp = values[i];
		values[i] = values[minIndex];
		values[minIndex] = temp;
	}

}

// Helper to print array date members
void Analyzer::print() {
	for (int i = 0; i < size; i++) {
		cout << pIntArray[i] << " ";
	}
	cout << endl;
}