#include "../include/Player/SnakeController.h"
#include "../include/Global/ServiceLocator.h"
#include "../include/Level/LevelService.h"

namespace Player
{
	using namespace Global;
	using namespace LinkedList;
	using namespace Level;

	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		createLinkedList();
	}
	SnakeController::~SnakeController()
	{
		destroy();
	}
	void SnakeController::initialize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width, height, default_position, default_direction);
	}
	
	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case Player::SnakeState::ALIVE:
			processPlayerInput();
			updateSnakeDirection();
			processSnakeCollision();
			moveSnake();
			break;
		case Player::SnakeState::DEAD:
			handleRestart();
			break;
		default:
			break;
		}
	}
	void SnakeController::render()
	{
		single_linked_list->render();
	}
	void SnakeController::processPlayerInput() 
	{

	}
	void SnakeController::updateSnakeDirection()
	{

	}
	void SnakeController::moveSnake()
	{

	}
	void SnakeController::processSnakeCollision()
	{

	}
	void SnakeController::handleRestart()
	{

	}
	void SnakeController::reset()
	{

	}
	void SnakeController::spawnSnake()
	{
		single_linked_list->createHeadNote();
	}
	void SnakeController::respawnSnake()
	{

	}
	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}
	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}
	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}
	void SnakeController::destroy()
	{
		delete(single_linked_list);
	}
}