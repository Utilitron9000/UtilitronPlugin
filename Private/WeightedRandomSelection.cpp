#include "WeightedRandomSelection.hpp"
#include "RandomHelper.hpp"
#include <random>
#include <algorithm>

using randInt RandomHelper::getRandomInt

template<typename T>
WeightedRandomSelection<T>::selectedWeightedRandom(vector<T>& choices, int topSubsetSize, float (*utilityKey)(T)) {
	vector<T> topSubset = getTopSubset(choices, topSubsetSize, utilityKey);
	vector<T> weighted = getWeighted(topSubset, utilityKey);
	return weighted[randInt(0, weighted.size())];
}

WeightedRandomSelection<T>::getTopSubset(vector<T> choices, int topSubsetSize, float (*utilityKey)(T)) {
	auto compareFn = [utilityKey](T a, T b) {
		return utilityKey(a) > utilityKey(b);
	};

	sort(choices.begin(), choices.end(), compareFn);
	choices.resize(topSubsetSize);
	return choices;
}

WeightedRandomSelection<T>::getWeighted(vector<T>& choices, float (*utilityKey)(T)) {
	vector<T> weighted = vector<T>(choices.size() * 100);
	for (T* choice : choices) {
		int weight = (int)(utilityKey(choice) * WEIGHT_GROUP_SIZE);
		for (int i = 0; i < weight; ++i) {
			weighted.push_back(choice);
		}
	}
	return weighted;
}
