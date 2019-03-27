#include <vector>

using namespace std;

template<typename T>
class WeightedRandomSelection {
public:
	static const int WEIGHT_GROUP_SIZE = 100;
	static T selectWeightedRandom(vector<T> choices, int topSubsetSize, float (*utilityKey)(T));
private:
	static vector<T> getTopSubset(vector<T> choices, int topSubsetSize, float (*utilityKey)(T));
	static vector<T> getWeighted(vector<T> choices, float (*utilityKey)(T));
};
