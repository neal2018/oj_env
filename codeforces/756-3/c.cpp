#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    deque<int> p{a[0]}, c;
    for (int i = 1, j = n - 1; i <= j;) {
      if (a[i] > a[j]) {
        p.push_front(a[i]);
        i++;
      } else {
        p.push_back(a[j]);
        j--;
      }
    }
    auto b = p;
    int i, j;
    for (i = 0, j = n - 1; i < j;) {
      if (b[i] < b[j]) {
        c.push_front(b[i]);
        i++;
      } else {
        c.push_back(b[j]);
        j--;
      }
    }
    int f = 0;
    c.push_front(b[i]);
    if (vector(c.begin(), c.end()) == a) f = 1;
    c.push_back(b[i]), c.pop_front();
    if (vector(c.begin(), c.end()) == a) f = 1;
    if (f) {
      for (auto& x : p) cout << x << " ";
      cout << '\n';
    } else {
      cout << "-1\n";
    }
  }
}