#pragma once
#include "IModel.h"
#include <string>

using namespace std;

class Model : public virtual IModel {
	string fileName;
public:
	virtual void GenerateData(void){
		// Stub function.
	}
	virtual bool NextData(double &) {
		return true;
	}
};