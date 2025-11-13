#pragma once
#include "../include/Food/FoodItem.h"
#include <vector>
#include <random>

namespace Food
{
	class FoodService
	{
	private:
		FoodItem* current_food_item;

		std::default_random_engine random_engine;
		std::random_device random_device;

		float cell_width;
		float cell_height;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();
		void destroyFood();

		sf::Vector2i getRandomPosition();
		sf::Vector2i getValidSpawnPosition();
		FoodType getRandomFoodType();

		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}