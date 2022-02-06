#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, l, r;
  ll res = 0;
  string s;
  cin >> n >> l >> r >> s;
  vector<int> a(n, 3);
  for (int i = 0; i < n; i++) {
    if (isalpha(s[i]) && isupper(s[i])) a[i] = 0;
    if (isalpha(s[i]) && islower(s[i])) a[i] = 1;
    if (isdigit(s[i])) a[i] = 2;
  }
  int left = 0;
  vector<int> cnt(4);
  auto check = [&]() { return ((cnt[0] > 0) + (cnt[1] > 0) + (cnt[2] > 0) + (cnt[3] > 0)) >= 3; };
  for (int right = 0; right < n; right++) {
    cnt[a[right]]++;
    int good = 0;
    if (check()) good = 1;
    // cout << good << endl;
    while (check()) {
      cnt[a[left++]]--;
    }
    if (good) {
      left--;
      cnt[a[left]]++;
    }
    // [left, right]
    // cout << left << " " << right << "\n";
    ll leftmost = max(0, right - r + 1);
    if (good && left >= leftmost && (right - l + 1) >= 0) {
      ll leftright = min(left, right - l + 1);
      // cout << "\n" << leftmost << " " << leftright << "\n\n";
      res += leftright - leftmost + 1;
    }
  }
  cout << res << "\n";
}