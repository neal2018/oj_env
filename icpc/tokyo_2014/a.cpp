#include <bits/stdc++.h>
using namespace std;

int dist(vector<int>& a, vector<int>& b) {
  int n = (int)a.size();
  vector<int> pos1a, pos1b;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) pos1a.push_back(i);
    if (b[i] == 1) pos1b.push_back(i);
  }
  if (pos1a.size() != pos1b.size()) return INT_MAX;
  int ans = 0;
  for (int i = 0; i < pos1a.size(); i++) ans += abs(pos1a[i] - pos1b[i]);
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> b1, b2;
  int cur = 0;
  for (int i = 0; i < m; i++) {
    int w;
    cin >> w;
    for (int j = 0; j < w; j++) {
      b1.push_back(cur);
      b2.push_back(cur ^ 1);
    }
    cur ^= 1;
  }

  cout << min(dist(a, b1), dist(a, b2)) << '\n';
}