
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Read {
  static constexpr int SIZE = 1 << 16;
  static inline char buf[SIZE], *head, *tail;
  static char get_char() {
    if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
    return *head++;
  }
  static string read_s() {
    string str;
    char c = get_char();
    while (c == ' ' || c == '\n' || c == '\r') c = get_char();
    while (c != ' ' && c != '\n' && c != '\r') str += c, c = get_char();
    return str;
  }
  template <typename T>
  Read& operator>>(T& x) {
    int f = 1;
    char c = get_char();
    for (x = 0; !isdigit(c); c = get_char()) (c == '-') && (f = -1);
    for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
    return x *= f, *this;
  }
  Read& operator>>(string& x) { return x = read_s(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
};

auto manacher(vector<int>& s) {
  vector<int> t = {-2, -1};
  // for (auto& c : s) t += c, t += "#";
  for (auto& c : s) t.push_back(c), t.push_back(-1);
  t.push_back(-3);
  ll n = t.size(), r = 0, c = 0;
  vector<ll> p(n, 0);
  for (ll i = 1; i < n - 1; i++) {
    if (i < r + c) p[i] = min(p[2 * c - i], r + c - i);
    while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
    if (i + p[i] > r + c) r = p[i], c = i;
  }
  // i -> (2 * i + 1, 2 * i + 2)
  return p;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  auto cin = Read{};
  int T;
  cin >> T;
  for (int test_case_no = 1; test_case_no <= T; test_case_no++) {
    int n;
    cin >> n;
    auto wing = n;
    n *= 2;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) a.push_back(a[i]);
    auto p = manacher(a);
    int res = -1;
    int prev = -1;
    set<int> diff;
    auto check = [&](int i) {
      if (p[i] >= n) {
        if (prev != -1 && diff.count(i - prev)) return;
        auto cur_diff = i - prev;
        diff.insert(cur_diff), prev = i;
        int shift = ((i - (n + 1)) / 2 + n) % n;
        if ([&] {
              // [i/2 - wing  , i/2 - 1]
              int l = i / 2 - wing, r = i / 2 - 1;
              while (l < r) {
                if (a[l] >= a[r]) return false;
                l++, r--;
              }
              return true;
            }()) {
          res = shift;
        }
      }
    };

    for (int i = n + 1; i < int(p.size()) && res == -1; i += 2) {
      check(i);
    }

    cout << "Case #" << test_case_no << ": " << res << "\n";
  }
}
