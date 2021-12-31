#include "GaussianModel.h"
#include <random>

using namespace std;


GaussianParams::GaussianParams(double amplitude = 0.0, double stdDev = 0.0, unsigned int NumberOfPoints = 0, string filename = "")
{
	this->amplitude = amplitude;
	this->stdDev = stdDev;
	this->NumberOfPoints = NumberOfPoints;
	this->fileName = fileName;
}


GaussianModel::~GaussianModel() {
	// Dummy Destructor
}

GaussianModel::GaussianModel(const GaussianParams randomParams) {
	this->randomParams = randomParams;
}

void GaussianModel::GenerateData() {

	// Set up Gaussian RNG
	default_random_engine generator;
	normal_distribution<double> distribution(randomParams.amplitude, randomParams.stdDev);

	/* Allows the same code to re-assign a smart shared_ptr object with different data 
       and assign to the STL smart shared_ptr vector*/
	sharedDblPtr = make_shared<double>(randomParams.NumberOfPoints);

	//  Populate vector with Gaussian values
	for (currentSamplePosition = 0; currentSamplePosition < randomParams.NumberOfPoints; currentSamplePosition++) 
	{
		double GaussianNumber = distribution(generator);	// Generate Gaussian value
		sharedDblPtr.reset(new double(GaussianNumber));		// Allow the shared pointer to be reassigned to a new smart pointer.
		randomData.push_back(sharedDblPtr);					// Add the new element to the vector after the last element
	}

	dbl_pointers = randomData;
	// Reset the vector index after it is populated
	currentSamplePosition = 0;
	currentValue = *randomData[currentSamplePosition];
}

bool GaussianModel::NextData(double &value) {
	dblIterator ptr = dbl_pointers.begin();
	if (currentSamplePosition == dbl_pointers.size())		// If end of vector reached
	{
		currentSamplePosition = 0;
		currentValue = *dbl_pointers[currentSamplePosition];
		return false;   
	}
	else													// If not end of vector
	{
		advance(ptr, currentSamplePosition);			// Advance the 'ptr' iterator
		currentValue = **ptr;							// Assign current value equals to dereferenced value pointed to by 'ptr'
		value = currentValue;
		currentSamplePosition++;
		return true;	
	}

}