#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

auto longest_palindrome(string& s) {
  // init "abc" -> "^$a#b#c$"
  vector<char> t{'^', '#'};
  for (char c : s) t.push_back(c), t.push_back('#');
  t.push_back('$');
  // manacher
  int n = int(t.size()), r = 0, c = 0;
  vector<int> p(n, 0);
  for (int i = 1; i < n - 1; i++) {
    if (i < r + c) p[i] = min(p[2 * c - i], r + c - i);
    while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
    if (i + p[i] > r + c) r = p[i], c = i;
  }
  // s[i] -> p[2 * i + 2] (even), p[2 * i + 2] (odd)
  return p;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  auto work = [&](std::string s) {
    auto p = longest_palindrome(s);
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
      int p_index = i * 2 + 1;
      // check s[0] .. s[i-1] vs s[i] .. s[i+i-1]
      // cut start
      // check s[start] .. s[i-1] vs s[i] .. s[i+i-1-start]
      // len = (i-start)
      int wing = p[p_index] / 2;
      int len = i - start;
      if (wing >= len) {
        // cut from i-1
        start = i;
      }
    }
    return s.substr(start);
  };

  std::string s;
  std::cin >> s;
  s = work(s);
  std::reverse(s.begin(), s.end());
  s = work(s);
  std::reverse(s.begin(), s.end());
  std::cout << s.size() << "\n";
}
