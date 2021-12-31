#pragma once
#include "IView.h"
#include "Model.h"

class View : virtual public IView {
public:
	View(Model &model) {
		this->model = &model; 
	}
	void SetModel(Model &model) {
		// Allows model object to be changed
		this->model = &model;
	}
	void Render(unsigned int NoOfElements) {
		// Stub function.
	}
protected:
	Model* model;
};

