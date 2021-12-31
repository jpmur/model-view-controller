#include "GaussianView.h"
#include <iostream>

using namespace std;

GaussianView::GaussianView(Model &model) : View(model) // Pass model reference to base class (View) constructor
{
	cout << "GaussianView Constructor" << endl;
	// GaussianView Constructor - no functionaility except passing argument to base class constructor
}

GaussianView::~GaussianView()
{
	// GaussianView Destructor - dummy
}

void GaussianView::Render(unsigned int numberOfElements) 
{
	double value;
	int index = 0;
	bool keepGoing = true;					// Flag to check if required number of vlaues have been rendered
	/*Keep rendering values before the end of vector is reached and
	  while the the user defined number of values to display has not been surpassed*/
	while (keepGoing = true && index < numberOfElements) 
	{
		keepGoing = model->NextData(value); // Return type of NextData() is a bool which sets the keepGoing flag
		cout << value << endl;
		index++;
	}
}