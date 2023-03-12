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
    string zero = "0";
    vector memo(n, vector<string>(k + 1));
    auto dfs = [&](auto&& self, int cur, int used) -> string {
      if (cur >= n) return zero;
      if (used == k) return memo[cur][used] = s.substr(cur);
      if (memo[cur][used].size()) return memo[cur][used];
      int base = max((n + k) / (k + 1), 1);
      string res = "";
      for (auto len : {base - 1, base + 1, base, base - 2}) {
        if (len <= 0 || len + cur > n) continue;
        auto t1 = s.substr(cur, len);
        auto t2 = self(self, cur + len, used + 1);
        auto sum = add(t1, t2);
        if (is_smaller(sum, res)) swap(res, sum);
      }
      // cout << cur << " " << used << " " << res << "\n";
      return memo[cur][used] = res;
    };
    auto res = dfs(dfs, 0, 0);
    cout << res << "\n";
  }
}
