#include "Controller.h"

Controller::Controller(Model &model, View &view) {
	this->model = &model;
	this->view = &view;
}

void Controller::SetModel(Model &model) {
	this->model = &model;
}

void Controller::SetView(View &view) {
	this->view = &view;
}

void Controller::OnLoad(void) {
	view->Render(4);
}

void Controller::Render(unsigned int numberOfPoints) {
	view->Render(numberOfPoints);
}