/* -*- coding: utf-8 -*- */
/**
 * @file	main.2.cpp
 * @brief	Chonanさんのブログの問題の回答。
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	see http://chonan.blog.pid0.org/2016/01/poh7-megane.html .
 */

/*
  問題:
  省略。
 */

#include <cstdio>
#include <utility>

/**
 * 問題の回答
 * @note	テンプレートの型 @a TYPE には @a N ビット以上の整数を指定すること。
 */
template<typename TYPE, size_t M, size_t N>
std::pair<TYPE, TYPE>
search(const bool large[M][M],
	   const bool small[N][N])
{
	TYPE v[M][M-N+1];
	TYPE w[N];

	// O(N^2)
	for (size_t i(0); i < N; ++i) {
		w[i] = 0;
		for (size_t j(0); j < N; ++j) {
			w[i] = (w[i] << 1) | small[i][j];
		}
	}

	// O(M^2)
	for (size_t i(0); i < M; ++i) {
		for (size_t j(0); j + N - 1 < M; ++j) {
			if (j == 0) {
				v[i][j] = 0;
				for (size_t k(0); k < N; ++k) {
					v[i][j] = (v[i][j] << 1) | large[i][j+k];
				}
			}
			else {
				v[i][j] = (v[i][j-1] << 1) | large[i][j+N-1];
				v[i][j] &= ~(~(TYPE)0 << N);
			}
		}
	}

	// O(N*(M-N)^2)
	// 必要ならここでより速いマッチング処理に変更する。
	for (size_t i(0); i + N - 1 < M; ++i) {
		for (size_t j(0); j + N - 1 < M; ++j) {
			bool f(true);
			for (size_t k(0); k < N; ++k) {
				if (v[i+k][j] == w[k]) continue;
				f = false;
				break;
			}
			if (!f) continue;
			return std::make_pair((TYPE)i, (TYPE)j);
		}
	}

	return std::make_pair(~(TYPE)0, ~(TYPE)0);
}

#define	M	4
#define	N	3

/**
 * サンプル・コマンド
 */
int
main()
{
	bool large[M][M] = {{0, 0, 1, 0},
						{0, 1, 1, 0},
						{0, 1, 0, 1},
						{1, 1, 1, 0}};
	bool small[N][N] = {{0, 1, 1},
						{0, 1, 0},
						{1, 1, 1}};

	std::pair<int, int> result = search<int, M, N>(large, small);

	std::printf("%d, %d\n", result.first, result.second);

	return 0;
}
