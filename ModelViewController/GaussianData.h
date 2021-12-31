#pragma once
#include <vector>
#include <string>

using namespace std;

struct GaussianParams {
	double amplitude;
	double stdDev;
	unsigned int NumberOfPoints;
	string fileName;
	GaussianParams(double amplitude, double stdDev, unsigned int NumberOfPoints, string fileName);
};

typedef vector< shared_ptr<double> > GaussianData;
