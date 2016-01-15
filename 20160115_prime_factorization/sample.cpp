/* -*- coding: utf-8 -*- */
/**
 * @file	sample.cpp
 * @brief	素因数分解の簡単な実装
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstdio>
#include <vector>
#include <utility>

/**
 * 素因数に分解
 * @param[in]	number	分解対象の数字
 * @param[out]	factors	素因数分解の結果 (first: base, second: exponention)
 */
template<typename TYPE>
void
prime_factorization(TYPE number,
					std::vector< std::pair<TYPE, TYPE> >& factors)
{
	TYPE e(0);

	while (number % 2 == 0) {
		number /= 2;
		++e;
	}

	if (0 < e) factors.push_back(std::make_pair((TYPE)2, e));

	// 注意: 合成数は自動的にスキップされる。
	for (TYPE i(3); i * i <= number; i += 2) {
		e = 0;
		while (number % i == 0) {
			number /= i;
			++e;
		}
		if (0 < e) factors.push_back(std::make_pair(i, e));
	}

	if (1 < number || factors.empty()) {
		factors.push_back(std::make_pair(number, (TYPE)1));
	}
}

#define	N	1234567890LU

/**
 * サンプル・コマンド
 */
int
main()
{
	std::vector< std::pair<size_t, size_t> > factors;

	prime_factorization((size_t)N, factors);

	std::printf("%lu =", N);
	for (size_t i(0); i < factors.size(); ++i) {
		if (0 < i) std::printf(" *");
		std::printf(" %lu^%lu", factors[i].first, factors[i].second);
	}
	std::printf("\n");

	return 0;
}
