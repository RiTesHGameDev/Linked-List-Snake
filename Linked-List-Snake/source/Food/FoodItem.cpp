#include "Food/FoodItem.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelView.h"
#include "Global/Config.h"
#include "Food/FoodType.h"

namespace Food
{
	using namespace Global;
	using namespace Level;
	using namespace UI::UIElement;

	FoodItem::FoodItem()
	{
		food_image = new ImageView();
	}

	FoodItem::~FoodItem()
	{
		delete (food_image);
	}

	void FoodItem::initialize(sf::Vector2i grid_pos, float width, float height, FoodType type)
	{
		grid_position = grid_pos;
		cell_width = width;
		cell_height = height;
		food_type = type;

		initializeFoodImage();
	}

	void FoodItem::initializeFoodImage()
	{
		sf::Vector2f screen_position = getFoodImagePosition();
		sf::String food_texture_path = getFoodTexturePath();

		food_image->initialize(food_texture_path, static_cast<float>(cell_width), static_cast<float>(cell_height), screen_position);
		food_image->setOriginAtCentre();
		food_image->setPosition(screen_position);

		food_image->show();
	}

	sf::String FoodItem::getFoodTexturePath()
	{
		switch (food_type)
		{
		case Food::FoodType::APPLE:
			return Config::apple_texture_path;

		case Food::FoodType::MANGO:
			return Config::mango_texture_path;

		case Food::FoodType::ORANGE:
			return Config::orange_texture_path;

		case Food::FoodType::PIZZA:
			return Config::pizza_texture_path;

		case Food::FoodType::BURGER:
			return Config::burger_texture_path;

		case Food::FoodType::CHEESE:
			return Config::cheese_texture_path;

		case Food::FoodType::POISION:
			return Config::poision_texture_path;

		case Food::FoodType::ALCOHOL:
			return Config::alcohol_texture_path;

		default:
			return "";
		}
	}

	void FoodItem::update()
	{
		food_image->update();
	}

	void FoodItem::render()
	{
		food_image->render();
	}

	FoodType FoodItem::getFoodType()
	{
		return food_type;
	}

	sf::Vector2i FoodItem::getFoodPosition()
	{
		return grid_position;
	}

	sf::Vector2f FoodItem::getFoodImagePosition()
	{
		float screen_position_x =
			LevelView::border_left_offset +
			(grid_position.x * cell_width) +
			(cell_width / 2.0f);

		float screen_position_y =
			LevelView::border_top_offset +
			(grid_position.y * cell_height) +
			(cell_height / 2.0f);


		return sf::Vector2f(screen_position_x, screen_position_y);
	}
}