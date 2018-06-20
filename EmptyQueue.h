#ifndef EMPTYQUEUE_H
#define EMPTYQUEUE_H
#include <iostream>
#include <string>

namespace cs20 {

class EmptyQueue : public std::logic_error {
public:
	EmptyQueue( const std::string& msg = "" );
};

}
#endif