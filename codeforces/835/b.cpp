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
    cout << transform_reduce(
                s.begin(), s.end(), 0, [](auto x, auto y) { return max(x, y); },
                [](auto c) { return c - 'a' + 1; })
         << "\n";
  }
}
