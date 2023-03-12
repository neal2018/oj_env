#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_smaller(string_view a, string_view b) {
  if (b.size() == 0) return true;
  if (a.size() < b.size()) return true;
  if (a.size() > b.size()) return false;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] < b[i]) return true;
    if (a[i] > b[i]) return false;
  }
  return true;
}

string add(string_view a, string_view b) {
  string result;
  int carry = 0;
  int i = int(a.size()) - 1, j = int(b.size()) - 1;
  while (i >= 0 || j >= 0 || carry) {
    int num1 = i >= 0 ? a[i--] - '0' : 0;
    int num2 = j >= 0 ? b[j--] - '0' : 0;
    int sum = num1 + num2 + carry;
    result += sum % 10 + '0';
    carry = sum / 10;
  }
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string res = "";
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
      if (__builtin_popcount(mask) != k) continue;
      int prev = 0;
      string cur = "0";
      for (int i = 0; i < n - 1; i++) {
        if (mask & (1 << i)) {
          cur = add(cur, s.substr(prev, i - prev + 1));
          prev = i + 1;
        }
      }
      cur = add(cur, s.substr(prev, n - prev + 1));
      if (is_smaller(cur, res)) swap(res, cur);
    }
    cout << res << "\n";
  }
}
