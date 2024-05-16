#pragma once

#include "Analyzer.h"
#include <string>

class MissingAnalyzer : public Analyzer {
public:
	MissingAnalyzer(int* pArr, int size);
	std::string analyze() override;
};

