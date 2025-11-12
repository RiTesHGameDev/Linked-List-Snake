#include <iostream>
#include "../include/Level/LevelModel.h"
#include "../include/Element/ElementService.h"

namespace Level
{
	using namespace Element;

	LevelModel::LevelModel() = default;

	LevelModel::~LevelModel() = default;

	void LevelModel::initialize(int width,int height)
	{
		cell_width = width / number_of_columns;
		cell_height = height / number_of_rows;

		initializeLevelData();
	}

	void LevelModel::update()
	{

	}

	void LevelModel::render()
	{

	}

	void LevelModel::initializeLevelData()
	{
		level_configurations.push_back(LevelData(LevelNumber::ONE, &level_one_element_list));
		level_configurations.push_back(LevelData(LevelNumber::TWO, &level_two_element_list));
	}

	const std::vector<ElementData>& LevelModel::getElemenetDataList(int level_to_load)
	{
		return *level_configurations[level_to_load].element_data_list;
	}

	float LevelModel::getCellWidth() { return cell_width; }

	float LevelModel::getCellHeight() { return cell_height; }
}