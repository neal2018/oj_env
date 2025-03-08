#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end(),
            [](const std::string& a, const std::string& b) { return a.size() < b.size(); });
  std::string res;
  for (const auto& x : a) res += x;
  std::cout << res << "\n";
}
