/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	main.cpp
 * @brief	エラトステネスのふるいの実装に関する速度比較コマンド
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstddef>
#include <cstdio>
#include <ctime>
#include <vector>

#ifndef	N
#define	N	((size_t)(1024 * 1024 * 8))
#endif	// N

int
main()
{
	std::clock_t s, e;

	std::printf("0-%lu\n", N);

	////////////////////////////////////////////////////////////
	// エラトステネスのふるいの典型的な実装

	{
		s = std::clock();

		std::vector<bool> f;
		f.resize(N+1, true);

		f[0] = false;
		if (1 < N) f[1] = false;

		// 2を超える偶数
		for (size_t i(4); i <= N; i += 2) f[i] = false;

		// 奇数の合成数
		for (size_t i(3); i * i <= N; i += 2) {
			if (!f[i]) continue;
			for (size_t j(i+i); j <= N; j += i) f[j] = false;
		}

		size_t x(0);

		for (size_t i(0); i <= N; ++i) {
			if (!f[i]) continue;
			++x;
		}

		f.clear();

		e = std::clock();

		std::printf("=> %lu (%G sec.)\n", x, (double)(e - s) / CLOCKS_PER_SEC);
	}

	////////////////////////////////////////////////////////////
	// エラトステネスのふるいの変化球っぽい実装

	{
		s = std::clock();

		std::vector<size_t> r;

		if (2 <= N) r.push_back(2);

		for (size_t i(3); i <= N; i += 2) {
			bool f(true);
			for (auto it = r.begin(); it != r.end() && *it * *it <= i; ++it) {
				if (0 < i % *it) continue;
				f = false;
				break;
			}
			if (f) r.push_back(i);
		}

		size_t x = r.size();

		r.clear();

		e = std::clock();

		std::printf("=> %lu (%G sec.)\n", x, (double)(e - s) / CLOCKS_PER_SEC);
	}

	return 0;
}
