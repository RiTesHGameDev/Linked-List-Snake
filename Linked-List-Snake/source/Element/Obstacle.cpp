#include "../include/Element/Obstacle.h"
#include "../include/Global/Config.h"
#include "../include/Level/LevelView.h"

namespace Element
{
	using namespace Global;
	using namespace Level;

	Obstacle::Obstacle()
	{
		obstacle_image = new ImageView();
	}
	Obstacle::~Obstacle()
	{
		destroy();
	}
	void Obstacle::initialize(sf::Vector2i grid_pos, float width, float height)
	{
		grid_position = grid_pos;
		cell_width = width;
		cell_height = height;

		initializeObstacleImage();
	}
	void Obstacle::initializeObstacleImage()
	{
		sf::Vector2f screen_position = getObstacleImagePosition();
		obstacle_image->initialize(Config::obstacle_texture_path, cell_width, cell_height, screen_position);
		obstacle_image->show();
	}
	sf::Vector2f Obstacle::getObstacleImagePosition()
	{
		float screen_position_x = LevelView::border_left_offset + (cell_width * grid_position.x);
		float screen_position_y = LevelView::border_top_offset + (cell_height * grid_position.y);
		return sf::Vector2f(screen_position_x, screen_position_y);
	}
	void Obstacle::update()
	{
		obstacle_image->update();
	}
	void Obstacle::render()
	{
		obstacle_image->render();
	}
	sf::Vector2i Obstacle::getObstaclePosition()
	{
		return grid_position;
	}
	void Obstacle::destroy()
	{
		delete (obstacle_image);
	}
}