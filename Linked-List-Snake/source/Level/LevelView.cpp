#include <iostream>
#include "../include/Level/LevelView.h"
#include "../include/Global/ServiceLocator.h"

namespace Level
{
	using namespace Global;

	LevelView::LevelView()
	{
		createViews();
	}
	LevelView::~LevelView()
	{
		destroy();
	}
	void LevelView::createViews()
	{
		background_rectangle = new RectangleShapeView();
		border_ractangle = new RectangleShapeView();
	}
	void LevelView::initialize()
	{
		initializeBackground();
		calculateGridExtents();
		initializeBorder();
	}
	void LevelView::initializeBackground()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		sf::Vector2f background_size = sf::Vector2f(game_window->getSize().x, game_window->getSize().y);

		background_rectangle->initialize(background_size, sf::Vector2f(0, 0), 0, background_color));
		background_rectangle->show();
	}
	void LevelView::initializeBorder()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		sf::Vector2f border_size = sf::Vector2f(grid_width,grid_height);
		sf::Vector2f border_position = sf::Vector2f(border_left_offset, border_top_offset);

		border_ractangle->initialize(border_size, border_position, 
			border_thickness, sf::Color::Transparent, border_color);
		border_ractangle->show();
	}
	void LevelView::calculateGridExtents()
	{
		sf::RenderWindow& game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		grid_width = game_window.getSize().x - 2 * border_left_offset;
		grid_height = game_window.getSize().y - 2 * border_top_offset;
	}
	void LevelView::update()
	{
		background_rectangle->update();
		border_ractangle->update();
	}
	void LevelView::render()
	{
		background_rectangle->render();
		background_rectangle->render();
	}
	void LevelView::destroy()
	{
		delete(background_rectangle);
		delete(border_ractangle);
	}
	float LevelView::getGridWidth() { return grid_width; }
	float LevelView::getGridHeight() { return grid_height; }
}