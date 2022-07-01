#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  auto sum = accumulate(a.begin(), a.end(), 0);
  auto maxi = *max_element(a.begin(), a.end());
  cout << (sum > 2 * maxi ? "YES\n" : "NO\n");
}
