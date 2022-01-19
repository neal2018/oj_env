#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) { return rng() % r; }
int main() {
  int k = 100;
  int n = 5;
  int a[5] = {0, 0, 0, 0, 1};
  long long ans = 0;  // create a 64-bit signed variable which is initially equal to 0
  for (int i = 1; i <= k; i++) {
    int idx = rnd(0, n - 1);
    ans += a[idx];
    a[idx] -= (a[idx] % i);
  }
  cout << ans;
}
