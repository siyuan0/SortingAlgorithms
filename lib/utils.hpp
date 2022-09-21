#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <string>
#include <chrono>
#include <random>

void printVector(std::vector<int>& vec);
void printVector(std::vector<int>& vec, int start, int end);

std::vector<int> generate_test_set(int size);
bool check_ans(std::vector<int>& to_check, std::vector<int>& ref);

static int memused;

#define START_TRACK_SPACE(_desc) memused = 0; std::string desc = _desc;

#define TRACK_VAR(_var) memused += sizeof(_var);

#define TRACK_VECTOR(_vec) memused += sizeof(_vec); memused += sizeof(*(_vec.data())) * _vec.size();

#define END_TRACK_SPACE() std::cout << desc << '\n' << "\tMemory used: " << memused << " Bytes\n";

#define START_TIMING() auto start = std::chrono::high_resolution_clock::now();

#define END_TIMING() \
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; \
    std::cout << std::fixed << std::setprecision(4) <<  "\tComputational time: " << diff.count() * 1000 << "ms\n";

#endif