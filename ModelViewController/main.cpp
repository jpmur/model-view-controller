#include "GaussianModel.h"
#include "SineModel.h"
#include "GaussianView.h"
#include "SineView.h"
#include "Controller.h"
#include <fstream>
using namespace std;


int main(void) {
	double dataValue = 0;

	GaussianParams aGaussian(5.0, 2.0, 100, "test.dat");  
	GaussianModel aGaussModel(aGaussian);  
	GaussianView aGaussView(aGaussModel); 
	aGaussModel.GenerateData();   

	cout << "-- Random Gaussian Data --" << endl;
	while (aGaussModel.NextData(dataValue))  
		cout << dataValue << endl;

	SineParams aSinewave(10, 1000, 0.0, 0.00001, 100, "test.dat");  
	SineModel aSineModel(aSinewave);

	aSineModel.GenerateData();

	cout << "-- Random Sine Data --" << endl;
	while (aSineModel.NextData(dataValue))   
		cout << dataValue << endl;

	ofstream foData("test.dat");  // create normal output file 

	if (!foData) 
	{ 
		foData << "Cannot open output file." << endl;
	}
	else 
	{ 
		foData << aSineModel;   foData.close(); 
	}    
	
	string file = aSineModel.GetFileName(); 
	ifstream fiData(file);    
	if (!fiData) 
	{
		cout << "Cannot open output file." << endl;
	}
	else
	{
		fiData >> aSineModel;   fiData.close(); 
	}

	cout << "-- Values extracted from file --" << endl;
	while (aSineModel.NextData(dataValue))  
		cout << dataValue << endl;    
	
	SineView aSineView(aSineModel);  
	Controller aController(aSineModel, aSineView);

	cout << "-- OnLoad() output --" << endl;
	aController.OnLoad();    
	cout << "---Render() output ---" << endl;;
	aController.Render(4); 

	aController.SetModel(aGaussModel);  
	aController.SetView(aGaussView);   
	cout << "-- Gaussian OnLoad() output --" << endl;
	aController.OnLoad();    
	cout << "-- Gaussian Render() output --" << endl;;
	aController.Render(23); 

	return 0;
}