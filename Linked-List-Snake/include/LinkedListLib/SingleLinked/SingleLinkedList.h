#pragma once
#include <SFML/System/Vector2.hpp>
#include "../include/LinkedListLib/LinkedList.h"
#include "../include/LinkedListLib/Node.h"

namespace LinkedListLib
{
	namespace SingleLinkedList
	{
		class SingleLinkedList:public LinkedList
		{
		private:

			virtual Node* createNode()override;

		public:
			SingleLinkedList();
			~SingleLinkedList();

			void insertNodeAtTail() override;
			void insertNodeAtHead() override;
			void insertNodeAtMiddle() override;
			void insertNodeAtIndex(int index, Node* new_node);

			void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

			void removeNodeAtTail() override;
			void removeNodeAtHead() override;
			void removeNodeAtMiddle() override;
			void removeNodeAt(int index) override;
			void removeNodeAtIndex(int index);
			void removeAllNodes() override;
			void removeHalfNodes() override;

			void shiftNodesAfterRemoval(Node* cur_node);

			Direction reverse() override;
			void reverseNodeDirections();


		};
	}
}