#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelService.h"
#include "Event/EventService.h"
#include <iostream>

namespace Player
{
	using namespace LinkedListLib::SingleLinked;
	using namespace LinkedListLib::DoubleLinked;
	using namespace Global;
	using namespace Level;
	using namespace Event;
	using namespace Time;
	using namespace Sound;
	using namespace Element;
	using namespace Food;

	SnakeController::SnakeController()
	{
		linked_list = nullptr;

		movement_frame_duration = 0.1f;
		normal_movement_speed = movement_frame_duration;
		boosted_movement_speed = normal_movement_speed * 0.4f;
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initializeLinkedList()
	{
		if (linked_list == nullptr)
		{
			return;
		}
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		reset();
		linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::createLinkedList(LinkedListType level_type)
	{
		switch (level_type)
		{
		case Level::LinkedListType::SINGLE_LINKED_LIST:
			linked_list = new SingleLinkedList();
			break;
		case Level::LinkedListType::DOUBLE_LINKED_LIST:
			linked_list = new DoubleLinkedList();
			break;
		default:
			linked_list = nullptr;
			break;
		}
		if (linked_list != nullptr)
		initializeLinkedList();
	}

	void SnakeController::initialize()
	{
		if (linked_list == nullptr)
		{
			createLinkedList(Level::LinkedListType::SINGLE_LINKED_LIST);
		}
	}

	void SnakeController::update()
	{
		handleSpeedBoostTimer();

		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		if (linked_list == nullptr) return;
		linked_list->render();
	}

	void SnakeController::processPlayerInput()
	{
		if (current_input_state == InputState::PROCESSING)
			return;

		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			current_input_state = InputState::PROCESSING;
		}
	}

	void SnakeController::delayedUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollision();

			if (current_snake_state != SnakeState::DEAD)
				moveSnake();
			current_input_state = InputState::WAITING;
		}
	}

	void SnakeController::handleSpeedBoostTimer()
	{
		if (!speed_boost_active) return;

		speed_boost_timer += ServiceLocator::getInstance()
			->getTimeService()->getDeltaTime();

		if (speed_boost_timer >= speed_boost_duration)
		{
			movement_frame_duration = normal_movement_speed;
			speed_boost_active = false;
			speed_boost_timer = 0.f;
		}
	}

	float SnakeController::speedBoost()
	{
		movement_frame_duration = boosted_movement_speed;
		return movement_frame_duration;
	}

	void SnakeController::updateSnakeDirection()
	{
		if (linked_list == nullptr) return;
		linked_list->updateNodeDirection(current_snake_direction);
	}

	void SnakeController::moveSnake()
	{
		if (linked_list == nullptr) return;
		linked_list->updateNodePosition();
	}

	void SnakeController::processSnakeCollision()
	{
		processBodyCollision();
		processElementsCollision();
		processFoodCollision();
	}

	void SnakeController::processBodyCollision()
	{
		if (linked_list == nullptr) return;
		if (linked_list->processNodeCollision())
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}

	void SnakeController::processElementsCollision()
	{
		ElementService* element_service = ServiceLocator::getInstance()->getElementService();

		if (element_service->processElementsCollision(linked_list->getHeadNode()))
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}

	void SnakeController::processFoodCollision()
	{
		FoodService* food_service = ServiceLocator::getInstance()->getFoodService();
		FoodType food_type;

		if (food_service->processFoodCollision(linked_list->getHeadNode(), food_type))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);

			food_service->destroyFood();
			OnFoodCollected(food_type);

			player_score++;
		}
	}

	void SnakeController::OnFoodCollected(FoodType food_type)
	{
		switch (food_type)
		{
		case FoodType::PIZZA:
			//Insert at TAIL
			linked_list->insertNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_TAIL;
			break;

		case FoodType::BURGER:
			//Insert at HEAD
			linked_list->insertNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_HEAD;
			break;

		case FoodType::CHEESE:
			//Insert at MIDDLE
			linked_list->insertNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_MID;
			break;

		case FoodType::APPLE:
			//Delete at HEAD
			linked_list->removeNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_HEAD;
			break;

		case FoodType::MANGO:
			//Delete at MIDDLE
			linked_list->removeNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_MID;
			break;

		case FoodType::ORANGE:
			//Delete at TAIL
			linked_list->removeNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_TAIL;
			break;

		case FoodType::POISION:
			//Delete half nodes
			linked_list->removeHalfNodes();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::DELETE_HALF_LIST;
			break;

		case FoodType::ALCOHOL:
			//Reverse Direction
			linked_list->reverse();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REVERSE_LIST;
			break;

		case FoodType::ENERGY_DRINK:
			//Speed Boost
			speedBoost();
			speed_boost_active = true;
			speed_boost_timer = 0.f;
			slogan = Slogan::TURBO_SPEED;
			break;

		}
	}

	void SnakeController::handleRestart()
	{
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++)
		{
			linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
		player_score = 0;
		current_input_state = InputState::WAITING;
		time_complexity = TimeComplexity::NONE;
		last_linked_list_operation = LinkedListOperations::NONE;

		movement_frame_duration = normal_movement_speed;
		speed_boost_active = false;
		speed_boost_timer = 0.f;
	}

	void SnakeController::respawnSnake()
	{
		linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	bool SnakeController::isSpeedBoostActive()
	{
		return speed_boost_active;
	}

	int SnakeController::getPlayerScore()
	{
		return player_score;
	}

	bool SnakeController::isSnakeDead()
	{
		return current_snake_state == SnakeState::DEAD;
	}

	TimeComplexity SnakeController::getTimeComplexity()
	{
		return time_complexity;
	}

	LinkedListOperations SnakeController::getLastOperation()
	{
		return last_linked_list_operation;
	}

	Slogan SnakeController::getSlogan()
	{
		return slogan;
	}


	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		if (linked_list == nullptr) return std::vector<sf::Vector2i>();
		return linked_list->getNodesPositionList();
	}

	void SnakeController::destroy()
	{
		delete (linked_list);
		linked_list = nullptr;
	}
}