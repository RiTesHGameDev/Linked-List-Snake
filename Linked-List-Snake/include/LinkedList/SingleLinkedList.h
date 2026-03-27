#pragma once
#include <SFML/System/Vector2.hpp>
#include "../include/LinkedList/Node.h"

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};
	class SingleLinkedList
	{
	private:
		Node* head_node;

		int linked_list_size;
		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();
		
		int findMiddleNode();

		

		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		Direction getReverseDirection(Direction reference_direction);
	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();

		void insertNodeAtHead();
		void insertNodeAtTail();
		void insertNodeAtIndex(int index);
		void insertNodeAtMiddle();
		void shiftNodesAfterInsertion(Node* new_node, Node* reference_node, Node* prev_node);

		void removeNodeAtHead();
		void removeNodeAtTail();
		void removeNodeAtMiddle();
		void removeNodeAt(int index);
		void removeNodeAtIndex(int index);
		void shiftNodesAfterRemoval(Node* cur_node);

		Node* findNodeAtIndex(int index);

		void removeHalfNodes();
		Direction reverse();
		void reverseNodeDirections();	

		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeAllNodes();

		Node* getHeadNode();
		std::vector<sf::Vector2i> getNodesPositionList();

		
	};
}