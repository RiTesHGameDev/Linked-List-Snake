#pragma once
#include <SFML/System/Vector2.hpp>
#include "../include/LinkedListLib/LinkedList.h"
#include "../include/LinkedListLib/DoubleLinked/DoubleNode.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		class DoubleLinkedList:public LinkedList
		{
        protected:
            virtual Node* createNode() override;
		public:
			DoubleLinkedList();
			~DoubleLinkedList();
			
            virtual void insertNodeAtTail()override;
            virtual void insertNodeAtHead()override;
            virtual void insertNodeAtMiddle()override;
            virtual void insertNodeAtIndex(int index)override;

            void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

            virtual void removeNodeAtTail()override;
            virtual void removeNodeAtHead()override;
            virtual void removeNodeAtMiddle()override;
            virtual void removeNodeAt(int index)override;
            virtual void removeAllNodes()override;
            virtual void removeHalfNodes()override;

            void shiftNodesAfterRemoval(Node* cur_node);

            Direction reverse() override;
		};
	}
}