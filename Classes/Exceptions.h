#include <iostream>
#include <exception>

struct NodeConnectionError: public exception {
	const char * what () const throw () {
		return "Nodes cannot be connected"
	}
}
