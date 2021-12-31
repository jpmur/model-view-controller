#include "SineModel.h"
#define _USE_MATH_DEFINES
#include <math.h>

SineParams::SineParams(double amplitude=1.0, double frequency=1.0, double phase=1.0, double samplingTime=1.0, unsigned int NumberOfPoints=100, string fileName = "test.dat") {
	this->amplitude = amplitude;
	this->frequency = frequency;
	this->phase = phase;
	this->samplingTime = samplingTime;
	this->NumberOfPoints = NumberOfPoints;
	this->fileName = fileName;
}

SineModel::SineModel(SineParams theData) {
	this->waveformParams = theData;		// Initialise member data
}

SineModel::~SineModel() {
	// Dummy Destructor
}

void SineModel::GenerateData(void) {

	for (currentSamplePosition = 0; currentSamplePosition < waveformParams.NumberOfPoints; ++currentSamplePosition)
	{
		/* Generate sine values using class parameters.
		   Sampling time is multiplied by 'currentSamplePosition' to advance sine wave in time*/
		double SineValue = waveformParams.amplitude * sin(2 * M_PI * waveformParams.frequency * (waveformParams.samplingTime*currentSamplePosition)) + waveformParams.phase;
		sharedDblPtr.reset(new double(SineValue));  // Allow the shared pointer to be reassigned to a new smart pointer.
		sineData.push_back(sharedDblPtr);			// Add the new element to the vector after the last element
	}
	dbl_pointers = sineData;
	// Reset the vector index after it is populated
	currentSamplePosition = 0;
	currentValue = *sineData[currentSamplePosition];
}

bool SineModel::NextData(double &value) {
	dblIterator ptr = dbl_pointers.begin();
	if (currentSamplePosition == dbl_pointers.size())	// If end of vector reached
	{
		currentSamplePosition = 0;
		currentValue = *dbl_pointers[currentSamplePosition];
		return false;								
	}
	else                                                // If not end of vector
	{
		advance(ptr, currentSamplePosition);			// Advance the 'ptr' iterator
		currentValue = **ptr;							// Assign current value equals to dereferenced value pointed to by 'ptr'
		value = currentValue;	
		currentSamplePosition++;
		return true;									
	}
}

string SineModel::GetFileName(void) {
	return waveformParams.fileName;
}

// Inserter
ostream &operator<<(ostream &stream, SineModel sineOb) {
	for (int i = 0; i < sineOb.waveformParams.NumberOfPoints; i++)
	{
		// Output elements of vector to stream
		stream << *sineOb.sineData[i] << endl;
	}
	return stream;		
}

// Extractor
istream &operator>>(istream &stream, SineModel &sineOb) {
	string str;
	int index = 0;
	/*Extract lines from file and assign to 'str' variable*/
	while (getline(stream, str) && (index < sineOb.waveformParams.NumberOfPoints)) 
	{
		// Populate vector with each line converted to a double.
		*sineOb.sineData[index++] = stod(str.c_str()); 
	}
	return stream;
}