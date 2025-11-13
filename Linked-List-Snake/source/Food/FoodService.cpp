#include "../include/Food/FoodService.h"
#include "../include/Level/LevelService.h"
#include "../include/Global/ServiceLocator.h"
#include "../include/Level/LevelModel.h"
#include "../include/Time/TimeService.h"

namespace Food
{
	using namespace Level;
	using namespace Global;
	using namespace Time;

	FoodService::FoodService()
	{
		current_food_item = nullptr;
	}
	FoodService::~FoodService()
	{
		destroyFood();
	}
	void FoodService::initialize()
	{

	}
	void FoodService::update()
	{
		if (current_food_item)current_food_item->update();
	}
	void FoodService::render()
	{
		if (current_food_item)current_food_item->render();

	}
	void FoodService::startFoodSpawning()
	{
		cell_width = ServiceLocator::getInstance()->getLevelService()->getCellHeight();
		cell_height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		spawnFood();
	}
	FoodItem* FoodService::createFood(sf::Vector2i position, FoodType type)
	{
		FoodItem* food_item = new FoodItem();

		food_item->initialize(position, cell_width, cell_height, type);
		return food_item;
	}
	void FoodService::spawnFood()
	{
		current_food_item = createFood(sf::Vector2i(4, 6), FoodType::BURGER);
	}
	void FoodService::destroyFood()
	{
		if (current_food_item)delete(current_food_item);
	}
}