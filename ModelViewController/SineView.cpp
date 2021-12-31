#pragma once
#include "SineView.h"
#include <iostream>

using namespace std;

SineView::SineView(Model &model) : View(model)
{
	cout << "SineView Constructor" << endl;
	// SineView Constructor - no functionaility except passing argument to base class constructor
}

SineView::~SineView() {
	// SineView Destructor - dummy
}

void SineView::Render(unsigned int numberOfElements) {
	double value;
	int index = 0;
	bool keepGoing = true;		// Flag to check if required number of vlaues have been rendered
	/*Keep rendering values before the end of vector is reached and
      while the the user defined number of values to display has not been surpassed*/
	while (keepGoing = true && index < numberOfElements)
	{
		keepGoing = model->NextData(value);	// Return type of NextData() is a bool which sets the keepGoing flag
		cout << value << endl;
		index++;
	}
}