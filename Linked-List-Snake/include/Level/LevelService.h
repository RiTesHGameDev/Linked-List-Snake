#pragma once
#include "../include/Level/LevelConfig.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;
		LinkedListType current_linked_list_type;

		void createLevelController();
		void destroy();
		void spawnPlayer();
		void spawnFood();
		void spawnLevelElements(LevelNumber level_to_load);

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();

		void createLevel(LinkedListType linked_list_type);
		void setCurrentLevelNumber(LevelNumber level_to_load);
		LevelNumber getCurrentLevel();
		LinkedListType getCurrentLinkedListType();
	};
}