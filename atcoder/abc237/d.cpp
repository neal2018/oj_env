#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  vector<int> nex(n + 2);
  iota(nex.begin(), nex.end(), 0);
  nex[n + 1] = 0, nex[0] = n + 1;
  int cur = 0, pre = n + 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      nex[pre] = i + 1;
      nex[i + 1] = cur;
      cur = i + 1;
    } else {
      nex[i + 1] = nex[cur];
      nex[cur] = i + 1;
      pre = cur, cur = i + 1;
    }
  }
  for (cur = nex[n + 1]; cur != n + 1; cur = nex[cur]) {
    cout << cur << " ";
  }
  cout << "\n";
}
