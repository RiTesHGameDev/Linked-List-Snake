#pragma once
#include <SFML/Graphics.hpp>
#include "../include/Player/SnakeController.h"
#include <Level/LevelConfig.h>

namespace Player
{
	using namespace Level;

	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
		void destroy();
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer(LinkedListType level_type);

		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		int getPlayerScore();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
	};
}