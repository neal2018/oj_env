#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0, x; i < 4 * n - 1; i++) {
    cin >> x, x--;
    a[x]++;
  }
  cout << find(a.begin(), a.end(), 3) - a.begin() + 1 << "\n";
}
