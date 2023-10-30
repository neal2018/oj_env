
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
    int n;
    cin >> n;
    vector<int> parent(n, -1);
    vector<vector<int>> g(n);
    for (int i = 1, p; i < n; i++) {
      cin >> p, p--, parent[i] = p;
      g[p].push_back(i);
    }
    vector<int> child_map(n, -1), mapping(n, -1);
    for (int i = 0; i < n; i++) {
      if (g[i].size() == 1) child_map[i] = g[i][0];
    }
    int new_n = 0;
    for (int i = 0; i < n; i++) {
      if (g[i].size() != 1) mapping[i] = new_n++;
    }
    function<int(int)> get_mapping = [&](int i) {
      if (mapping[i] != -1) return mapping[i];
      return mapping[i] = get_mapping(child_map[i]);
    };
    for (int i = 0; i < n; i++) {
      if (g[i].size() == 1) {
        mapping[i] = get_mapping(i);
      }
    }

    vector<int> new_parent(new_n, -2);
    for (int i = 0; i < n; i++) {
      if (g[i].size() == 1) continue;
      if (new_parent[mapping[i]] != -2) continue;
      auto node = parent[i];
      while (node != -1 && g[node].size() == 1) {
        node = parent[node];
      }
      auto new_p = node;
      if (new_p != -1) new_p = mapping[new_p];
      new_parent[mapping[i]] = new_p;
    }

    map<string, set<int>> str2node;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      vector<string> v(t);
      for (auto& x : v) {
        cin >> x;
        str2node[x].insert(mapping[i]);
      }
    }

    vector<int> child_cnt(new_n);
    for (int i = 0; i < new_n; i++) {
      if (new_parent[i] != -1) child_cnt[new_parent[i]]++;
    }
    int leaf_cnt = 0;
    for (int i = 0; i < new_n; i++) leaf_cnt += (child_cnt[i] == 0);

    int res = 0;
    for (auto& [s, st] : str2node) {
      if (st.size() < leaf_cnt) continue;

      vector<int> valid(new_n);
      for (auto& x : st) valid[x] = 1;
      vector<int> q, nq;
      vector<int> ask(new_n);
      for (int i = 0; i < new_n; i++) {
        if (child_cnt[i] == 0) q.push_back(i), ask[i] = 1;
      }
      if ([&] {
            auto t = child_cnt;
            for (; q.size(); swap(q, nq), nq.clear()) {
              for (auto& x : q) {
                if (ask[x] > 1) return false;
                if (valid[x]) ask[x]--;
                if (new_parent[x] != -1) {
                  ask[new_parent[x]] += ask[x];
                  if ((--t[new_parent[x]]) == 0) {
                    nq.push_back(new_parent[x]);
                  }
                }
              }
            }
            return true;
          }()) {
        res++;
      }
    }
    cout << "Case #" << test_case_no << ": " << res << "\n";
  }
}
