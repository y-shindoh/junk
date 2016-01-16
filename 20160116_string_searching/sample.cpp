/* -*- coding: utf-8 -*- */
/**
 * @file	sample.cpp
 * @brief	文字列探索の各種実装
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <algorithm>

/**
 * 力まかせ探索
 */
size_t
bf_search(const char* input,
		  const char* pattern)
{
	for (size_t i(0); input[i]; ++i) {
		size_t j(0);
		while (input[i+j] && input[i+j] == pattern[j]) ++j;
		if (pattern[j] == '\0') return i;
	}

	return ~(size_t)0;
}

/**
 * BM法および派生の文字列探索器
 */
template<typename TYPE, size_t N = 0x100UL>
class BMsearcher
{
private:

	std::string pattern_;	///< パターンの文字列
	TYPE table_[N];			///< 末尾から数えた文字位置のテーブル

public:

	/**
	 * コンストラクタ
	 * @param[in]	pattern	パターン文字列
	 */
	BMsearcher(const char* pattern)
		: pattern_(pattern)
		{
			assert(pattern);
			assert(0 < pattern_.length());

			TYPE n = (TYPE)pattern_.length();
			std::fill(table_, table_ + N, n);	///< 先頭以前はワイルドカード

			for (TYPE i(0); i + 1 < n; ++i) {
				table_[(size_t)pattern[i]] = n - i - 1;
			}
		}

	/**
	 * BM法による文字列探索
	 * @param[in]	buffer	探索対象
	 * @param[in]	l	文字列 @a buffer の長さ
	 * @return	パターン文字列の @a buffer 内での位置
	 */
	size_t
	search_bm(const char* buffer,
			  size_t l) const
		{
			assert(buffer);
			assert(0 < l);
			assert(0 < pattern_.length());

			TYPE n = (TYPE)pattern_.length();

			for (TYPE i(n-1); i < (TYPE)l; ++i) {
				bool f(true);
				for (TYPE j(0); j < n; ++j) {
					if (buffer[i-j] == pattern_[n-j-1]) continue;
					f = false;
					TYPE k = table_[(size_t)buffer[i-j]];
					if (j < k) i += k - j - 1;	// スキップする文字数を調整
					break;
				}
				if (f) return i - (n - 1);
			}

			return ~(size_t)0;
		}

	/**
	 * Horspool法による文字列探索
	 * @param[in]	buffer	探索対象
	 * @param[in]	l	文字列 @a buffer の長さ
	 * @return	パターン文字列の @a buffer 内での位置
	 */
	size_t
	search_horspool(const char* buffer,
					size_t l) const
		{
			assert(buffer);
			assert(0 < l);
			assert(0 < pattern_.length());

			TYPE n = (TYPE)pattern_.length();

			for (TYPE i(0); i + n - 1 < (TYPE)l; ++i) {
				if (std::memcmp(buffer + i, pattern_.c_str(), n) == 0) return i;
				i += table_[(size_t)buffer[i+n-1]] - 1;	// スキップする文字数を調整
			}

			return ~(size_t)0;
		}

	/**
	 * Sunday法による文字列探索
	 * @param[in]	buffer	探索対象
	 * @param[in]	l	文字列 @a buffer の長さ
	 * @return	パターン文字列の @a buffer 内での位置
	 */
	size_t
	search_sunday(const char* buffer,
				  size_t l) const
		{
			assert(buffer);
			assert(0 < l);
			assert(0 < pattern_.length());

			TYPE n = (TYPE)pattern_.length();

			for (TYPE i(0); i + n - 1 < (TYPE)l; ++i) {
				if (std::memcmp(buffer + i, pattern_.c_str(), n) == 0) return i;
				if ((TYPE)l <= i + n) break;
				if (pattern_[n-1] == buffer[i+n]) continue;
				i += table_[(size_t)buffer[i+n]];	// スキップする文字数を調整
			}

			return ~(size_t)0;
		}
};

/**
 * サンプル・コマンド
 */
int
main()
{
	const char input[] = "the stick, and made believe to worry it: then Alice dodged behind a";
	const char pattern[] = "behind";
	size_t l = std::strlen(input);

	BMsearcher<int> searcher(pattern);

	// 力まかせ探索
	std::printf("<<bf_search>>\n");
	for (size_t i(0); i < l; ++i) {
		size_t j = bf_search(input + i, pattern);
		if (j == ~(size_t)0) break;
		i += j;
		std::printf("%s\n", input + i);
	}

	// BM法
	std::printf("<<BMsearcher::search_bm>>\n");
	for (size_t i(0); i < l; ++i) {
		size_t j = searcher.search_bm(input + i, l - i);
		if (j == ~(size_t)0) break;
		i += j;
		std::printf("%s\n", input + i);
	}

	// Horspool法
	std::printf("<<BMsearcher::search_horspool>>\n");
	for (size_t i(0); i < l; ++i) {
		size_t j = searcher.search_horspool(input + i, l - i);
		if (j == ~(size_t)0) break;
		i += j;
		std::printf("%s\n", input + i);
	}

	// Sunday法
	std::printf("<<BMsearcher::search_sunday>>\n");
	for (size_t i(0); i < l; ++i) {
		size_t j = searcher.search_sunday(input + i, l - i);
		if (j == ~(size_t)0) break;
		i += j;
		std::printf("%s\n", input + i);
	}

	return 0;
}
