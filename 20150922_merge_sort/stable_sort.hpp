/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	stable_sort.hpp
 * @brief	マージ処理系ソートの実装
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#ifndef	__STABLE_SORT_HPP__
#define	__STABLE_SORT_HPP__ "stable_sort.hpp"

#include <cstddef>
#include <cstring>
#include <cassert>
#include <utility>
#include <algorithm>

/**
 * 新しいマージ処理系ソーティング・アルゴリズム
 * @param[in,out]	data	ソーティング処理の対象データ
 * @param	buffer	作業領域 (引数 @a length の長さが必要)
 * @param[in]	length	引数 @a data の要素数
 * @param[in]	gap	マージ処理以前のソーティング処理幅の最大値
 */
template<typename TYPE>
void
looped_sort(TYPE* data,
			TYPE* buffer,
			size_t length,
			size_t gap = 4)
{
	assert(data);
	assert(buffer);
	assert(0 < length);
	assert(2 <= gap);

	size_t l, k;
	bool flag;

	for (size_t h(0); h < length; h += gap) {
		l = std::min<size_t>(h + gap, length);
		for (size_t i(0); i < gap; ++i) {
			k = l - i;
			flag = true;
			for (size_t j(h+1); j < k; ++j) {
				if (data[j-1] <= data[j]) continue;
				std::swap<TYPE>(data[j-1], data[j]);
				flag = false;
			}
			if (flag) break;
		}
	}

	size_t x, y;

	for (size_t h(gap); h < length; h *= 2) {
		for (size_t i(0); i + h < length; i += h * 2) {
			std::memcpy((void*)buffer, (const void*)(data + i), sizeof(TYPE) * h);
			x = 0;
			y = i + h;
			l = std::min<size_t>(i + h * 2, length);
			for (size_t j(i); j < l; ++j) {
				if (buffer[x] <= data[y]) {
					data[j] = buffer[x];
					if (++x >= h) break;
				}
				else {
					data[j] = data[y];
					if (++y < l) continue;
					std::memcpy((void*)(data + j + 1), (const void*)(buffer + x), sizeof(TYPE) * (h - x));
					break;
				}
			}
		}
	}
}

/**
 * マージ・ソート
 * @param[in,out]	data	ソーティング処理の対象データ
 * @param	buffer	作業領域 (引数 @a length の長さが必要)
 * @param[in]	length	引数 @a data の要素数
 */
template<typename TYPE>
void
recursive_sort(TYPE* data,
			   TYPE* buffer,
			   size_t length)
{
	assert(data);
	assert(buffer);
	assert(0 < length);

	size_t h = length / 2;

	if (1 < h) recursive_sort<TYPE>(data, buffer, h);
	if (1 < length - h) recursive_sort<TYPE>(data + h, buffer, length - h);

	if (0 == h || 0 == length - h) return;

	size_t x(0);
	size_t y(h);

	std::memcpy((void*)buffer, (const void*)data, sizeof(TYPE) * h);

	for (size_t i(0); i < length; ++i) {
		if (buffer[x] <= data[y]) {
			data[i] = buffer[x];
			if (++x >= h) break;
		}
		else {
			data[i] = data[y];
			if (++y < length) continue;
			std::memcpy((void*)(data + i + 1), (const void*)(buffer + x), sizeof(TYPE) * (h - x));
			break;
		}
	}
}

#endif	// __STABLE_SORT_HPP__
