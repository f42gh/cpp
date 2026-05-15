# 累積和

## 累積和とは

累積和は、配列の「先頭からそこまでの合計」を前計算しておいて、区間和を高速に求めるためのテクニック。

例えば配列 `a` があるとき、`sum[i]` を

- `a[0] + a[1] + ... + a[i - 1]`

として持っておくと、半開区間 `[l, r)` の和は

- `sum[r] - sum[l]`

で求められる。

`Q` 回の区間和クエリがあるとき、

- 素直に毎回足す: `O(NQ)`
- 累積和を使う: 構築 `O(N)`、各クエリ `O(1)`

となる。

## 1次元累積和の基本形

### 元配列

```cpp
vector<int> a = {3, 1, 4, 1, 5};
int n = (int)a.size();
```

### 累積和の作り方

`sum[0] = 0` から始めるのが定番。

```cpp
vector<int> sum(n + 1, 0);
for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
}
```

このとき:

- `sum[0] = 0`
- `sum[1] = a[0]`
- `sum[2] = a[0] + a[1]`
- ...

### 区間和の取り方

`[l, r)` の和は:

```cpp
int ans = sum[r] - sum[l];
```

例: `a[1] + a[2] + a[3]` を取りたいなら、区間は `[1, 4)` なので

```cpp
int ans = sum[4] - sum[1];
```

## AtCoder でよく使う完成形

```cpp
int n, q;
cin >> n >> q;

vector<long long> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

vector<long long> sum(n + 1, 0);
for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
}

for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l] << '\n';
}
```

## for文の賢い使い方

累積和は `for (int i = 0; i < n; i++)` がかなり本筋。
理由は、`sum[i + 1]` と `a[i]` のように**添字が必要**だから。

## 1. 添字が必要なら普通の for

累積和の構築はこれが一番読みやすい。

```cpp
for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
}
```

これは:

- 今どこを見ているか分かる
- `i + 1` を自然に書ける
- 区間DPや尺取り法にも流用しやすい

ので、競プロではむしろ「スタイリッシュで実用的」。

## 2. 要素だけ見ればいいなら range-based for

`for (x : y)` は range-based for。
要素そのものだけ欲しいときに使う。

```cpp
for (auto x : a) {
    cout << x << '\n';
}
```

文字列なら:

```cpp
string s;
cin >> s;

for (char c : s) {
    cout << c << '\n';
}
```

### ただし累積和構築とは少し相性が悪い

例えば:

```cpp
long long cur = 0;
vector<long long> sum = {0};
for (auto x : a) {
    cur += x;
    sum.push_back(cur);
}
```

これは書けるけど、

- `sum[i]` を意識しづらい
- 後で添字付き処理に拡張しにくい

ので、競プロでは普通の `for` の方が安定。

## 3. 書き換えるなら参照を使う

```cpp
for (auto& x : a) {
    cin >> x;
}
```

これはかなり便利。

- 入力
- 配列要素の更新
- 文字列の各文字の書き換え

に向いている。

例:

```cpp
string s = "abc";
for (auto& c : s) {
    c = toupper(c);
}
```

## 4. 累積和まわりでよくある for の形

### 入力

```cpp
for (auto& x : a) cin >> x;
```

### 累積和構築

```cpp
for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
}
```

### クエリ処理

```cpp
for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l] << '\n';
}
```

### 全要素の確認

```cpp
for (auto x : sum) {
    cout << x << ' ';
}
cout << '\n';
```

## 5. 結論

使い分けはこれで十分。

- 添字が必要: `for (int i = 0; i < n; i++)`
- 要素だけ見る: `for (auto x : a)`
- 要素を書き換える: `for (auto& x : a)`

特に累積和では、

```cpp
for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
}
```

が一番素直で強い。
無理に `for (x : y)` に寄せるより、**添字がある処理は普通の for を使う**方がバグりにくい。

## 2次元累積和

マス目でも同じ考え方を使える。

`sum[i + 1][j + 1]` に、左上 `(0, 0)` から `(i, j)` までの和を入れる。

```cpp
vector<vector<int>> sum(h + 1, vector<int>(w + 1, 0));

for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
    }
}
```

長方形 `[x1, x2) x [y1, y2)` の和は:

```cpp
int ans = sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
```

ここでも添字が重要なので、普通の `for` が本筋。
