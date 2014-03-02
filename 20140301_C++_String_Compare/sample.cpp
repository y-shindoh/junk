/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @brief	sample code of O(n^3).
 */

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>

int
main()
{
	size_t m = 1000u * 10000u;
	size_t n = 2u * 10000u;

	char buffer[1024];

	// prepare
	std::vector<std::string> data;
	int h;
	size_t k(m);
	if (k < n) k = n;
	std::srand((unsigned)std::time(0));
	for (size_t i(0); i < k; ++i) {
		if (i % 10000u == 0) std::printf("+");
		h = std::rand();
		sprintf(buffer, "%X", h);
		data.push_back(std::string(buffer));
	}
	std::printf("\n");

	// O(n^3)
	size_t x(0);
	for (size_t i(0); i < m; ++i) {
		if (i % 10000u == 0) std::printf(".");
		// O(n^2)
		for (size_t j(0); j < n; ++j) {
			// O(n^1)
			if (data[i] == data[j]) ++x;
		}
	}
	std::printf("[%ld]\n", x);

	return 0;
}
