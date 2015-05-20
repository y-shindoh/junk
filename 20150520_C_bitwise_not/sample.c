/* -*- coding: utf-8 -*- */
/**
 * @file	sample.c
 * @brief	ビット反転演算子に関する確認
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <stdio.h>

int 
main(void)
{
	printf("sizeof(~(unsigned char)0) => %lu\n", sizeof(~(unsigned char)0));
	printf("sizeof(~(unsigned int)0) => %lu\n", sizeof(~(unsigned int)0));
	printf("sizeof(~(unsigned long int)0) => %lu\n", sizeof(~(unsigned long int)0));

	printf("sizeof(~(char)0) => %lu\n", sizeof(~(char)0));
	printf("sizeof(~(int)0) => %lu\n", sizeof(~(int)0));
	printf("sizeof(~(long int)0) => %lu\n", sizeof(~(long int)0));

	printf("(double)~(unsigned char)0 => %lG\n", (double)~(unsigned char)0);
	printf("(double)~(unsigned int)0 => %lG\n", (double)~(unsigned int)0);
	printf("(double)~(unsigned long int)0 => %lG\n", (double)~(unsigned long int)0);

	printf("(double)~(char)0 => %lG\n", (double)~(char)0);
	printf("(double)~(int)0 => %lG\n", (double)~(int)0);
	printf("(double)~(long int)0 => %lG\n", (double)~(long int)0);

	return 0;
}
