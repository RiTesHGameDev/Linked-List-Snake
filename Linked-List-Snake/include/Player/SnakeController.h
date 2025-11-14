#pragma once
#include <SFML/Graphics.hpp>
#include "../include/Player/Direction.h"
#include "../include/LinkedList/SingleLinkedList.h"
#include "../include/Food/FoodType.h"

namespace Player
{
	using namespace LinkedList;
	using namespace Food;

	enum class InputState
	{
		WAITING,
		PROCESSING
	};
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};
	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		SnakeState current_snake_state;

		//direction properties
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;

		//LinkedList
		SingleLinkedList* single_linked_list;

		//delayed update or Snake speed
		float elapsed_duration;
		const float movement_frame_duration = 0.1f;

		//reset
		const float restart_duration = 2.0f;
		float restart_counter;

		//InputState Properties
		InputState current_input_state;

		void delayedUpdate();
		void createLinkedList();

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();

		void processSnakeCollision();
		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();

		void onFoodCollected(FoodType food_type);

		void handleRestart();
		void reset();
		void destroy();
	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}