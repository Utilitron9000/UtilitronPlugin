#include "Nodes/ScoreNode.hpp"
#include "Exceptions.h"

ScoreNode::ScoreNode(string name) {
	this->name = name;
	this->maxInputs = 1;
}

ScoreNode::getOutput() {
	if (this->connectedInputs.size() > 0) {
		return this->connectedInputs[0];
	}

	throw OutputError();
}
