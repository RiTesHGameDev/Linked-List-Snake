#pragma once
#include "../include/Element/ElementData.h"
#include "../include/Element/Obstacle.h"
#include <vector>

namespace Element
{
	class ElementService
	{
	private:
		std::vector<Obstacle*> obstacle_list;

		void spawnObstacle(sf::Vector2i position, 
			float cell_width, float cell_height);
		
	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();

		const void spawnElements(std::vector<ElementData>& element_data_list,
			float cell_width, float cell_height);

		std::vector<sf::Vector2i> getElementsPositionList();
	};
}