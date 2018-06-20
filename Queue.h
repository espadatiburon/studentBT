#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "QueueNode.h"
#include "EmptyQueue.h"

namespace cs20 {

template <class Object>
class Queue {
public:
	Queue();
	Queue( const Queue& rhs );
	~Queue();

	bool isEmpty() const;
	void makeEmpty();
	void enqueue( const Object& data );
	const Object dequeue();
	const Object& getFront() const;
	
	const Queue& operator =( const Queue& rhs );
// take this out for the student version
	friend std::ostream& operator << ( std::ostream& outs, const Queue& q );
	friend std::ostream& operator << ( std::ostream& outs, const Queue* q );

private:
	QueueNode<Object> * frontNode;
	QueueNode<Object> * backNode;
};

}
#endif