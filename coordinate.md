# 座標・グリッド問題の基本パターン

## 座標を値として持つ：pair

```cpp
pair<int,int> p = {3, 5};
int x = p.first;   // 3
int y = p.second;  // 5

// 構造化束縛（C++17）
auto [x, y] = p;
```

vectorに複数の座標を入れる：

```cpp
vector<pair<int,int>> points;
points.push_back({1, 2});
points.push_back({3, 4});

for (auto [x, y] : points) {
    cout << x << " " << y << "\n";
}
```

### pairのソート

```cpp
// x座標で昇順、同じなら y座標で昇順（デフォルト）
sort(points.begin(), points.end());

// y座標で昇順にしたい場合
sort(points.begin(), points.end(), [](auto& a, auto& b) {
    return a.second < b.second;
});
```

---

## 距離の計算

### マンハッタン距離（グリッド上の移動コスト）

```cpp
int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
```

### ユークリッド距離（斜線あり）

```cpp
#include <cmath>
double euclid(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
// 距離の比較だけなら sqrt を省いて二乗のまま比較するほうが精度が良い
long long euclid_sq(int x1, int y1, int x2, int y2) {
    return (long long)(x1-x2)*(x1-x2) + (long long)(y1-y2)*(y1-y2);
}
```

---

## 4方向・8方向の移動

```cpp
// 4方向（上・下・左・右）
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 8方向（斜め含む）
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
```

グリッドBFSのテンプレートは → [grid.md](grid.md)

---

## 座標変換

### 1次元インデックス ↔ 2次元座標

グリッドを1次元配列で管理したいとき（BFSのキューに整数で入れたいなど）。

```cpp
// (i, j) → 1次元インデックス
int idx = i * W + j;

// 1次元インデックス → (i, j)
int i = idx / W;
int j = idx % W;
```

### 1-indexed を 0-indexed に変換

問題文は `1 ≤ x ≤ N` でも配列は 0-indexed なので：

```cpp
cin >> x >> y;
x--; y--;  // 0-indexed に変換
grid[x][y];
```

---

## 座標圧縮

座標が大きくても「相対的な大小関係」だけ必要な場合に使う。

```cpp
vector<int> xs = {100, 300, 200, 100};

// 重複除去してソート
vector<int> sorted_xs = xs;
sort(sorted_xs.begin(), sorted_xs.end());
sorted_xs.erase(unique(sorted_xs.begin(), sorted_xs.end()), sorted_xs.end());

// 元の値 → 圧縮後インデックス
for (int x : xs) {
    int idx = lower_bound(sorted_xs.begin(), sorted_xs.end(), x) - sorted_xs.begin();
    // 100→0, 200→1, 300→2
}
```

---

## チェックリスト

- [ ] 座標を持ち回すなら `pair<int,int>` か構造化束縛で受ける
- [ ] 距離比較だけなら `sqrt` を使わず二乗で比較（精度向上・高速化）
- [ ] 問題文が 1-indexed なら `x--; y--;` で 0-indexed に変換
- [ ] 大きな座標値が出てきたら座標圧縮を疑う
- [ ] `long long` のオーバーフローに注意（距離の二乗は `(int)*(int)` で溢れることがある）
