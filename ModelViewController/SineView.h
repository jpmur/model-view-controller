#pragma once
#include "View.h"

class SineView : virtual public View {
public:
	SineView(Model &model);
	~SineView();
	void Render(unsigned int numberOElements);
};
