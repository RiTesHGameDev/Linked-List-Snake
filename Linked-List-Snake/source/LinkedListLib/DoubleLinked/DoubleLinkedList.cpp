#include <iostream>
#include "../include/LinkedListLib/DoubleLinked/DoubleLinkedList.h"
#include "../include/Level/LevelView.h"
#include "../include/Global/Config.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		Node* DoubleLinkedList::createNode()
		{
			return new DoubleNode();
		}

		DoubleLinkedList::DoubleLinkedList() = default;

		DoubleLinkedList::~DoubleLinkedList() = default;

		void DoubleLinkedList::insertNodeAtHead()
		{
			linked_list_size++;
			Node* new_node = createNode();

			if (head_node == nullptr)
			{
				new_node = head_node;
				static_cast<DoubleNode*>(new_node)->previous = nullptr;
				initializeNode(new_node, nullptr, Operation::HEAD);
				return;
			}
			
			initializeNode(new_node, head_node, Operation::HEAD);
			new_node->next = head_node;
			static_cast<DoubleNode*>(head_node)->previous = new_node;

			head_node = new_node;
		}

		void DoubleLinkedList::insertNodeAtMiddle()
		{

		}
	}
}