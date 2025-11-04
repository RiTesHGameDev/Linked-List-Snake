#pragma once

namespace Level
{
	class LevelModel
	{
	private:
		Destroy();
	public:
		LevelModel();
		~LevelModel();

		void Initialize();
		void Update();
		void Render();
	};
}