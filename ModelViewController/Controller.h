#pragma once
#include "Model.h"
#include "View.h"

class Controller{
	Model* model;
	View* view;
public:
	Controller(Model &model, View &view);
	void SetModel(Model &model);
	void SetView(View &view);
	void OnLoad(void);
	void Render(unsigned numberOfPoints);
};