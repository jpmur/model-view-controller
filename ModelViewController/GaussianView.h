#pragma once
#include "View.h"

class GaussianView : virtual public View {
public:
	GaussianView(Model &model);
	~GaussianView();
	void Render(unsigned int numberOfElements);
};
