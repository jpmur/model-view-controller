#pragma once
#include "SineData.h"
#include "Model.h"
#include "common.h"

class SineModel : public virtual Model{
	unsigned int currentSamplePosition;
	double currentValue;
	dblContainer dbl_pointers;
	SineParams waveformParams;
	SineWaveData sineData;
	shared_ptr<double> sharedDblPtr;
public:
	~SineModel();
	SineModel(SineParams theData);
	void GenerateData(void);
	bool NextData(double &value);
	string GetFileName(void);
	// Can't be members of class because left operator has to be type ostream/istream
	friend ostream &operator<<(ostream &stream, SineModel sineOb);  // Inserter 
	friend istream &operator>>(istream &stream, SineModel &sineOb); // Extractor
};