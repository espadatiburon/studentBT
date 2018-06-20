#ifndef QUEUENODE_CPP
#define QUEUENODE_CPP

#include "QueueNode.h"

namespace cs20 {

template <class Object>
QueueNode<Object>::QueueNode( const Object& theElement,
								      QueueNode<Object> * node ) {
	element = theElement;
	next = node;
}

template <class Object>
const Object& QueueNode<Object>::getElement() const {
	return( element );
}

template <class Object>
QueueNode<Object>* QueueNode<Object>::getNext() const {
	return( next );
}

template <class Object>
void QueueNode<Object>::setNext( QueueNode<Object> * node ) {
	next = node;
}

template <class Object>
std::ostream& operator <<( std::ostream& outs, const QueueNode<Object> * node ) {
	if (node == nullptr) {
		outs << "Empty Queue";
	}
	else {
		QueueNode<Object> current = *node;
		// yucky loop, but I did not want to build a
		// constructor, destructor and equal operator
		// for a QueueNode
		while( true ) {
			Object o = current.element;
			outs << o << " ";
			if (current.next == nullptr)
				break;
			else
				current = *(current.next);
		}
	}
	outs << std::endl;
	return( outs );
}

}

#endif