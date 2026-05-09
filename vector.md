# vector の使い方

## 宣言と初期化

```cpp
vector<int> a;              // 空のvector
vector<int> b(5);           // サイズ5、全て0
vector<int> c(5, -1);       // サイズ5、全て-1
vector<int> d = {1, 2, 3};  // 直接初期化
```

## cin で読み込む（競プロ最頻出）

```cpp
int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];
```

範囲 for で書くと短い：

```cpp
int n; cin >> n;
vector<int> a(n);
for (auto& x : a) cin >> x;
```

## アクセス

```cpp
a[0];        // 先頭（インデックスアクセス）
a.front();   // 先頭
a.back();    // 末尾
a.size();    // 要素数
```

## 追加・削除・変更

```cpp
a.push_back(1);  // 末尾に追加
a.pop_back();    // 末尾を削除（値は返さない）
a.resize(10);    // サイズを変更（増えた分は0で埋まる）
a.clear();       // 全要素削除
a.empty();       // 空かどうか
```

> `pop_back()` は削除するだけで値を返さない。値が必要なら先に `a.back()` で取得する。

## ループ

```cpp
// インデックス for
for (int i = 0; i < (int)a.size(); i++) cout << a[i] << endl;

// 範囲 for（読み取り）
for (int x : a) cout << x << endl;

// 範囲 for（変更あり）
for (int& x : a) x *= 2;
```

> `i < a.size()` は `a.size()` が `size_t`（符号なし整数）なので、`i` が `int` のとき比較に注意。`(int)a.size()` とキャストするのが安全。

## ソート・逆順

```cpp
sort(a.begin(), a.end());    // 昇順
sort(a.rbegin(), a.rend());  // 降順
reverse(a.begin(), a.end()); // 逆順
```

## 2次元vector（ジャグ配列）

行ごとに長さが違うときは `vector<vector<int>>` を使う。

```cpp
int n;
cin >> n;
vector<vector<int>> A(n);   // n行の空のvector

for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    A[i].resize(l);
    for (int j = 0; j < l; j++) cin >> A[i][j];
}
```

固定サイズの2次元配列 `int A[N][M]` との違いや注意点は → [array.md](array.md)
