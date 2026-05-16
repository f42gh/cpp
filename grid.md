# グリッド（2次元配列）の競プロ操作

## 宣言と初期化

```cpp
int H, W;
cin >> H >> W;

// H行W列、全部0で初期化
vector<vector<int>> grid(H, vector<int>(W, 0));
```

## 入力の読み込み

### 整数グリッド
```cpp
for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
        cin >> grid[i][j];
```

### 文字グリッド（'.'や'#'の迷路）
```cpp
vector<string> grid(H);
for (int i = 0; i < H; i++) cin >> grid[i];

// アクセス
char c = grid[i][j];
```

> 文字グリッドは `vector<string>` が書きやすい。変更が多いなら `vector<vector<char>>` でもいい。

---

## 問題文を座標に落とす

グリッド問題は「図形として眺める」だけだと実装しづらいことがある。
その場合は、まず条件を **座標の式** に直す。

たとえば:

- 上のマス: `(i - 1, j)`
- 右のマス: `(i, j + 1)`
- 長方形 `(h1..h2, w1..w2)` 内で点対称な相手: `(h1 + h2 - i, w1 + w2 - j)`

図で考えた内容を `(i, j)` の式にできると、そのままループで書ける。

---

## 上下左右の移動（最頻出パターン）

```cpp
// 4方向（上・下・左・右）
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    // 範囲チェック（必ず入れる）
    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

    // 有効なマスに対して処理
}
```

8方向（斜め含む）にするには dx/dy を8要素にする：

```cpp
int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
```

---

## 距離管理（BFS の定番）

```cpp
vector<vector<int>> dist(H, vector<int>(W, -1));  // -1 = 未訪問

queue<pair<int,int>> q;
q.push({0, 0});
dist[0][0] = 0;

while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (dist[nx][ny] != -1) continue;  // 訪問済みスキップ

        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
    }
}
```

---

## 部分長方形の全探索

グリッドで「長方形領域」を数える問題はかなり多い。
その場合、まず長方形の四辺を固定する。

```cpp
for (int h1 = 0; h1 < H; h1++) {
    for (int h2 = h1; h2 < H; h2++) {
        for (int w1 = 0; w1 < W; w1++) {
            for (int w2 = w1; w2 < W; w2++) {
                // 長方形 [h1..h2][w1..w2]
            }
        }
    }
}
```

長方形の数は

```cpp
H * (H + 1) / 2 * W * (W + 1) / 2
```

`H, W <= 30` くらいまでなら、判定が軽ければ全探索できることが多い。

---

## 点対称・180度回転の判定

長方形 `(h1..h2, w1..w2)` が点対称かどうかは、
各マス `(i, j)` とその相手

```cpp
(h1 + h2 - i, w1 + w2 - j)
```

の色が一致するか見ればよい。

```cpp
bool ok = true;
for (int i = h1; i <= h2; i++) {
    for (int j = w1; j <= w2; j++) {
        int ni = h1 + h2 - i;
        int nj = w1 + w2 - j;
        if (grid[i][j] != grid[ni][nj]) ok = false;
    }
}
```

これは「中心を求める」のではなく、「対応する相手の座標を直接出す」発想。
幾何問題ではこの変換が重要。

---

## 設計が立たないときの進め方

グリッド幾何問題で詰まったら、コードを書く前にこれをメモすると崩れにくい。

```txt
1. 何を数える問題か
2. 何を1個固定すると判定できるか
3. 条件を座標の式で書けるか
4. 制約上、全探索できるか
5. 判定関数 ok(...) を作れるか
```

たとえば ABC455 B なら:

```txt
・数えるもの: 条件を満たす部分長方形
・固定するもの: (h1, h2, w1, w2)
・判定: (i, j) と (h1+h2-i, w1+w2-j) が同じ
・制約: H, W <= 10 なので全探索で十分
```

---

## 訪問済みフラグ

```cpp
vector<vector<bool>> visited(H, vector<bool>(W, false));

visited[x][y] = true;
if (visited[nx][ny]) continue;
```

---

## よくある罠

```cpp
// NG: 範囲チェックの順番ミス（短絡評価を利用しないと配列外アクセス）
if (grid[nx][ny] == '.' && nx >= 0 && ...) // nx が負のとき先に grid にアクセスしてしまう

// OK: 範囲チェックを先に
if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] == '.')
```

---

## チェックリスト

- [ ] `dist` や `visited` は `grid` と同じサイズで初期化したか
- [ ] 範囲チェックは移動後の座標 `(nx, ny)` に対して行っているか
- [ ] 文字グリッドは `vector<string>` で受けると楽
- [ ] 8方向が必要な問題か確認する
- [ ] 問題文の条件を `(i, j)` ベースの式に直せたか
- [ ] 「マスを固定する」のか「長方形を固定する」のかを先に決めたか
- [ ] 制約が小さいなら、まず全探索の形を疑ったか
