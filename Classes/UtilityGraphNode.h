#include <vector>
#include "Exceptions.h"

class UtilityGraphNode {
	int maxInputs;
	std::vector<UtilityGraphNode*> connectedInputs;

 public:
	UtilityGraphNode() : maxInputs(1) {}
	~UtilityGraphNode() {}
	virtual float getOutput() = 0;
	virtual bool connectInput(UtilityGraphNode* node) {
		if (connectedInputs.size() < maxInputs) {
			connectedInputs.push_back(node);
			return true;
		} else {
			return false;
		}
	}

	virtual void reset() {
		for (UtilityGraphNode* node : connectedInputs) {
			node->reset();
		}
	}
}

