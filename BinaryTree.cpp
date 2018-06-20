#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include "BinaryTree.h"

namespace cs20 {

template <class Object>
BinaryTree<Object>::BinaryTree() {
	root = nullptr;
}

template <class Object>
BinaryTreeNode<Object> * BinaryTree<Object>::getRoot() const {
	return( root );
}

template <class Object>
BinaryTree<Object>::BinaryTree( const BinaryTree<Object>& rhs ) {
	root = nullptr;
	*this = rhs;
}

template <class Object>
BinaryTree<Object>::BinaryTree( const Object& rootElement ) {
	root = new BinaryTreeNode<Object>( rootElement );
}

template <class Object>
BinaryTree<Object>::~BinaryTree() {
	makeEmpty();
}

template <class Object>
bool BinaryTree<Object>::isEmpty() const {
	return( root == nullptr );
}

template <class Object>
void BinaryTree<Object>::makeEmpty() {
	makeEmpty( root );
}

template <class Object>
void BinaryTree<Object>::makeEmpty( NodePtr & node ) {
	if (node != nullptr) {
		NodePtr r = node->getRightSide();
		NodePtr l = node->getLeftSide();

		if (r != nullptr)
			makeEmpty( r );
		if (l != nullptr)
			makeEmpty( l );
		delete node;
		node = nullptr;
	}
}

template <class Object>
int BinaryTree<Object>::size() const {
	return( BinaryTreeNode<Object>::size( root ) );
}

template <class Object>
int BinaryTree<Object>::height() const {
	return( BinaryTreeNode<Object>::height( root ) );
}

template <class Object>
void BinaryTree<Object>::setRightSide( BinaryTree& theRightSide ) {
	if (theRightSide.root == nullptr)
		throw( InvalidTreeArgument() );
	BinaryTreeNode<Object> *child = new BinaryTreeNode<Object>( theRightSide.root->getElement(), 
																theRightSide.root->getLeftSide(),
																theRightSide.root->getRightSide() );
	root->setRightSide( child );
	if (child != theRightSide.root)
		theRightSide.root = nullptr;
}

template <class Object>
void BinaryTree<Object>::setLeftSide( BinaryTree& theLeftSide ) {
	if (theLeftSide.root == nullptr) 
		throw( InvalidTreeArgument() );
	BinaryTreeNode<Object> *child = new BinaryTreeNode<Object>( theLeftSide.root->getElement(), 
																theLeftSide.root->getLeftSide(),
																theLeftSide.root->getRightSide() );
	root->setLeftSide( child );
	if (child != theLeftSide.root)
		theLeftSide.root = nullptr;
}

template <class Object>
bool BinaryTree<Object>::isOnRightSide( Object value )
{
	if(root == nullptr)
		throw(InvalidTreeArgument());
	BinaryTreeNode<Object> *search = root;
	if(search->getRightSide() != nullptr)
	{
		search = root->getRightSide();
	}
	else 
	{
		throw(InvalidTreeArgument());
	}
	return isOnRightSide(search, value);
}

template<class Object> 
bool BinaryTree<Object>::isOnRightSide(BinaryTreeNode<Object>* node, Object value)
{
	if(node != nullptr)
	{
		if(node->getElement() != value)
		{
			if(isOnRightSide(node->getLeftSide(), value))
			{
				return true;
			}
			else if (isOnRightSide(node->getRightSide(), value))
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	return false;

}

template <class Object>
Object BinaryTree<Object>::findMin()
{
	if(root == nullptr)
		throw (InvalidTreeArgument());
	Object smallest = root->getElement();
	findMin(root, smallest);
	return smallest;
}

template <class Object>
void BinaryTree<Object>::findMin(BinaryTreeNode<Object>* node, Object &smallest)
{
	if(node != nullptr)
	{
		if(node->getElement() < smallest)
		{
			smallest = node->getElement();
		}
		if(node->getLeftSide() != nullptr)
		{
			findMin(node->getLeftSide(), smallest);
		}
		if(node->getRightSide() != nullptr)
		{
			findMin(node->getRightSide(), smallest);
		}
	}
}

template <class Object>
void BinaryTree<Object>::merge( const Object& rootElement,
 								BinaryTree & left,
								BinaryTree & right ) {
	if ( left.root == right.root && left.root != nullptr ) {
		std::cerr << "Cannot merge a tree with itself" << std::endl;
		throw( InvalidTreeArgument() );
	}
	else {
		NodePtr oldRoot = root;
		root = new BinaryTreeNode<Object>( rootElement, 
							 			   left.root,
										   right.root );
		if (this != &left && this != &right) 
			makeEmpty( oldRoot );
		if (this != &left) 
			left.root = nullptr;
		if (this != &right)
			right.root = nullptr;
	}
}

// Deep copy of tree
template <class Object>
const BinaryTree<Object>& BinaryTree<Object>::operator =( const BinaryTree<Object>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		if (rhs.root != nullptr) 
			root = rhs.root->duplicate();
	}
	return( *this );
}

template <class Object>
void BinaryTree<Object>::printTree( std::ostream& out ) const {
	if (root == nullptr) {
		out << "nullptr" << std::endl;
	}
	else {
		printTree( root, out );
		out << std::endl;
	}
}

template <class Object>
void BinaryTree<Object>::printTree( NodePtr subtree, std::ostream & out ) const {
	if (subtree == nullptr) {
		out << "nullptr";
	}
	else {
		out << subtree->getElement();
		out << " ";
		printTree( subtree->getLeftSide(), out );
		out << " ";
		printTree( subtree->getRightSide(), out );
		out << " ";
	}
}

}
#endif