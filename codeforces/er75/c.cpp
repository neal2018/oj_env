#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    string even, odd;
    for (auto c : s) {
      if ((c - '0') & 1) {
        odd += c;
      } else {
        even += c;
      }
    }
    string res;
    int i = 0, j = 0;
    while (i < even.size() && j < odd.size()) {
      if (even[i] < odd[j]) {
        res += even[i++];
      } else {
        res += odd[j++];
      }
    }
    while (i < even.size()) res += even[i++];
    while (j < odd.size()) res += odd[j++];
    cout << res << "\n";
  };
}
