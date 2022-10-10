#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  int i = n / 2 - 1, j = n / 2;
  int cnt = 0;
  while (cnt < n) {
    if (cnt % 2 == 1) {
      cout << a[i] << " ", cnt++, i--;
    } else {
      cout << a[j] << " ", cnt++, j++;
    }
  }
}
