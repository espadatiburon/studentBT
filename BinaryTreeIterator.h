#ifndef BINARYTREEITERATOR_H
#define BINARYTREEITERATOR_H
#include <iostream>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include "BadIterator.h"

namespace cs20 {

template <class Object>
class BinaryTreeIterator {
public:
	BinaryTreeIterator( const BinaryTree<Object>& theTree );
	virtual ~BinaryTreeIterator();

	bool isValid() const;
	virtual void advance() = 0;
	virtual void first() = 0;
	const Object& retrieve() const;
	
//protected:
	const BinaryTreeNode<Object> * current;
	const BinaryTreeNode<Object> * root;

};

}
#endif