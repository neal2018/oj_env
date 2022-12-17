#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (auto& s : a) std::cin >> s;
  if ([&] {
        if (std::set(a.begin(), a.end()).size() != n) {
          return false;
        }
        std::set st1{'H', 'D', 'C', 'S'};
        std::set st2{'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        for (auto& s : a) {
          if (st1.count(s[0]) == 0) return false;
          if (st2.count(s[1]) == 0) return false;
        }
        return true;
      }()) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
