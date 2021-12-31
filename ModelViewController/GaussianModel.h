#pragma once
#include "Model.h"
#include "GaussianData.h"
#include "common.h"

class GaussianModel : public virtual Model{
	unsigned int currentSamplePosition;
	double currentValue;
	dblContainer dbl_pointers;
	GaussianData randomData;
	GaussianParams randomParams;
	shared_ptr<double> sharedDblPtr;

public:
	GaussianModel(const GaussianParams randomParams);
	~GaussianModel();
	void GenerateData(void);
	bool NextData(double &);
};