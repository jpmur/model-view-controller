#pragma once

class IModel {
public:
	// Pure virtual functions
	virtual void GenerateData(void) = 0;
	virtual bool NextData(double &) = 0;
};
