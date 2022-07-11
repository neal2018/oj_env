#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  ll mini = *min_element(a.begin(), a.end());
  ll maxi = *max_element(a.begin(), a.end());
  cout << (maxi - mini) * n << "\n";
}
