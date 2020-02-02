#ifndef SRC_ADVENTURE_H_
#define SRC_ADVENTURE_H_

#include <algorithm>
#include <vector>
#include <random>

#include "../third_party/threadpool/threadpool.h"

#include "./types.h"
#include "./utils.h"

class Adventure {
 public:
  virtual ~Adventure() = default;

  virtual uint64_t packEggs(std::vector<Egg> eggs, BottomlessBag& bag) = 0;

  virtual void arrangeSand(std::vector<GrainOfSand>& grains) = 0;

  virtual Crystal selectBestCrystal(std::vector<Crystal>& crystals) = 0;

 protected:
	size_t partition(std::vector<GrainOfSand>& grains, size_t lo, size_t hi) {
		GrainOfSand pivot = grains[hi];

		size_t lastSmaller = lo - 1;
		for (size_t i = lo; i <= hi - 1; ++i) {
			if (grains[i] < pivot) {
				++lastSmaller;
				std::swap(grains[lastSmaller], grains[i]);
			}
		}

		std::swap(grains[lastSmaller + 1], grains[hi]);
		return lastSmaller + 1;
	}

	void chooseRandomPivot(std::vector<GrainOfSand>& grains, size_t lo, size_t hi, std::mt19937& gen) {
		std::uniform_int_distribution<int> dist(lo, hi - 1);
		size_t randomId = dist(gen);
		std::swap(grains[randomId], grains[hi]);
	}

	static Crystal findMax(std::vector<Crystal>& crystals, size_t startPos, size_t endPos) {
		Crystal result = Crystal(0);
		if (startPos > endPos)
			return result;

		for (size_t i = startPos; i <= endPos; ++i) {
			if (result < crystals[i])
				result = crystals[i];
		}

		return result;
	}
};

class LonesomeAdventure : public Adventure {
 public:
  LonesomeAdventure() {}

  uint64_t packEggs(std::vector<Egg> eggs, BottomlessBag& bag) override {
		uint64_t freeEggs = 0;
		for (size_t i = 0; i < eggs.size(); ++i) {
			if (eggs[i].getSize() == 0) {
				freeEggs += eggs[i].getWeight();
				std::swap(eggs[i], eggs.back());
				eggs.pop_back();
			}
		}

		std::vector<std::vector<uint64_t>> dp(eggs.size() + 1);
		std::vector<std::vector<bool>> from(eggs.size() + 1);
		for (auto& it : dp)
			it.resize(bag.getCapacity() + 1);
		for (auto& it : from)
			it.resize(bag.getCapacity() + 1);

		for (size_t item = 0; item <= eggs.size(); ++item) {
			for (uint64_t curLoad = 0; curLoad <= bag.getCapacity(); ++curLoad) {
				from[item][curLoad] = false;
				if (item == 0 || curLoad == 0) {
					dp[item][curLoad] = 0;
					continue;
				}

				dp[item][curLoad] = dp[item - 1][curLoad];
				uint64_t candidate = dp[item - 1][curLoad - eggs[item - 1].getSize()] + eggs[item - 1].getWeight();
				if (eggs[item - 1].getSize() <= curLoad && candidate > dp[item][curLoad]) {
					dp[item][curLoad] = candidate;
					from[item][curLoad] = true;
				}
			}
		}

		//std::cerr<<"\n\nRESULT: "<<dp[eggs.size()][bag.getCapacity()]<<"\nCONSTRUCTION: ";
		uint64_t curLoad = bag.getCapacity();
		for (int item = eggs.size(); item >= 1; --item) {
			if (from[item][curLoad]) {
				//std::cerr<<"("<<eggs[item - 1].getWeight()<<","<<eggs[item - 1].getSize()<<")";
				bag.addEgg(eggs[item - 1]);
				curLoad -= eggs[item - 1].getSize();
			}
		}

		return dp[eggs.size()][bag.getCapacity()] + freeEggs;
	}

  void arrangeSand(std::vector<GrainOfSand>& grains) override {
  	std::random_device rd;
  	std::mt19937 gen(rd());
  	quickSortSequential(grains, 0, grains.size() - 1, gen);
  }

  Crystal selectBestCrystal(std::vector<Crystal>& crystals) override {
  	return findMax(crystals, 0, crystals.size() - 1);
  }

 private:
	void quickSortSequential(std::vector<GrainOfSand>& grains, size_t lo, size_t hi, std::mt19937& gen) {
		if (lo < hi) {
			chooseRandomPivot(grains, lo, hi, gen);
			size_t pivot = partition(grains, lo, hi);

			if (pivot != 0)
				quickSortSequential(grains, lo, pivot - 1, gen);
			quickSortSequential(grains, pivot + 1, hi, gen);
		}
	}
};

