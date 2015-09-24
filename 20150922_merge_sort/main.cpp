/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	main.cpp
 * @brief	ソーティング処理の速度比較コマンド
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "stable_sort.hpp"

#define	LENGTH	((size_t)(1024 * 1024 * 128))
//#define	LENGTH	((size_t)(6))

/**
 * ソーティング処理の速度比較コマンド
 */
int
main()
{
	int* original = new int[LENGTH];
	int* data = new int[LENGTH];
	int* buffer = new int[LENGTH];

	std::srand((unsigned int)std::time(0));

	for (size_t i(0); i < LENGTH; ++i) {
		original[i] = std::rand();
	}

	std::memcpy((void*)data, (const void*)original, sizeof(int) * LENGTH);
	std::clock_t start = std::clock();
	recursive_sort<int>(data, buffer, LENGTH);
	std::clock_t end = std::clock();

	std::printf("[R] %G (sec)\n", (double)(end - start) / CLOCKS_PER_SEC);

	if (LENGTH <= 8) {
		for (size_t i(0); i < LENGTH; ++i) {
			if (0 < i) std::printf(", ");
			std::printf("%d", data[i]);
		}
		std::printf("\n");
	}

	std::memcpy((void*)data, (const void*)original, sizeof(int) * LENGTH);
	start = std::clock();
	looped_sort<int>(data, buffer, LENGTH);
	end = std::clock();

	std::printf("[L] %G (sec)\n", (double)(end - start) / CLOCKS_PER_SEC);

	if (LENGTH <= 8) {
		for (size_t i(0); i < LENGTH; ++i) {
			if (0 < i) std::printf(", ");
			std::printf("%d", data[i]);
		}
		std::printf("\n");
	}

	delete [] original;
	delete [] data;
	delete [] buffer;

	return 0;
}
