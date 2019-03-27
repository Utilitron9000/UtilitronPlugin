#include <vector>

class UtilityGraphNode {
	int maxInputs;
	std::vector<UtilityGraphNode*> connectedInputs;
	string id;

 public:
	UtilityGraphNode() {}
	~UtilityGraphNode() {}
	virtual float getOutput() = 0;
	string getId() { return id; }
}

