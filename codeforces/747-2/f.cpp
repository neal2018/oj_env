#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, s, n, k;
  cin >> T;
  while (T--) {
    cin >> s >> n >> k;
    if (k > s) {
      cout << "NO\n";
    } else if (k == s) {
      cout << "YES\n";
    } else {
      ll q = s / (k * 2), r = s % (k * 2), maxi = q * k + min(r + 1, k);
      cout << (maxi <= n ? "YES\n" : "NO\n");
    }
  }
}