class TeamAdventure : public Adventure {
 public:
  explicit TeamAdventure(uint64_t numberOfShamansArg)
      : numberOfShamans(numberOfShamansArg),
        councilOfShamans(numberOfShamansArg) {}

	uint64_t packEggs(std::vector<Egg> eggs, BottomlessBag& bag) override {
		uint64_t freeEggs = 0;
		for (size_t i = 0; i < eggs.size(); ++i) {
			if (eggs[i].getSize() == 0) {
				freeEggs += eggs[i].getWeight();
				std::swap(eggs[i], eggs.back());
				eggs.pop_back();
			}
		}

		std::vector<std::vector<uint64_t>> dp(eggs.size() + 1);
		std::vector<std::vector<bool>> from(eggs.size() + 1);
		for (auto& it : dp)
			it.resize(bag.getCapacity() + 1);
		for (auto& it : from)
			it.resize(bag.getCapacity() + 1);

		for (size_t item = 0; item <= eggs.size(); ++item) {
			for (uint64_t curLoad = 0; curLoad <= bag.getCapacity(); ++curLoad) {
				from[item][curLoad] = false;
				if (item == 0 || curLoad == 0) {
					dp[item][curLoad] = 0;
					continue;
				}

				dp[item][curLoad] = dp[item - 1][curLoad];
				uint64_t candidate = dp[item - 1][curLoad - eggs[item - 1].getSize()] + eggs[item - 1].getWeight();
				if (eggs[item - 1].getSize() <= curLoad && candidate > dp[item][curLoad]) {
					dp[item][curLoad] = candidate;
					from[item][curLoad] = true;
				}
			}
		}

		//std::cerr<<"\n\nRESULT: "<<dp[eggs.size()][bag.getCapacity()]<<"\nCONSTRUCTION: ";
		uint64_t curLoad = bag.getCapacity();
		for (int item = eggs.size(); item >= 1; --item) {
			if (from[item][curLoad]) {
				//std::cerr<<"("<<eggs[item - 1].getWeight()<<","<<eggs[item - 1].getSize()<<")";
				bag.addEgg(eggs[item - 1]);
				curLoad -= eggs[item - 1].getSize();
			}
		}

		return dp[eggs.size()][bag.getCapacity()] + freeEggs;
	}

	void arrangeSand(std::vector<GrainOfSand>& grains) override {
		std::random_device rd;
		std::mt19937 gen(rd());
		jobsActive = 1;
		quickSortConcurrent(grains, 0, grains.size() - 1, gen);

		{
			std::unique_lock<std::mutex> lock(sort_mutex);
			all_done.wait(lock, [this]{ return jobsActive == 0; });
		}
	}

	Crystal selectBestCrystal(std::vector<Crystal>& crystals) override {
		Crystal result = Crystal(0);

		// TODO: optymalniejsze wielkosci blokow
		size_t blockSize = (crystals.size() + numberOfShamans - 1) / numberOfShamans;
		for (size_t curStart = 0; curStart < crystals.size(); curStart += blockSize) {
			size_t curEnd = std::min(curStart + blockSize - 1, crystals.size() - 1);
			Crystal blockResult = councilOfShamans.enqueue([&crystals, curStart, curEnd]{
				return findMax(crystals, curStart, curEnd); }).get();
			if (result < blockResult)
				result = blockResult;
		}

		return result;
	}

 private:
  uint64_t numberOfShamans;
  ThreadPool councilOfShamans;
  int jobsActive;
  std::condition_variable all_done;
  std::mutex sort_mutex;
  const size_t SPLITTING_CONST = 8;

	void quickSortConcurrent(std::vector<GrainOfSand>& grains, size_t lo, size_t hi, std::mt19937& gen) {
		if (lo < hi) {
			chooseRandomPivot(grains, lo, hi, gen);
			size_t pivot = partition(grains, lo, hi);

			if (pivot != 0) {
				{
					std::lock_guard<std::mutex> lock(sort_mutex);
					++jobsActive;
				}
				if (hi - lo > SPLITTING_CONST) {
					councilOfShamans.enqueue([this, &grains, lo, pivot, &gen]{ this->quickSortConcurrent(grains,
									lo, pivot - 1, gen); });
				} else quickSortConcurrent(grains, lo, pivot - 1, gen);
			}

			{
				std::lock_guard<std::mutex> lock(sort_mutex);
				++jobsActive;
			}
			quickSortConcurrent(grains, pivot + 1, hi, gen);
		}

		{
			std::lock_guard<std::mutex> lock(sort_mutex);
			if (--jobsActive == 0) {
				all_done.notify_all();
			}
		}
	}
};

#endif  // SRC_ADVENTURE_H_
