#pragma once

#include "Analyzer.h"
#include <string>

class DuplicatesAnalyzer : public Analyzer {
public:
	DuplicatesAnalyzer(int* pArr, int size);
	std::string analyze() override;
};

