#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    array<int, 26> freq{};
    int res = 0;
    for (auto& c : s) {
      if (islower(c)) {
        int cur = c - 'a';
        if (freq[cur] < 0) res++;
        freq[cur]++;
      } else {
        int cur = c - 'A';
        if (freq[cur] > 0) res++;
        freq[cur]--;
      }
    }
    for (auto& x : freq) {
      int add = min(k, abs(x / 2));
      k -= add, res += add;
    }
    cout << res << "\n";
  }
}
