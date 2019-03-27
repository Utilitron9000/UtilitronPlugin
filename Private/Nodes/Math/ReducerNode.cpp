#include "Nodes/Math/ReducerNode.h"
#include "Exceptions.h"

ReducerNode::ReducerNode(float(*op)(float, float)) : maxInputs(INFINITY), operation(op) { }


ReducerNode::getOutput() {
	if (this->connectedInputs.size() > 0) {
        float connectedInputVals = connectedInputs[0];
        for(int i = 1; i < connectedInputs.size(); i++) {
            connectedInputVals = this->operation(connectedInputVals, connectedInputs[i].getOutput());
        }  
        return connectedInputVals;
	}

	throw OutputError();
}
