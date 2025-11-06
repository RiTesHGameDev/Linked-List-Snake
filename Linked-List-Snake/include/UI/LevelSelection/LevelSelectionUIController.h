#pragma once
#include <SFML/Graphics.hpp>
#include "../include/UI/Interface/IUIController.h"
#include "../include/UI/UIElement/ImageView.h"
#include "../include/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace LevelSelection
	{
		class LevelSelectionUIController:public Interface::IUIController
		{
		private:
			UIElement::ImageView* background_image;
			UIElement::ButtonView* level_one_button;
			UIElement::ButtonView* level_two_button;
			UIElement::ButtonView* menu_button;

			const float level_one_button_y_position = 500.f;
			const float levl_two_button_y_position = 700.f;
			const float menu_button_y_position = 900.f;

			const float button_width = 400.0f;
			const float button_height = 140.0f;

			const float background_alpha = 85.f;

			void createImage();
			void createButtons();

			void initializeButtons();
			void initializeBackgroundImage();
			float calculateLeftOffsetForButton();

			void singleLinkedListButtonCallback();
			void doubleLinkedListButtonCallback();
			void menuButtonCallback();

			void registerButtonCallback();

			void show();
			void destroy();
		public:
			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize();
			void update();
			void render();
		
		};
	}
}