#pragma once

#include "Analyzer.h"
#include <string>

class SearchAnalyzer : public Analyzer {
public:
	SearchAnalyzer(int* values, int size);
	std::string analyze() override;
	bool binarySearch(int* values, int toFind, int size);

private:
	bool binarySearchRecursive(int* values, int toFind, int start, int end);
};

