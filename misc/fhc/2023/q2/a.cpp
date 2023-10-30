
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  auto cin = Read{};
  int T;
  cin >> T;
  for (int test_case_no = 1; test_case_no <= T; test_case_no++) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;

    vector<vector<int>> seen(n, vector<int>(m));
    map<array<int, 2>, int> mp;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != 'W') continue;
        if (seen[i][j] != 0) continue;
        vector<array<int, 2>> q{{i, j}}, nq;
        seen[i][j] = 1;
        int cnt = 1;
        set<array<int, 2>> border;
        for (; q.size(); swap(nq, q), nq.clear()) {
          for (auto& [x, y] : q) {
            for (auto& [dx, dy] : vector<array<int, 2>>{{0, 1}, {0, -1}, {1, -0}, {-1, 0}}) {
              auto xx = x + dx, yy = y + dy;
              if (!(0 <= xx && xx < n && 0 <= yy && yy < m)) continue;
              if (a[xx][yy] == 'B') {
                continue;
              } else if (a[xx][yy] == '.') {
                if (border.size() < 2) border.insert({xx, yy});
              } else if (seen[xx][yy] == 0) {
                seen[xx][yy] = 1, cnt++;
                nq.push_back({xx, yy});
              }
            }
          }
        }
        if (border.size() == 1) {
          auto [x, y] = *border.begin();
          mp[{x, y}] += cnt;
        }
      }
    }
    int res = 0;
    for (auto& [k, v] : mp) {
      res = max(res, v);
    }
    cout << "Case #" << test_case_no << ": " << res << "\n";
    // if (res > 0) {
    //   cout << "Case #" << test_case_no << ": "
    //        << "YES"
    //        << "\n";
    // } else {
    //   cout << "Case #" << test_case_no << ": "
    //        << "NO"
    //        << "\n";
    // }
  }
}
