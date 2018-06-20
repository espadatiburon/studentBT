#include "EmptyQueue.h"

namespace cs20 {

EmptyQueue::EmptyQueue( const std::string& msg ) : std::logic_error( msg.c_str() ) {}

}
