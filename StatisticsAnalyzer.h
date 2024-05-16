#pragma once

#include "Analyzer.h"
#include <string>

class StatisticsAnalyzer : public Analyzer {
public:
	StatisticsAnalyzer(int* pArr, int s);
	std::string analyze() override;
};

