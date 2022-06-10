#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<array<int, 3>> event;
    event.reserve(2 * n);
    for (int i = 0, x; i < n; i++) {
      cin >> x, event.push_back({x, i, 1});
    }
    for (int i = 0, x; i < n; i++) {
      cin >> x, event.push_back({x, i, -1});
    }
    sort(event.begin(), event.end());
    vector<int> start(n), res(n);
    deque<int> q;
    int cur = -1;
    for (auto& [x, id, is_new] : event) {
      if (is_new == 1) {
        q.push_back(id);
        if (cur == -1) {
          cur = q.front();
          q.pop_front();
          start[cur] = x;
        }
      } else {
        res[id] = x - start[id];
        cur = -1;
        if (q.size()) {
          cur = q.front();
          q.pop_front();
          start[cur] = x;
        }
      }
    }
    for (auto& x : res) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
