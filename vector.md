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

---

## `[]` を何回使えるかは要素型で決まる

`vector` は「中に何型を入れているか」で使い方が変わる。

```cpp
vector<int> a(5);
```

これは「`int` が 5 個入った配列」なので、

```cpp
a[i]      // int
a[i][j]   // NG
```

`a[i]` の時点で `int` になっており、`int` にはさらに `[]` がない。

一方で

```cpp
vector<string> S(5);
```

これは「`string` が 5 個入った配列」なので、

```cpp
S[i]      // string
S[i][j]   // char
```

`S[i]` は文字列で、`string` には `[]` があるからさらに `[j]` を使える。

同様に

```cpp
vector<vector<int>> g(4, vector<int>(5));
```

なら

```cpp
g[i]      // vector<int>
g[i][j]   // int
```

になる。

要するに、`[]` を何回重ねられるかは
**次の要素型にも `[]` があるかどうか**
で決まる。

---

## `vector<string>` と `vector<vector<char>>`

どちらも「文字の2次元グリッド」を表せる。

```cpp
vector<string> A(H);
for (int i = 0; i < H; i++) cin >> A[i];
```

```cpp
vector<vector<char>> B(H, vector<char>(W));
for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> B[i][j];
}
```

どちらも

```cpp
A[i][j]
B[i][j]
```

でアクセスできる。

違いは中身の型:

- `A[i]` は `string`
- `B[i]` は `vector<char>`

競プロで `.` と `#` のような文字グリッドを読むだけなら、`vector<string>` の方が短くて書きやすい。
文字を1文字ずつ個別に処理する場面でも普通に使える。

---

## ありがちな勘違い

`S[i][j]` を見て「途中から勝手に2次元になった」のではない。

```cpp
vector<string> S(H);
```

は最初から

- 1段目: `vector`
- 2段目: `string`

という2段構造になっている。

だから

```cpp
S[i]     // i行目の文字列
S[i][j]  // i行目 j列目の文字
```

と読める。

`vector<int>` で同じことができないのは、`int` が1個の値であって、
文字列や `vector` のように中にさらに要素を持っていないから。
