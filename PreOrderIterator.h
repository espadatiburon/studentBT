#ifndef PREORDERITERATOR_H
#define PREORDERITERATOR_H
#include <iostream>
#include <cstddef>
#include "BinaryTree.h"
#include "BinaryTreeIterator.h"
#include "Queue.h"

namespace cs20 {

template <class Object>
class PreOrderIterator : public BinaryTreeIterator<Object> {
public:
	PreOrderIterator( const BinaryTree<Object>& theTree );
	virtual ~PreOrderIterator();
	
	void queueAll();
	void queueAll(const BinaryTreeNode<Object>* node);
	void advance();
	void first();
	
protected:
	Queue<const BinaryTreeNode<Object> *> q;
};

}
#endif