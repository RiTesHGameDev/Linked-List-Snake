#pragma once

namespace Level
{
	class LevelController
	{
	private:
		Destroy();
	public:
		LevelController();
		~LevelController();

		void Initialize();
		void Update();
		void Render();
	};
}