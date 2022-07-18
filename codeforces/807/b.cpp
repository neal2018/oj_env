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
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    int left = 0;
    while (left < n && a[left] == 0) left++;
    int right = left;
    while (right < n && a[right] != 0) right++;
    ll res = 0;
    while (right < n) {
      res++;
      a[right]++;
      while (right < n && a[right] != 0) right++;
      a[left]--;
      while (left < n && a[left] == 0) left++;
    }
    ll extra = accumulate(a.begin(), a.end(), 0ll) - a.back();
    cout << res + extra << "\n";
  }
}
