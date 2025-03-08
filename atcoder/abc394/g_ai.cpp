#include <bits/stdc++.h>
using namespace std;

// ----- DSU (Disjoint Set Union) -----
struct DSU {
  vector<int> parent, rank;
  DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }
  int find(int a) { return parent[a] == a ? a : parent[a] = find(parent[a]); }
  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rank[a] < rank[b]) swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b]) rank[a]++;
    return true;
  }
};

// ----- Edge structure for grid edges -----
struct Edge {
  int u, v;
  int w;  // weight = min(F[u], F[v])
};

// Comparator: sort edges in descending order
bool cmpEdge(const Edge &a, const Edge &b) { return a.w > b.w; }

// ----- Main Function -----
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int H, W;
  cin >> H >> W;
  int n = H * W;
  vector<int> F(n);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> F[i * W + j];
    }
  }

  // ----- Build grid edges (only right and down neighbors) -----
  vector<Edge> edges;
  edges.reserve(n * 2);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int u = i * W + j;
      if (j + 1 < W) {
        int v = i * W + (j + 1);
        int w = min(F[u], F[v]);
        edges.push_back({u, v, w});
      }
      if (i + 1 < H) {
        int v = (i + 1) * W + j;
        int w = min(F[u], F[v]);
        edges.push_back({u, v, w});
      }
    }
  }
  sort(edges.begin(), edges.end(), cmpEdge);

  // ----- Build the Maximum Spanning Tree (MST) using DSU (Kruskal) -----
  DSU dsu(n);
  // Represent the MST as an adjacency list: (neighbor, edge_weight)
  vector<vector<pair<int, int>>> tree(n);
  for (auto &e : edges) {
    if (dsu.unite(e.u, e.v)) {
      tree[e.u].push_back({e.v, e.w});
      tree[e.v].push_back({e.u, e.w});
    }
  }

  // ----- Preprocess MST for LCA queries -----
  // We will compute:
  // - depth[v]: depth of vertex v in the tree.
  // - par0[v]: immediate parent of v in the tree.
  // - min0[v]: the edge weight from v to its parent.
  int LOG = 0;
  while ((1 << LOG) <= n) LOG++;
  vector<int> depth(n, 0), par0(n, -1), min0(n, INT_MAX);
  vector<bool> visited(n, false);

  // DFS to compute depth, parent and min0.
  function<void(int, int, int)> dfs = [&](int v, int p, int d) {
    visited[v] = true;
    par0[v] = p;
    depth[v] = d;
    for (auto &edge : tree[v]) {
      int nv = edge.first, w = edge.second;
      if (nv == p) continue;
      min0[nv] = w;
      dfs(nv, v, d + 1);
    }
  };
  // Start DFS from vertex 0 (grid is connected).
  min0[0] = INT_MAX;  // For root, set a very high value.
  dfs(0, -1, 0);

  // Build binary lifting tables:
  // parentBinary[k][v] = 2^k-th ancestor of v
  // minBinary[k][v] = minimum edge weight on the path from v to its 2^k-th ancestor.
  vector<vector<int>> parentBinary(LOG, vector<int>(n, -1));
  vector<vector<int>> minBinary(LOG, vector<int>(n, INT_MAX));
  for (int i = 0; i < n; i++) {
    parentBinary[0][i] = par0[i];
    minBinary[0][i] = min0[i];
  }
  for (int k = 1; k < LOG; k++) {
    for (int i = 0; i < n; i++) {
      if (parentBinary[k - 1][i] == -1) {
        parentBinary[k][i] = -1;
        minBinary[k][i] = INT_MAX;
      } else {
        parentBinary[k][i] = parentBinary[k - 1][parentBinary[k - 1][i]];
        minBinary[k][i] = min(minBinary[k - 1][i], minBinary[k - 1][parentBinary[k - 1][i]]);
      }
    }
  }

  // LCA query: returns the minimum edge weight along the path between u and v in the MST.
  auto queryMinEdge = [&](int u, int v) -> int {
    if (u == v) return F[u];  // Same vertex: no edge, so "g" is F[u].
    int res = INT_MAX;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int k = 0; diff; k++) {
      if (diff & 1) {
        res = min(res, minBinary[k][u]);
        u = parentBinary[k][u];
      }
      diff >>= 1;
    }
    if (u == v) return res;
    for (int k = LOG - 1; k >= 0; k--) {
      if (parentBinary[k][u] != parentBinary[k][v]) {
        res = min(res, minBinary[k][u]);
        res = min(res, minBinary[k][v]);
        u = parentBinary[k][u];
        v = parentBinary[k][v];
      }
    }
    res = min(res, minBinary[0][u]);
    res = min(res, minBinary[0][v]);
    return res;
  };

  // ----- Answer queries -----
  // For each query, we compute "g": the maximum floor X such that one can travel by walkways
  // between the two blocks staying at floor X (i.e. the minimum F along some path).
  // Then the answer is:
  //    if(g >= min(Y,Z)) => answer = |Y - Z|
  //    else => answer = (Y - g) + (Z - g)
  int Q;
  cin >> Q;
  while (Q--) {
    int A, B, Y, C, D, Z;
    cin >> A >> B >> Y >> C >> D >> Z;
    // Convert 1-indexed block (A,B) to vertex id:
    int u = (A - 1) * W + (B - 1);
    int v = (C - 1) * W + (D - 1);

    int g;
    if (u == v) {
      // Same block: can move vertically within the building.
      g = F[u];
    } else {
      g = queryMinEdge(u, v);
    }

    int lowFloor = min(Y, Z);
    int highFloor = max(Y, Z);
    long long ans;
    if (g >= lowFloor) {
      // We can choose an intermediate floor between Y and Z.
      ans = (long long)highFloor - lowFloor;
    } else {
      // Must go down/up to floor g first.
      ans = (long long)(Y - g) + (Z - g);
    }
    cout << ans << "\n";
  }

  return 0;
}
