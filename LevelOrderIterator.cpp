#ifndef LEVELORDERITERATOR_CPP
#define LEVELORDERITERATOR_CPP

#include "LevelOrderIterator.h"

namespace cs20 {

template <class Object>
LevelOrderIterator<Object>::LevelOrderIterator( const BinaryTree<Object> & theTree ) : BinaryTreeIterator<Object>( theTree ) {
	q.enqueue( this->root );
}

template <class Object>
LevelOrderIterator<Object>::~LevelOrderIterator() {

}

template <class Object>
void LevelOrderIterator<Object>::first( ) {
	q.makeEmpty();
	if (this->root != nullptr) {
		q.enqueue( this->root );
		advance();
	}
}


template <class Object>
void LevelOrderIterator<Object>::advance( ) {
	if (q.isEmpty()) {
		if (this->current == nullptr)
			throw BadIterator();
		this->current = nullptr;
	}
	else {
		this->current = q.dequeue();
		//if (current->leftSide != nullptr)
		//	q.enqueue( current->leftSide );
		//if (current->rightSide != nullptr) 
		//	q.enqueue( current->rightSide );
		if (this->current->getLeftSide() != nullptr)
			q.enqueue( this->current->getLeftSide() );
		if (this->current->getRightSide() != nullptr)
			q.enqueue( this->current->getRightSide() );
	}
}

}

#endif