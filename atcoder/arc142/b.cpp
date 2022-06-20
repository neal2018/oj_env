#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAX = 5001;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), cnt(MAX);
  for (auto& x : a) cin >> x, cnt[x]++;
  for (auto& x : b) cin >> x, cnt[x]--;
  for (auto& x : cnt) {
    if (x) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = 0; i < n - 3; i++) {
    int j = int(find(a.begin(), a.end(), b[i]) - a.begin());
    a.erase(a.begin() + j);
    a.insert(a.begin() + i, b[i]);
    if ((j - i) & 1) {
      swap(a[i + 1], a[i + 2]);
    }
  }
  int f = 0;
  // n-3, n-2, n-1;
  vector<int> a_last(a.begin() + n - 3, a.end());
  vector<int> b_last(b.begin() + n - 3, b.end());
  for (int j = 0; j < 3; j++) {
    if (a_last == b_last) {
      f = 1;
      break;
    } else {
      a_last = {a_last[2], a_last[0], a_last[1]};
    }
  }
  if (f == 0) {
    set<ll> odd, even;
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        if (even.count(a[i])) {
          f = 1;
        } else {
          odd.insert(a[i]);
        }
      } else {
        if (odd.count(a[i])) {
          f = 1;
        } else {
          even.insert(a[i]);
        }
      }
    }
  }
  cout << (f ? "Yes\n" : "No\n");
}
