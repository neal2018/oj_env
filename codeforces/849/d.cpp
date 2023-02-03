#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> pre, post;
    for (auto& x : s) {
      post[x]++;
    }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
      post[s[i]]--;
      if (post[s[i]] == 0) {
        post.erase(s[i]);
      }
      pre[s[i]]++;
      res = max(res, int(pre.size() + post.size()));
    }
    cout << res << "\n";
  }
}
