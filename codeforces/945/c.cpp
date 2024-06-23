#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<int> a(m);
    for (auto& x : a) std::cin >> x, x--;
    std::string c;
    std::cin >> c;
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    std::sort(c.begin(), c.end());
    for (int i = 0; i < a.size(); i++) {
      s[a[i]] = c[i];
    }
    std::cout << s << "\n";
  }
}
