#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/RectangleShapeView.h"

namespace Level
{
	using namespace UI;
	using namespace UIElement;

	class LevelView
	{
	private:
		const sf::Color border_color = sf::Color::Black;
		const sf::Color background_color = sf::Color(180, 200, 160);

		RectangleShapeView* background_rectangle;
		RectangleShapeView* border_ractangle;

		float grid_width;
		float grid_height;

		void createViews();
		void initializeBackground();
		void initializeBorder();
		void calculateGridExtents();
		void destroy();

	public:
		static const int border_thickness = 10;
		static const int border_left_offset = 40;
		static const int border_top_offset = 40;

		LevelView();
		~LevelView();

		void initialize();
		void update();
		void render();

		float getGridWidth();
		float getGridHeight();
	};
}