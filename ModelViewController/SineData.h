#pragma once
#include <vector>
#include <string>

using namespace std;

struct SineParams {
	double amplitude;
	double stdDev;
	double frequency;
	double phase;
	double samplingTime;
	unsigned int NumberOfPoints;
	string fileName;

	SineParams(double amplitude, double frequency, double phase, double samplingTime, unsigned int NumberOfPoints, string fileName);
};

typedef vector< shared_ptr<double> > SineWaveData;


