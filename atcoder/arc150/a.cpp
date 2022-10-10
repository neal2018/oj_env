#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> one(n + 1), zero(n + 1);
    for (int i = 0; i < n; i++) {
      one[i + 1] = one[i] + (s[i] == '1');
      zero[i + 1] = zero[i] + (s[i] == '0');
    }
    int ways = 0;
    int total_one = int(count(s.begin(), s.end(), '1'));
    for (int i = 0; i + k <= n; i++) {
      if (zero[i + k] - zero[i] == 0 && one[i + k] - one[i] == total_one) {
        ways++;
      }
    }
    if (ways == 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
