#ifndef QUEUENODE_H
#define QUEUENODE_H
#include <iostream>

namespace cs20 {

template <class Object>
class QueueNode {
public:
	QueueNode( const Object& theElement = Object(), QueueNode * node = nullptr );

	friend std::ostream& operator <<( std::ostream& outs, const QueueNode * node );

	// these accessors and mutators are called
	// from Queue class
	// no public methods expose QueueNode instances
	// outside the Queue class
	const Object& getElement() const;
	QueueNode* getNext() const;
	void setNext( QueueNode * node );

private:
	Object element;
	QueueNode* next;

};

}
#endif