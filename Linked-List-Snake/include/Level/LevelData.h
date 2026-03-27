#pragma once
#include "Level/LevelNumber.h"
#include "../include/Element/ElementData.h"

namespace Level
{
	using namespace Element;

	struct LevelData
	{
		LevelData(LevelNumber ind,std::vector<ElementData>* data_list)
		{
			level_index = ind;
			element_data_list = data_list;
		}
		LevelNumber level_index;
		std::vector<ElementData>* element_data_list;
	};
}