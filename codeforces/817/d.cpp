#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SIZE = 30;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    priority_queue<ll> pq;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        pq.push((n - i - 1) - i);
        res += i;
      } else {
        pq.push(i - (n - i - 1));
        res += (n - i - 1);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (pq.size() && pq.top() > 0) {
        res += pq.top();
        pq.pop();
      }
      cout << res << ' ';
    }
    cout << "\n";
  }
}
