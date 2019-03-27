#include <iostream>
#include <exception>

struct OutputError: public std::exception {
	const char * what () const throw () {
		return "A graph node is unable to produce an output with the current connections"
	}
}
