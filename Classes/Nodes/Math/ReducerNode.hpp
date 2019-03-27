#include "UtilityGraphNode.h"

class ReducerNode : public UtilityGraphNode {
 public:
    float operation(float, float);
    float getOutput() override;
};
