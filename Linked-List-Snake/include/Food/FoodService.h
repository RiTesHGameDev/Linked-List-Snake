#pragma once
#include "../include/Food/FoodItem.h"
#include <vector>

namespace Food
{
	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();
		void destroyFood();
	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}