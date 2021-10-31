#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms,
                            vector<vector<int>>& queries) {
        int n = rooms.size();
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            queries[i].push_back(i);
        }

        auto f = [](vector<int> a, vector<int> b) { return a[1] < b[1]; };
        sort(rooms.begin(), rooms.end(), f);
        sort(queries.begin(), queries.end(), f);

        set<int> s;
        int curr = n - 1;
        vector<int> ans(m, -1);
        for (int i = m - 1; i >= 0; i--) {
            while (curr >= 0 && rooms[curr][1] >= queries[i][1]) {
                s.insert(rooms[curr][0]);
                curr--;
            }
            if (s.empty()) {
                continue;
            }
            auto it = s.lower_bound(queries[i][0]);
            auto pre = prev(it);
            if (it == s.end()) {
                ans[queries[i][2]] = *pre;
            } else if (it == s.begin()) {
                ans[queries[i][2]] = *it;
            } else {
                if (*it - queries[i][0] >= queries[i][0] - *pre) {
                    ans[queries[i][2]] = *pre;
                } else {
                    ans[queries[i][2]] = *it;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    auto s = Solution();
    vector<vector<int>> a = {{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}};
    vector<vector<int>> b = {{2, 3}, {2, 4}, {2, 5}};
    auto res = s.closestRoom(a, b);
    return 0;
}

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            queries[i].push_back(i);  // record the original index
        }

        auto f = [](vector<int> a, vector<int> b) { return a[1] < b[1]; };
        sort(rooms.begin(), rooms.end(), f);
        sort(queries.begin(), queries.end(), f);

        set<int> s;  // save rooms fit the minSize
        vector<int> ans(m,-1); // to return
        int curr = n - 1;  // iter from large size to smaller size
        for (int i = m - 1; i >= 0; i--) {
            // iter from large Minsize to smaller Minsize
            while (curr >= 0 && rooms[curr][1] >= queries[i][1]) {
                s.insert(rooms[curr][0]);
                curr--;
            }
            if (s.empty()) { // no fitted room
                continue;
            } 
            
            // find the closet one
            auto it = s.lower_bound(queries[i][0]);
            auto pre = prev(it);
            if (it == s.end()) {
                ans[queries[i][2]] = *pre;
            } else if (it == s.begin()) {
                ans[queries[i][2]] = *it;
            } else {
                if (*it - queries[i][0] >= queries[i][0] - *pre) {
                    ans[queries[i][2]] = *pre;
                } else {
                    ans[queries[i][2]] = *it;
                }
            
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int room_size = rooms.size();
        int query_size = queries.size();
        for (int i = 0; i < query_size; i++) {
            queries[i].push_back(i);  // record the original index
        }

        auto f = [](vector<int> a, vector<int> b) { return a[1] < b[1]; };
        sort(rooms.begin(), rooms.end(), f);
        sort(queries.begin(), queries.end(), f);

        set<int> s;  // save rooms fit the minSize
        vector<int> ans(query_size); // to return
        int curr = room_size - 1;  // iter from large size to smaller size
        for (int i = query_size - 1; i >= 0; i--) {
            // iter from large Minsize to smaller Minsize
            while (curr >= 0 && rooms[curr][1] >= queries[i][1]) {
                s.insert(rooms[curr][0]);
                curr--;
            }
            if (s.empty()) { // no fitted room
                ans[queries[i][2]] = -1;
            } else {
                // find the closet one
                auto it = s.lower_bound(queries[i][0]);
                if (it == s.end()) {
                    ans[queries[i][2]] = *prev(it);
                } else if (it == s.begin()) {
                    ans[queries[i][2]] = *it;
                } else {
                    if (*it - queries[i][0] >= queries[i][0] - *prev(it)) {
                        ans[queries[i][2]] = *prev(it);
                    } else {
                        ans[queries[i][2]] = *it;
                    }
                }
            }
        }
        return ans;
    }
};