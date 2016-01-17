/* -*- coding: utf-8 -*- */
/**
 * @file	sample.cpp
 * @brief	TRIE木の単純な実装
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstdio>
#include <cassert>

/**
 * TRIE木のノード (二重連鎖木による実装)
 */
template<typename TYPE>
class Node
{
public:

	TYPE key_;	///< キーの1要素
	Node<TYPE>* sibling_;	///< 弟
	Node<TYPE>* child_;		///< 子

	/**
	 * コンストラクタ
	 * @param[in]	key	キーの1要素
	 */
	Node(const TYPE& key)
		: key_(key), sibling_(0), child_(0)
		{
			;
		}
};

/**
 * TRIE木にキーを追加
 * @param[in,out]	node	TRIE木の根
 * @param[in]	キー
 * @return	処理後のTRIE木の根
 */
template<typename TYPE>
Node<TYPE>*
add(Node<TYPE>* node,
	const TYPE* key)
{
	assert(key);

	if (node) {
		if (*key < node->key_) {
			Node<TYPE>* n = new Node<TYPE>(*key);
			n->sibling_ = node;
			if (*key) n->child_ = add<TYPE>(0, key+1);
			node = n;
		}
		else if (node->key_ < *key) {
			node->sibling_ = add<TYPE>(node->sibling_, key);
		}
		else {
			if (*key) node->child_ = add<TYPE>(node->child_, key+1);
		}
	}
	else {
		node = new Node<TYPE>(*key);
		if (*key) node->child_ = add<TYPE>(0, key+1);
	}

	return node;
}

/**
 * TRIE木からキーを探索
 * @param[in,out]	node	TRIE木の根
 * @param[in]	キー
 * @return	葉ノード (探索失敗時は 0)
 */
template<typename TYPE>
Node<TYPE>*
find(Node<TYPE>* node,
	 const TYPE* key)
{
	assert(key);

	while (node) {
		if (node->key_ != *key) {
			if (*key < node->key_) break;
			node = node->sibling_;
		}
		else{
			if (!*key) return node;
			++key;
			node = node->child_;
		}
	}

	return 0;
}

/**
 * TRIE木を削除
 * @param[in,out]	node	TRIE木の根
 */
template<typename TYPE>
void
clear(Node<TYPE>* node)
{
	if (node) {
		clear<TYPE>(node->child_);
		clear<TYPE>(node->sibling_);
		delete node;
	}
}

#define	N	7

/**
 * サンプル・コマンド
 */
int
main()
{
	Node<char>* trie(0);
	const char key[N][16] = {"array",
							 "bold",
							 "curry",
							 "cute",
							 "art",
							 "alert",
							 "dish"};

	if (3 < N) trie = add(trie, key[3]);
	for (int i(0); i + 2 < N; ++i) trie = add(trie, key[i]);

	for (int i(0); i < N; ++i) {
		std::printf("%s: %s\n", key[i], find(trie, key[i]) ? "yes" : "no");
	}

	clear(trie);

	return 0;
}
