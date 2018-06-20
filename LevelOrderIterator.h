#ifndef LEVELORDERITERATOR_H
#define LEVELORDERITERATOR_H
#include <iostream>
#include <cstddef>
#include "BinaryTree.h"
#include "BinaryTreeIterator.h"
#include "Queue.h"

namespace cs20 {

template <class Object>
class LevelOrderIterator : public BinaryTreeIterator<Object> {
public:
	LevelOrderIterator( const BinaryTree<Object>& theTree );
	virtual ~LevelOrderIterator();

	void advance();
	void first();
	
protected:
	Queue<const BinaryTreeNode<Object> *> q;
};

}
#endif