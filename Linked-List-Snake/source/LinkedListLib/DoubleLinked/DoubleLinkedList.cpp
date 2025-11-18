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
	}
}