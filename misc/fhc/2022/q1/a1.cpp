#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto minimal_represent(vector<int> s) {
  int n = int(s.size()), res = 0;
  s.reserve(2 * n);
  for (int i = 0; i < n; i++) s.push_back(s[i]);
  for (int i = 0; i < n;) {
    int j = i, k = i + 1;
    for (; k < 2 * n && s[j] <= s[k]; j++, k++) {
      if (s[j] < s[k]) j = i - 1;
    }
    res = i;
    while (i <= j) i += k - j;
  }
  return res;
}

auto is_repeated(vector<int>& s) {
  int n = int(s.size());
  vector<int> nex(n);
  for (int i = 1, j = 0; i < n; i++) {
    while (j && s[j] != s[i]) j = nex[j - 1];
    if (s[j] == s[i]) j++;
    nex[i] = j;
  }
  return nex[n - 1] && n % (n - nex[n - 1]) == 0;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    if (k == 0) {
      cout << ((a == b) ? "YES\n" : "NO\n");
      continue;
    }

    int good = [&] {
      auto sa = minimal_represent(a);
      auto sb = minimal_represent(b);
      for (int i = 0; i < n; i++) {
        if (a[(sa + i) % n] != b[(sb + i) % n]) return 0;
      }
      return 1;
    }();

    if (!good) {
      cout << "NO\n";
      continue;
    }
    auto repeated = is_repeated(a);
    if (k == 1 && (a == b)) {
      cout << (repeated ? "YES\n" : "NO\n");
      continue;
    }
    if (n == 2 && !repeated) {
      if ((a == b) == (k % 2 == 0)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    cout << "YES\n";
  }
}
