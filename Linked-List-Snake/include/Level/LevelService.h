#pragma once
#include "../Level/LevelNumber.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void CreateLevelController();
		void Destroy();

	public:
		LevelService();
		~LevelService();

		void Initialize();
		void Update();
		void Render();

		void CreateLevel(LevelNumber level_to_load);
	};
}