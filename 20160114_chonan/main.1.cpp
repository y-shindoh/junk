/* -*- coding: utf-8 -*- */
/**
 * @file	main.1.cpp
 * @brief	Chonanさんのブログの問題の回答。
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://chonan.blog.pid0.org/2016/01/poh7-swim.html .
 */

/*
  問題:
  入力された自然数 n (最大1000000)の階乗 n! での、
  最下位から続く0を除いた値の下9けたを出力せよ。
 */

#include <cstdio>

/**
 * 問題の回答
 * @note	テンプレートの型 @a TYPE には64ビット以上の整数を指定すること。
 */
template<typename TYPE>
TYPE
calculate(TYPE n)
{
	TYPE r(1);

	for (TYPE i(2); i <= n; ++i) {
		size_t j(i);
		while (j % 10 == 0) j /= 10;
		j %= 1000000000;
		r *= j;
		while (r % 10 == 0) r /= 10;
		r %= 1000000000;
	}

	return r;
}

#define	N	1000000

/**
 * サンプル・コマンド
 */
int
main()
{
	std::printf("%09lu\n", calculate<size_t>(N));

	return 0;
}
