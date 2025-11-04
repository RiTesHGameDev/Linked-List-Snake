#include "../../../Include/Level/LevelService.h"
#include "../../../Include/Level/LevelController.h"

namespace Level
{
	using namespace Global;

	LevelService::LevelService()
	{
		level_controller = nullptr;
		CreateLevelController();
	}
	LevelService::~LevelService()
	{
		Destroy();
	}
	void LevelService::CreateLevelController()
	{
		level_controller = new LevelController();
	}
	void LevelService::Initialize()
	{
		level_controller->Initialize();
	}
	void LevelService::Update()
	{
		level_controller->Update();
	}
	void LevelService::Render()
	{
		level_controller->Render();
	}
	void LevelService::CreateLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
	}
	void LevelService::Destroy()
	{
		delete level_controller;
	}
}