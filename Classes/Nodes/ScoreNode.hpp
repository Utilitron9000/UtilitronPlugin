#include "UtilityGraphNode.h"
#include <string>

class ScoreNode : public UtilityGraphNode {
 public:
	ScoreNode(std::string name);
	float getOutput() override;
};
