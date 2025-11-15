#pragma once
#include "../include/Food/FoodItem.h"
#include "../include/LinkedList/Node.h"
#include <vector>
#include <random>

namespace Food
{
	using namespace LinkedList;
	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};
	class FoodService
	{
	private:
		FoodItem* current_food_item;
		FoodSpawningStatus current_spawning_status;

		std::default_random_engine random_engine;
		std::random_device random_device;

		float cell_width;
		float cell_height;

		const float spawn_duration = 4.f;
		float elapsed_duration;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();
		
		sf::Vector2i getRandomPosition();
		sf::Vector2i getValidSpawnPosition();
		FoodType getRandomFoodType();

		bool isValidPosition(std::vector<sf::Vector2i> position_data,
			sf::Vector2i food_position);

		void reset();
		void updateElapsedDuration();
		void handleFoodSpawning();
		

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();
		void destroyFood();

		void startFoodSpawning();
		void stopFoodSpawning();

		bool processFoodCollision(Node* head_node, FoodType& out_food_type);
	};
}