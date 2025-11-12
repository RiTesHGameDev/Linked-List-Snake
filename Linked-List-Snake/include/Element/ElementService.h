#pragma once
#include "../include/Element/ElementData.h"

namespace Element
{
	class ElementService
	{
	private:
		void destroy();
	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();
	};
}