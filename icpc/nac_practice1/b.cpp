#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main() {
  int n;
  cin >> n;

  vector<int> birthDay(365, -1);

  int oneIndex;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    cin >> s;

    int month = (s[0] - '0') * 10 + (s[1] - '0');
    int day = (s[3] - '0') * 10 + (s[4] - '0');

    int index = day - 1;

    if (month > 1) index += 31;
    if (month > 2) index += 28;
    if (month > 3) index += 31;
    if (month > 4) index += 30;
    if (month > 5) index += 31;
    if (month > 6) index += 30;
    if (month > 7) index += 31;
    if (month > 8) index += 31;
    if (month > 9) index += 30;
    if (month > 10) index += 31;
    if (month > 11) index += 30;

    oneIndex = index;
    birthDay[index] = 0;
  }

  int cur = 0;

  int ansIndex = oneIndex;
  int best = 0;

  for (int i = 0; i < 365; i++) {
    if (birthDay[(i + oneIndex) % 365] == 0) {
      cur = 0;
    } else {
      cur++;
      birthDay[(i + oneIndex) % 365] = cur;
    }
  }

  oneIndex = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 27;

  for (int i = 0; i < 365; i++) {
    if (birthDay[(i + oneIndex) % 365] > best) {
      ansIndex = (i + oneIndex) % 365;
      best = birthDay[(i + oneIndex) % 365];
    }
  }
  int ansMonth = 0;

  if (ansIndex >= 31) {
    ansIndex -= 31;
    ansMonth++;
    if (ansIndex >= 28) {
      ansIndex -= 28;
      ansMonth++;
      if (ansIndex >= 31) {
        ansIndex -= 31;
        ansMonth++;
        if (ansIndex >= 30) {
          ansIndex -= 30;
          ansMonth++;
          if (ansIndex >= 31) {
            ansIndex -= 31;
            ansMonth++;
            if (ansIndex >= 30) {
              ansIndex -= 30;
              ansMonth++;
              if (ansIndex >= 31) {
                ansIndex -= 31;
                ansMonth++;
                if (ansIndex >= 31) {
                  ansIndex -= 31;
                  ansMonth++;
                  if (ansIndex >= 30) {
                    ansIndex -= 30;
                    ansMonth++;
                    if (ansIndex >= 31) {
                      ansIndex -= 31;
                      ansMonth++;
                      if (ansIndex >= 30) {
                        ansIndex -= 30;
                        ansMonth++;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  ansMonth++;
  ansIndex++;

  if (ansMonth < 10) cout << '0';
  cout << ansMonth;
  cout << '-';
  if (ansIndex < 10) cout << '0';
  cout << ansIndex << nl;
}