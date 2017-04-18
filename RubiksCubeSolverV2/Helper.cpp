#include "stdafx.h"
#include "Helper.h"

int Helper::factorial(int x, int result) {
	if (x <= 1) return result; else return factorial(x - 1, x * result);
}

int Helper::C(int n, int k) {
	if (n < k) return 0;
	else {
		int s, j;
		s = 1;
		if (k > n / 2) k = n - k;
		for (j = 1; j <= k; j++) {
			s = (s*n) / j;
			n--;
		}
		return s;
	}
	


}