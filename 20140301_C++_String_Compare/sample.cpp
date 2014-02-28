/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @brief	sample code of O(n^3).
 */

#include <vector>
#include <ctime>
#include <cstdlib>

int
main()
{
	size_t l = 1000u * 10000u;
	size_t m = 2u * 10000u;
	size_t n = 64u;

	// prepare
	std::vector<char> data;
	size_t k(m);
	if (k < n) k = n;
	data.reserve(k);
	std::srand((unsigned)std::time(0));
	for (size_t j(0); j < k; ++j) {
		data.push_back((char)std::rand());
	}

	// O(n^3)
	size_t x(0);
	for (size_t h(0); h < l; ++h) {
		if (h % 1000u == 0) std::printf(".");
		// O(n^2)
		for (size_t i(0); i < m; ++i) {
			// O(n^1)
			for (size_t j(0); j < n; ++j) {
				if (data[i] < data[j]) ++x;
			}
		}
	}
	std::printf("[%ld]\n", x);

	return 0;
}
