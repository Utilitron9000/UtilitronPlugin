#include "RandomHelper.hpp"

std::default_random_engine RandomHelper::randomEngine = std::default_random_engine{};

RandomHelper::getRandomInt(int min, int max) {
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(randomEngine, Dist::param_type{min, max});
}
