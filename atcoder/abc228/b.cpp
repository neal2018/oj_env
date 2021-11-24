#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  x--;
  vector<int> a(n), seen(n);
  for (auto& t : a) cin >> t, t--;
  while (true) {
    seen[x] = 1;
    if (seen[a[x]]) break;
    seen[a[x]] = 1, x = a[x];
  }
  cout << accumulate(seen.begin(), seen.end(), 0) << endl;
}