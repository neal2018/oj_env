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
    if (n % 2) {
      cout << "-1\n";
      continue;
    }
    if ([&] {
          for (char c = 'a'; c != 'z' + 1; c++) {
            if (count(s.begin(), s.end(), c) > n / 2) return true;
          }
          return false;
        }()) {
      cout << "-1\n";
      continue;
    }
    array<int, 26> freq = {};
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == s[n - 1 - i]) {
        freq[s[i] - 'a']++;
      }
    }
    int sum = accumulate(freq.begin(), freq.end(), 0);
    sort(freq.rbegin(), freq.rend());
    if (freq[0] * 2 <= sum) {
      cout << (sum + 1) / 2 << "\n";
      continue;
    }
    cout << freq[0] << "\n";
  }
}
