/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @brief	sample code of O(n^3).
 */

import java.util.ArrayList;
import java.util.Random;

class Compare
{
	static int l = 1000 * 10000;
	static int m = 2 * 10000;
	static int n = 64;

	public static void
	main(String arguments[]) {
		// prepare
		ArrayList<Integer> data = new ArrayList<Integer>();
		Random random = new Random(System.currentTimeMillis());
		int k = m;
		if (k < n) k = n;
		for (int j = 0; j < k; ++j) {
			data.add(random.nextInt(k));
		}
		// O(n^3)
		long x = 0;
		for (int h = 0; h < l; ++h) {
			if (h % 1000 == 0) System.out.print(".");
			// O(n^2)
			for (int i = 0; i < m; ++i) {
				// O(n^1)
				for (int j = 0; j < n; ++j) {
					if (data.get(i) < data.get(j)) ++x;
				}
			}
		}
		System.out.printf("[%d]\n", x);
	}
}
