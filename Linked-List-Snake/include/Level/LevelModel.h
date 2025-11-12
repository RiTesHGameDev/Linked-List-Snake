#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Level/LevelData.h"

namespace Level
{
	using namespace Element;
	class LevelModel
	{
	private:
		std::vector<LevelData> level_configuration;

		float cell_width;
		float cell_height;

		std::vector<ElementData> level_one_element_list;
		std::vector<ElementData> level_two_element_list;
		std::vector<LevelData> level_configurations;

		void initializeLevelData();
	public:
		static const int number_of_rows = 28;
		static const int number_of_columns = 50;

		LevelModel();
		~LevelModel();

		void initialize(int width,int height);
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();

		const std::vector<ElementData>& getElemenetDataList(int level_to_load);
	};
}