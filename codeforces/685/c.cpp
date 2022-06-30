#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    int mp_a[26]{}, mp_b[26]{};
    for (auto& c : a) mp_a[c - 'a']++;
    for (auto& c : b) mp_b[c - 'a']++;
    cout << ([&] {
      for (int i = 0; i < 26; i++) {
        if (mp_a[i] < mp_b[i]) {
          return false;
        } else if (mp_a[i] > mp_b[i]) {
          if ((mp_a[i] - mp_b[i]) % k != 0) {
            return false;
          } else {
            int move = mp_a[i] - mp_b[i];
            mp_a[i + 1] += move;
          }
        }
      }
      return true;
    }()
                 ? "Yes\n"
                 : "No\n");
  }
}
