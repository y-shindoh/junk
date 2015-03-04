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
count_buffer(const void* buffer,
			 const size_t length)
{
	size_t count(0);
	bool flag_1(false);
	bool flag_2(false);
	unsigned char c;

	for (size_t i(0); i < length; ++i) {
		c = (static_cast<const unsigned char*>(buffer))[i];
		cerr << "[" << i << "]";
		for (size_t j(0); j < 8u; ++j) {
			if (c & (1u << (7u - j))) {
				if (flag_1) {
					if (!flag_2) count++;
					flag_2 = true;
				}
				else {
					flag_1 = true;
				}
				cerr << " +";
			}
			else {
				flag_1 = flag_2 = false;
				cerr << " -";
			}
		}
		cerr << endl;
	}

	return count;
}

int
main()
{
	char buffer[] = {0x19, 0x83, 0x03};

	cout << count_buffer((void *)&buffer, sizeof(buffer)) << endl;

	return 0;
}
