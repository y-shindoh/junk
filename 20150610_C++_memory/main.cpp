/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	main.cpp
 * @brief	C++における多重継承時のオブジェクト内のメモリ配置の確認
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstddef>
#include <cstdio>

class Father
{
public:
	char value_f_;

	Father()
		: value_f_(0)
		{
			;
		}
};

class Mother
{
public:
	short value_m_;

	Mother()
		: value_m_(0)
		{
			;
		}
};

class Child1
	: public Father,
	  public Mother
{
public:
	int value_c_;

	Child1()
		: value_c_(0)
		{
			;
		}
};

class Child2
	: public Mother,
	  public Father
{
public:
	int value_c_;

	Child2()
		: value_c_(0)
		{
			;
		}
};

int
main()
{
	Father f;
	std::printf("f: %p\n", &f);
	std::printf("f.value_f_: %p\n", &f.value_f_);

	std::printf("----\n");

	Mother m;
	std::printf("m: %p\n", &m);
	std::printf("m.value_m_: %p\n", &m.value_m_);

	std::printf("----\n");

	Child1 c1;
	std::printf("c1: %p\n", &c1);
	std::printf("c1.value_f_: %p\n", &c1.value_f_);	// パディングあり
	std::printf("c1.value_m_: %p\n", &c1.value_m_);
	std::printf("c1.value_c_: %p\n", &c1.value_c_);

	std::printf("----\n");

	Child2 c2;
	std::printf("c2: %p\n", &c2);
	std::printf("c2.value_m_: %p\n", &c2.value_m_);	// 継承順
	std::printf("c2.value_f_: %p\n", &c2.value_f_);	// パディングあり
	std::printf("c2.value_c_: %p\n", &c2.value_c_);

	return 0;
}
