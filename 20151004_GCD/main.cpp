/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	main.cpp
 * @brief	ユークリッド互除法の実装比較
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

#ifndef	N
#define	N	((size_t)(1024 * 1024 * 8))
#endif	// N

template<typename TYPE>
TYPE
gcd_r(TYPE a,
	  TYPE b)
{
	if (b == (TYPE)0) return a;

	return gcd_r(b, a % b);
}

template<typename TYPE>
TYPE
gcd_l(TYPE a,
	  TYPE b)
{
	if (a < b) std::swap<TYPE>(a, b);

	while (0 < b) {
		a %= b;
		std::swap<TYPE>(a, b);
	}

	return a;
}

int
main()
{
	std::clock_t s, e;
	std::vector<size_t> a, b, c, d;
	double x, y;

	////////////////////////////////////////////////////////////
	// 準備

	a.reserve(N);
	b.reserve(N);
	c.resize(N, (size_t)0);
	d.resize(N, (size_t)0);

	std::srand((unsigned int)std::time(0));
	for (size_t i(0); i < N; ++i) a.push_back((size_t)std::rand());
	for (size_t i(0); i < N; ++i) b.push_back((size_t)std::rand());

	////////////////////////////////////////////////////////////
	// ユークリッド互除法の再帰版

	s = std::clock();
	for (size_t i(0); i < N; ++i) c[i] = gcd_r<size_t>(a[i], b[i]);
	e = std::clock();
	x = (double)(e - s) / CLOCKS_PER_SEC;

	////////////////////////////////////////////////////////////
	// ユークリッド互除法の非再帰版

	s = std::clock();
	for (size_t i(0); i < N; ++i) d[i] = gcd_l<size_t>(a[i], b[i]);
	e = std::clock();
	y = (double)(e - s) / CLOCKS_PER_SEC;

	////////////////////////////////////////////////////////////
	// 値のチェック

	for (size_t i(0); i < N; ++i) {
		if (c[i] == d[i]) continue;
		std::printf("[%lu] %lu != %lu\n", i, c[i], d[i]);
	}

	////////////////////////////////////////////////////////////
	// 出力

	std::printf("[R] %G sec. (%f)\n", x, x / y);
	std::printf("[L] %G sec. (%f)\n", y, y / x);

	return 0;
}
