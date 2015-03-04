/** -*- coding: utf-8; tab-width: 4 -*-
 * @file	count_buffer.cpp
 * @author	Yasutaka SHINDOH
 */

#include <iostream>

using namespace std;

/**
 * 2進数表現のバッファ上で連続した1がいくつあるか算出
 * @param[in]	buffer	バッファ
 * @param[in]	length	バッファ長 (バイト数)
 * @return	連続した1の総数
 */
size_t
count_buffer(const unsigned char* buffer,
			 const size_t length)
{
	size_t count(0);
	size_t check(0);

	for (size_t i(0); i < length; ++i) {
		cerr << "[" << i << "]\t";
		for (size_t j(0); j < 8u; ++j) {
			if (buffer[i] & (static_cast<unsigned char>(1u) << (7u - j))) {
				if (check == 1u) count++;
				++check;
				cerr << '1';
			}
			else {
				check = 0;
				cerr << '0';
			}
		}
		cerr << endl;
	}

	return count;
}

int
main()
{
	unsigned char buffer[] = {0xD9, 0x83, 0x03};

	cout << count_buffer(buffer, sizeof(buffer)) << endl;

	return 0;
}
