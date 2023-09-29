#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  std::string s;
  cin >> s;
  std::set<int> a, b;
  for (int i = 0; i < n + 1; i++) {
    ((s[i] == 'A') ? a : b).insert(i);
  }
  for (int i = 0; i < n; i++) {
    auto kill = [&](auto& my, auto& other) {
      if (my.size() > 0) {
        my.erase(my.begin());
      } else {
        other.erase(--other.end());
      }
    };
    if (i % 2 == 0) {
      kill(b, a);
    } else {
      kill(a, b);
    }
    if (a.size() && (b.size() == 0 || *a.begin() < *b.begin())) {
      std::cout << "Alice\n";
    } else {
      std::cout << "Bob\n";
    }
  }
}
