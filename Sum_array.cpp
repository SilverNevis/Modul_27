#include "Sum_Array.h"
#include "iostream"
#include <algorithm>
#include <random>
#include <thread>

SumArray::SumArray(int n, int m) {
    n_ = n;
    m_ = m;

    data_.resize(n_);
    partial_sums_.resize(m_);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);

    for (int i = 0; i < n_; ++i) {
        data_[i] = dist(gen);
    }
}

SumArray::~SumArray() {
    for (auto& thread : threads_) {
        thread.join();
    }
}

void SumArray::Run() {
    int chunk_size = n_ / m_;

    for (int i = 0; i < m_; ++i) {
        int start = i * chunk_size;
        int end = (i + 1) * chunk_size - 1;

        // Захват переменных start, end и i в список захвата лямбды
        threads_.emplace_back([this, start, end, i]() mutable {
            partial_sums_[i] = 0; // Используем захваченное значение i
            for (int j = start; j <= end; ++j) {
                partial_sums_[i] += data_[j];
            }
            });
    }

    for (auto& thread : threads_) {
        thread.join();
    }
}

int SumArray::GetResult() const {
    int result = 0;
    for (int i = 0; i < m_; ++i) {
        result += partial_sums_[i];
    }
    return result;
}
