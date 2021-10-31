#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct GSAM {
  vector<unordered_map<int, int>> e = {{}};  // the labeled edges from node i
  vector<int> parent = {-1};                 // the parent of i
  vector<int> length = {0};                  // the length of the longest string

  int extend(int c, int p) {  // character, last
    bool f = true;            // if already exist
    int r = 0;                // potential new node
    if (!e[p].count(c)) {     // only extend when not exist
      f = false;
      e.emplace_back();
      parent.push_back(0);
      length.push_back(length[p] + 1);
      r = e.size() - 1;
      for (; ~p && !e[p].count(c); p = parent[p]) {
        e[p][c] = r;  // update parents
      }
    }
    if (f || ~p) {
      int q = e[p][c];
      if (length[q] == length[p] + 1) {
        if (f) return q;
        parent[r] = q;
      } else {
        e.push_back(e[q]);
        parent.push_back(parent[q]);
        length.push_back(length[p] + 1);
        int qq = parent[q] = e.size() - 1;
        for (; ~p && e[p][c] == q; p = parent[p]) {
          e[p][c] = qq;
        }
        if (f) return qq;
        parent[r] = qq;
      }
    }
    return r;
  }
};

vector<string> solve(vector<char>& letters, vector<string>& bannedWords, int n) {
  auto gsam = GSAM();
  int p = 0;
  vector<int> is_ended;
  for (auto& s : bannedWords) {
    int p = 0;
    for (auto& c : s) {
      p = gsam.extend(c, p);
    }
    is_ended.resize(gsam.parent.size());
    is_ended[p] = 1;
  }
  vector<string> ans;
  function<void(int, int, int, string&&)> dfs = [&](int i, int state, int full, string&& curr) {
    if (i >= n) {
      ans.push_back(curr);
      return;
    }
    for (auto c : letters) {
      int p = state;
      while (~p && !gsam.e[p].count(c)) {
        p = gsam.parent[p];
        full = 1;
      }
      if (p != state) gsam.parent[state] = p;
      int next_state = (p == -1 ? 0 : gsam.e[p][c]);
      full = (p == -1 ? 0 : (full && (gsam.length[next_state] - gsam.length[p] == 1)));
      if (full == 1 && p != -1 && is_ended[gsam.e[p][c]] == 1) {
        continue;
      }
      dfs(i + 1, next_state, full, curr + c);
    }
  };
  dfs(0, 0, 1, "");
  return ans;
}

int main(int argc, char const* argv[]) {
  vector<char> letters = {'a', 'b', 'c'};
  vector<string> bannedWords = {"aa", "bc", "c"};
  auto ans = solve(letters, bannedWords, 3);
  for (auto& s : ans) cout << s << endl;
}