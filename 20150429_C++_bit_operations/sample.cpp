/* -*- coding: utf-8 -*- */

#include <cstdio>
#include <cstddef>

using namespace std;

template<typename Type>
void print_b(Type n)
{
	size_t h, k;

	for (size_t i(0); i < sizeof(Type); ++i) {
		h = sizeof(n) - i - 1;
		for (size_t j(0); j < 8; ++j) {
			k = 8 - j - 1;
			if (n & (1 << (h * 8 + k))) {
				printf("1");
			}
			else {
				printf("0");
			}
		}
		printf(" ");
	}
	printf("(%lu, 0x%lX)\n", (size_t)n, (size_t)n);
}

// see http://www.slideshare.net/KMC_JP/slide-www

int main(void)
{
	unsigned int i;	// 簡単にするために符号なし整数を扱う。

	printf("** 1になっている一番下のビットを算出\n");
	i = 0xF80;
	printf("i:\t\t");
	print_b(i);
	printf("~i:\t\t");
	print_b(~i);
	printf("~i + 1:\t\t");
	print_b(~i + 1);
	printf("i & (~i + 1):\t");
	print_b(i & (~i + 1));

	printf("** 1になっている一番下のビットを0に置換 (入力は自然数)\n");
	i = 0xF480;
	printf("i:\t\t");
	print_b(i);
	printf("i - 1:\t\t");
	print_b(i - 1);
	printf("i & (i - 1):\t");
	print_b(i & (i - 1));

	printf("** 2のべき乗か否かをチェック (入力は自然数, 0なら真)\n");
	i = 0x040;
	printf("i:\t\t");
	print_b(i);
	printf("i - 1:\t\t");
	print_b(i - 1);
	printf("i & (i - 1):\t");
	print_b(i & (i - 1));

	printf("** 1になっている一番上のビットを算出\n");
	i = 0x340F0;
	printf("i:\t\t\t");
	print_b(i);
	if (i & 0xFFFF0000) {
		i &= 0xFFFF0000;
		printf("i &= 0xFFFF0000:\t");
		print_b(i);
	}
	else {
		printf("i &= 0xFFFF0000:\tSKIP\n");
	}
	if (i & 0xFF00FF00) {
		i &= 0xFF00FF00;
		printf("i &= 0xFF00FF00:\t");
		print_b(i);
	}
	else {
		printf("i &= 0xFF00FF00:\tSKIP\n");
	}
	if (i & 0xF0F0F0F0) {
		i &= 0xF0F0F0F0;
		printf("i &= 0xF0F0F0F0:\t");
		print_b(i);
	}
	else {
		printf("i &= 0xF0F0F0F0:\tSKIP\n");
	}
	if (i & 0xCCCCCCCC) {
		i &= 0xCCCCCCCC;
		printf("i &= 0xCCCCCCCC:\t");
		print_b(i);
	}
	else {
		printf("i &= 0xCCCCCCCC:\tSKIP\n");
	}
	if (i & 0xAAAAAAAA) {
		i &= 0xAAAAAAAA;
		printf("i &= 0xAAAAAAAA:\t");
		print_b(i);
	}
	else {
		printf("i &= 0xAAAAAAAA:\tSKIP\n");
	}

	printf("** ビット列を逆転\n");
	i = 0xAC49BE38;
	printf("i:\n\t");
	print_b(i);
	printf("i = ((i & 0xFFFF0000) >> 16) | ((i & 0x0000FFFF) << 16):\n\t");
	i = ((i & 0xFFFF0000) >> 16) | ((i & 0x0000FFFF) << 16);	// マスク不要
	print_b(i);
	printf("i = ((i & 0xFF00FF00) >> 8) | ((i & 0x00FF00FF) << 8):\n\t");
	i = ((i & 0xFF00FF00) >> 8) | ((i & 0x00FF00FF) << 8);
	print_b(i);
	printf("i = ((i & 0xF0F0F0F0) >> 4) | ((i & 0x0F0F0F0F) << 4):\n\t");
	i = ((i & 0xF0F0F0F0) >> 4) | ((i & 0x0F0F0F0F) << 4);
	print_b(i);
	printf("i = ((i & 0xCCCCCCCC) >> 2) | ((i & 0x33333333) << 2):\n\t");
	i = ((i & 0xCCCCCCCC) >> 2) | ((i & 0x33333333) << 2);
	print_b(i);
	printf("i = ((i & 0xAAAAAAAA) >> 1) | ((i & 0x55555555) << 1):\n\t");
	i = ((i & 0xAAAAAAAA) >> 1) | ((i & 0x55555555) << 1);
	print_b(i);

	printf("** 1のビットの数を算出\n");
	i = 0xAC49BE38;
	printf("i:\n\t");
	print_b(i);
	printf("i = ((i & 0xAAAAAAAA) >> 1) + (i & 0x55555555):\n\t");
	i = ((i & 0xAAAAAAAA) >> 1) + (i & 0x55555555);
	print_b(i);
	printf("i = ((i & 0xCCCCCCCC) >> 2) + (i & 0x33333333):\n\t");
	i = ((i & 0xCCCCCCCC) >> 2) + (i & 0x33333333);
	print_b(i);
	printf("i = ((i & 0xF0F0F0F0) >> 4) + (i & 0x0F0F0F0F):\n\t");
	i = ((i & 0xF0F0F0F0) >> 4) + (i & 0x0F0F0F0F);
	print_b(i);
	printf("i = ((i & 0xFF00FF00) >> 8) + (i & 0x00FF00FF):\n\t");
	i = ((i & 0xFF00FF00) >> 8) + (i & 0x00FF00FF);
	print_b(i);
	printf("i = ((i & 0xFFFF0000) >> 16) + (i & 0x0000FFFF):\n\t");
	i = ((i & 0xFFFF0000) >> 16) + (i & 0x0000FFFF);	// 左側のマスクは不要
	print_b(i);

	return 0;
}
