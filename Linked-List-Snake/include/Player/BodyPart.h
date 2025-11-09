#pragma once
#include <SFML//Graphics.hpp>
#include "../include/UI/UIElement/ImageView.h"
#include "../include/Player/Direction.h"

namespace Player
{
	using namespace UI;
	using namespace UIElement;

	class BodyPart
	{
	private:
		ImageView* bodypart_image;
		sf::Vector2i grid_position;

		Direction direction;

		float bodypart_width;
		float bodypart_height;
	};
}