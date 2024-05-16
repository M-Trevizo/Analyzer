#pragma once

#include <string>

class Analyzer {
public:
	Analyzer(int* pArr, int s);
	~Analyzer();
	virtual std::string analyze() = 0;
	void selectionSort(int* values, int size);
	void print();

protected:
	int* pIntArray;
	int size;

private:
	int* cloneValues(int* pIntArray, int size);
};
