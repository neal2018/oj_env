#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, m, x;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<int> a(101);
    for (int i = 0; i < n; i++) {
      cin >> x;
      a[x]++;
    }
    for (int i = 0; i < m; i++) {
      cin >> x;
      a[x]++;
    }
    int cnt = 0;
    for (int i = 0; i < 101; i++)
      if (a[i] == 2) cnt++;
    cout << cnt << '\n';
  }
}