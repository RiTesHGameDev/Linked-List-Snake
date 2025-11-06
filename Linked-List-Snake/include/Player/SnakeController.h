#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	class SnakeController
	{
	private:
		void destroy();
	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();
	};
}