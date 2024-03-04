#pragma once
#include <thread>
#include <vector>
#ifndef SUM_ARRAY_H
#define SUM_ARRAY_H

#include <vector>

class SumArray {
public:
	SumArray(int n, int m);
	~SumArray();

	void Run();

	int GetResult() const;

private:
	std::vector<int> data_;
	std::vector<std::thread> threads_;
	std::vector<int> partial_sums_;
	int n_;
	int m_;
};

#endif
