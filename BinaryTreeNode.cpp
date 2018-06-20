#ifndef BINARYTREENODE_CPP
#define BINARYTREENODE_CPP

#include "BinaryTreeNode.h"

namespace cs20 {

template <class Object>
BinaryTreeNode<Object>::BinaryTreeNode( const Object& theElement,
                                        BinaryTreeNode<Object> * theLeftSide,
                                        BinaryTreeNode<Object> * theRightSide ) {
	element = theElement;
	rightSide = theRightSide;
	leftSide = theLeftSide;
}

template <class Object>
int BinaryTreeNode<Object>::size( BinaryTreeNode<Object> * node ) {
	if (node == nullptr ) 
		return( 0 );
	else
		return( 1 + size( node->rightSide ) + size( node->leftSide ) );
}

template <class Object>
int BinaryTreeNode<Object>::height( BinaryTreeNode<Object> * node ) {
	if (node == nullptr ) 
		return( -1 );
	else
		return( 1 + std::max( height( node->leftSide ), height( node->rightSide ) ) );
}

template <class Object>
BinaryTreeNode<Object> * BinaryTreeNode<Object>::duplicate( ) const {
	BinaryTreeNode<Object> * newNode = new BinaryTreeNode<Object>( element );
	if (rightSide != nullptr) {
		newNode->rightSide = rightSide->duplicate();
	}
	if (leftSide != nullptr) {
		newNode->leftSide = leftSide->duplicate();
	}
	return( newNode );
}

template <class Object>
const Object& BinaryTreeNode<Object>::getElement() const {
	return( element );
}

template <class Object>
BinaryTreeNode<Object>* BinaryTreeNode<Object>::getLeftSide() const {
	return( leftSide );
}

template <class Object>
BinaryTreeNode<Object>* BinaryTreeNode<Object>::getRightSide() const {
	return( rightSide );
}

template <class Object>
void BinaryTreeNode<Object>::setLeftSide( BinaryTreeNode<Object>* node ) {
	leftSide = node;
}

template <class Object>
void BinaryTreeNode<Object>::setRightSide( BinaryTreeNode<Object>* node ) {
	rightSide = node;
}

}
#endif