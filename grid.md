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
