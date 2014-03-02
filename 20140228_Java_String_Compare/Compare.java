/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @brief	sample code of O(n^3).
 */

import java.util.ArrayList;
import java.util.Random;

class Compare
{
	static int m = 1000 * 10000;
	static int n = 2 * 10000;

	public static void
	main(String arguments[]) {
		// prepare
		ArrayList<String> data = new ArrayList<String>();
		Random random = new Random(System.currentTimeMillis());
		int h;
		int k = m;
		if (k < n) k = n;
		for (int i = 0; i < k; ++i) {
			if (i % 10000 == 0) System.out.print("+");
			h = random.nextInt(k);
			data.add(String.format("%X", h));
		}
		System.out.println("");
		// O(n^3)
		long x = 0;
		for (int i = 0; i < m; ++i) {
			if (i % 10000 == 0) System.out.print(".");
			// O(n^2)
			for (int j = 0; j < n; ++j) {
				// O(n^1)
				if (data.get(i) == data.get(j)) ++x;
			}
		}
		System.out.printf("[%d]\n", x);
	}
}
