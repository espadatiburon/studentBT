#ifndef PREORDERITERATOR_CPP
#define PREORDERITERATOR_CPP

#include "PreOrderIterator.h"

namespace cs20 {

template <class Object>
PreOrderIterator<Object>::PreOrderIterator( const BinaryTree<Object> & theTree ) : BinaryTreeIterator<Object>( theTree ) {
	q.enqueue( this->root );
}

template <class Object>
PreOrderIterator<Object>::~PreOrderIterator() {

}

template <class Object>
void PreOrderIterator<Object>::advance()
{
	if (q.isEmpty()) {
		if (this->current == nullptr)
			throw BadIterator();
		this->current = nullptr;
	}
	else {
		this->current = q.dequeue();
	}
}

template <class Object> 
void PreOrderIterator<Object>::queueAll()
{
	if(this->current == nullptr)
		throw BadIterator();
	queueAll(this->current);
}

template <class Object>
void PreOrderIterator<Object>::queueAll(const BinaryTreeNode<Object>* node)
{
	if(node->getLeftSide() != nullptr)
	{
		q.enqueue(node->getLeftSide());
		queueAll(node->getLeftSide());
	}
	if(node->getRightSide() != nullptr)
	{
		q.enqueue(node->getRightSide());
		queueAll(node->getRightSide());
	}
}

template <class Object>
void PreOrderIterator<Object>::first()
{
	q.makeEmpty();
	if (this->root != nullptr) 
	{
		q.enqueue( this->root );
		advance();
	}
}

}

#endif