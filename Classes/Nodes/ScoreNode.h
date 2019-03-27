#include "UtilityGraphNode.h"
#include <string>

class ScoreNode : public UtilityGraphNode {
 public:
	ScoreNode(string name);
	float getOutput();
}
