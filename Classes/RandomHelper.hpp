#include <random>
class RandomHelper {
	static std::default_random_engine randomEngine;

	public:
	RandomHelper();
	~RandomHelper();
	static int getRandomInt(int min, int max);
};
