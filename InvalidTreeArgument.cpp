#include "InvalidTreeArgument.h"

namespace cs20 {

InvalidTreeArgument::InvalidTreeArgument( const std::string& msg ) : std::logic_error( msg.c_str() ) {}

}
