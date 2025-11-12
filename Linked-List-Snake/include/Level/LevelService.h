#pragma once
#include "../include/Level/LevelNumber.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void createLevelController();
		void destroy();
		void spawnPlayer();
		void spawnLevelElements(LevelNumber level_to_load);

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();

		void createLevel(LevelNumber level_to_load);
	};
}