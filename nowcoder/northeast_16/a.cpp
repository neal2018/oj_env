#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SAM {
  int last = 0, SZ = 26;
  vector<vector<int>> e = {vector<int>(SZ, -1)};
  vector<int> parent = {-1}, length = {0};
  SAM(int n) { e.reserve(2 * n), parent.reserve(2 * n), length.reserve(2 * n); };
  void extend(int c) {
    e.push_back(vector<int>(SZ, -1)), parent.push_back(0), length.push_back(length[last] + 1);
    int p = last, r = last = (int)e.size() - 1;
    for (; p != -1 && e[p][c] == -1; p = parent[p]) e[p][c] = r;
    if (p != -1) {
      int q = e[p][c];
      if (length[q] == length[p] + 1) {
        parent[r] = q;
      } else {
        e.push_back(e[q]), parent.push_back(parent[q]), length.push_back(length[p] + 1);
        int qq = parent[q] = parent[r] = (int)e.size() - 1;
        for (; p != -1 && e[p][c] == q; p = parent[p]) e[p][c] = qq;
      }
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;

  vector<int> last;
  last.reserve(s.size());
  SAM sam(int(s.size()));
  for (auto& c : s) {
    sam.extend(c - 'a');
    last.push_back(sam.last);
  }

  ll sz = sam.e.size();
  vector<int> order(sz);
  {
    vector<int> c(sz + 1);
    for (int i = 1; i < sz; i++) c[sam.length[i]]++;
    for (int i = 1; i < sz; i++) c[i] += c[i - 1];
    for (int i = 1; i < sz; i++) order[c[sam.length[i]]--] = i;
    reverse(order.begin(), order.end());
  }

  vector<int> cnt(sz);
  for (auto& p : last) cnt[p]++;

  for (auto& node : order) {
    if (sam.parent[node] > 0) cnt[sam.parent[node]] += cnt[node];
  }

  vector<int> last_pos(sz);
  for (int i = 0; i < s.size(); i++) last_pos[last[i]] = i;

  for (auto& node : order) {
    if (sam.parent[node] > 0) {
      last_pos[sam.parent[node]] = max(last_pos[sam.parent[node]], last_pos[node]);
    }
  }

  vector<vector<int>> g(sz);
  for (int i = 0; i < sz; i++) {
    if (sam.parent[i] > 0) g[sam.parent[i]].push_back(i);
  }

  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    ll t_sz = t.size();
    deque<char> dq;
    for (ll i = t_sz - 1, p = 0; i >= 0; i--) {
      if (p == -1) {
        dq.push_front(t[i]);
      } else {
        if (i == t_sz - 1 || cnt[p] % 2 == 1) {
          dq.push_back(t[i]);
          p = sam.e[p][t[i] - 'a'];
        } else {
          dq.push_front(t[i]);
          ll len = dq.size();
          if (sam.length[p] < len) {
            [&] {
              for (auto& ne : g[p]) {
                if (sam.length[ne] >= len && s[last_pos[ne] - len + 1] == t[i]) {
                  p = ne;
                  return;
                }
              }
              p = 0;
            }();
          } else {
            if (s[last_pos[p] - len + 1] != t[i]) p = -1;
          }
        }
      }
    }
    for (auto& x : dq) cout << x;
    cout << "\n";
  }
}
