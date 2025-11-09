#include "../include/LinkedList/SingleLinkedList.h"
#include "../include/Player/BodyPart.h"
#include "../include/Level/LevelView.h"

namespace LinkedList
{
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}
	SingleLinkedList::~SingleLinkedList() = default;

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}
	void SingleLinkedList::render() {}

	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}
}