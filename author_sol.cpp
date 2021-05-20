#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n, a, b;
		cin >> n >> a >> b;
		// view the image in this repository for better understanding
		// convert 'a' and 'b' into their binary representation using bitsets
		string a_binary = bitset<30>(a).to_string();
		string b_binary = bitset<30>(b).to_string();
		int a1 = 0;
		int b1 = 0;
		for (int i = 30 - n; i < 30; i++) {
			if (a_binary[i] == '1') {
				// count the number of '1' bits in 'a'
				a1++;
			}
			if (b_binary[i] == '1') {
				// count the number of '1' bits in 'b'
				b1++;
			}
		}
		auto Power = [&](int x, int y) {
			int res = 1;
			while (y > 0) {
				if (y & 1) {
					res *= x;
				}
				x *= x;
				y /= 2;
			}
			return res;
		};
		// calculate the '0' bits in 'a'
		int a0 = n - a1;
		// calculate the '0' bits in 'b'
		int b0 = n - b1;
		// calculate the maximum number of '1' bits that can be
		// place in the MSB (Most Significant Bit) side of a binary
		// min(a1, b0) = pair the '1' bits of 'a' to the '0' bits of 'b'
		// min(a0, b1) = pair the '1' bits of 'b' to the '0' bits of 'a'
		// add these two values together to produce the maximum number of 
		// '1' bits needed to be placed in the MSB
		int xors = min(a1, b0) + min(a0, b1);
		long long ans = 0;
		// start placing '1' bits from 'n' - 1 (since it will end in 2 ^ 0)
		int p = n - 1;
		// run the loop 'xors' times
		for (int i = 0; i < xors; i++) {
			// calculate the digit by adding the value of every '1' bit that
			// is placed in a power of 2
			ans += Power(2, p--);
		}
		cout << ans << '\n';
	}
	return 0;
}
