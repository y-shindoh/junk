/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	main.cpp
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstddef>
#include <cstdio>
#include <cassert>
#include <vector>

#ifdef	NOT_USE_DP
/**
 * n段の階段を一歩で1〜N段ずつ登る場合の登り方の数 (単純な再帰関数の実装)
 * @param[in]	n	階段の段数
 * @param[in]	s	一歩で登れる段数
 * return	登り方の数
 * @note	テンプレートの型 @a TYPE は符号なし整数を指定すること。
 */
template<typename TYPE>
TYPE
find_step_sequence(size_t n,
				   size_t s)
{
	assert(n);
	assert(s);

	TYPE c(0);

	for (size_t i(1); i <= s; ++i) {
		if (n <= i) {
			if (n == i) ++c;
			break;
		}
		c += find_step_sequence<TYPE>(n - i, s);
	}

	return c;
}
#else	// NOT_USE_DP
/**
 * n段の階段を一歩で1〜N段ずつ登る場合の登り方の数 (DPを用いた実装)
 * @param[in]	n	階段の段数
 * @param[in]	s	一歩で登れる段数
 * return	登り方の数
 * @note	テンプレートの型 @a TYPE は符号なし整数を指定すること。
 */
template<typename TYPE>
TYPE
find_step_sequence(size_t n,
				   size_t s)
{
	assert(n);
	assert(s);

	std::vector<TYPE> count;
	count.resize(n + 1, (TYPE)0);
	count[0] = 1;

	for (size_t i(0); i < n; ++i) {
		for (size_t j(1); j <= s; ++j) {
			if (n < i + j) break;
			count[i+j] += count[i];
		}
	}

	return count.back();
}
#endif	// NOT_USE_DP

/**
 * 動作確認用コマンド
 */
int main()
{
	size_t n(LENGTH);
	size_t s(STEP);

	unsigned int c = find_step_sequence<unsigned int>(n, s);
	std::printf("%lu / 1-%lu => %u\n", n , s, c);

	return 0;
}
