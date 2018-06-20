#ifndef BINARYTREEITERATOR_CPP
#define BINARYTREEITERATOR_CPP

#include "BinaryTreeIterator.h"

namespace cs20 {

template <class Object>
BinaryTreeIterator<Object>::BinaryTreeIterator( const BinaryTree<Object> & theTree ) : root( theTree.root ) , current( nullptr ) {
//	all assignments performed thru code above
}

template <class Object>
BinaryTreeIterator<Object>::~BinaryTreeIterator() {

}

template <class Object>
bool BinaryTreeIterator<Object>::isValid( ) const {
	return( (current != nullptr) );
}


template <class Object>
const Object& BinaryTreeIterator<Object>::retrieve( ) const {
	if (!(isValid())) throw BadIterator();
	return( current->getElement() );
}

}

#endif