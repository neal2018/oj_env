#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    auto one_count = std::count(a.begin(), a.end(), 1);
    if (n - one_count <= 2) {
      std::cout << "No\n";
      continue;
    }
    auto two_count = std::count(a.begin(), a.end(), 2);
    if (one_count + two_count == n) {
      std::cout << "No\n";
      continue;
    }
    auto st = std::set(a.begin(), a.end());
    if (st.size() >= 3) {
      std::cout << "Yes\n";
      continue;
    }
    if (n - one_count <= 3) {
      std::cout << "No\n";
      continue;
    }
    std::cout << "Yes\n";
  }
}
