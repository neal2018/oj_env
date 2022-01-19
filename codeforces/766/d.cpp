#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 1e6;
int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(MAX + 1);
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    a[x] = 1;
  }
  for (int i = MAX; i >= 1; i--) {
    if (a[i]) continue;
    int gg = 0;
    for (int j = i + i; j <= MAX; j += i) {
      if (a[j]) gg = gcd(gg, j);
    }
    if (gg == i) a[i] = 1, res++;
  }
  cout << res << "\n";
}