#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n, -1), deg(n);
    for (int i = 1; i < n; i++) cin >> a[i], a[i]--, deg[a[i]]++;
    string s;
    cin >> s;
    vector<ll> q, nq, cnt(n);
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) q.push_back(i);
    }
    ll res = 0;
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        cnt[node] += (s[node] == 'B' ? 1 : -1);
        if (cnt[node] == 0) res++;
        if (a[node] == -1) continue;
        cnt[a[node]] += cnt[node];
        deg[a[node]]--;
        if (deg[a[node]] == 0) {
          nq.push_back(a[node]);
        }
      }
    }
    cout << res << "\n";
  }
}
