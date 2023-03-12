#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  map<string, char> mp = {
      {"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'}, {"CUU", 'L'}, {"CUC", 'L'},
      {"CUA", 'L'}, {"CUG", 'L'}, {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AUG", 'M'},
      {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'}, {"UCU", 'S'}, {"UCC", 'S'},
      {"UCA", 'S'}, {"UCG", 'S'}, {"AGU", 'S'}, {"AGC", 'S'}, {"CCU", 'P'}, {"CCC", 'P'},
      {"CCA", 'P'}, {"CCG", 'P'}, {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
      {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'}, {"UAU", 'Y'}, {"UAC", 'Y'},
      {"CAU", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'}, {"AAU", 'N'}, {"AAC", 'N'},
      {"AAA", 'K'}, {"AAG", 'K'}, {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'},
      {"UGU", 'C'}, {"UGC", 'C'}, {"UGG", 'W'}, {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'},
      {"CGG", 'R'}, {"AGA", 'R'}, {"AGG", 'R'}, {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'},
      {"GGG", 'G'}, {"UAA", '?'}, {"UAG", '?'}, {"UGA", '?'},
  };

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = int(s.size());
    for (int i = 0; i < n; i += 3) {
      auto t = s.substr(i, 3);
      auto val = mp[t];
      if (val == '?') break;
      cout << val;
    }
    cout << "\n";
  }
}
