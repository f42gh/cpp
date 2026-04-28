# for 文まとめ（C++）

## 1. 基本の for 文

```cpp
for (int i = 0; i < n; i++) {
    // i = 0, 1, ..., n-1
}

// 逆順
for (int i = n - 1; i >= 0; i--) {
    // i = n-1, n-2, ..., 0
}

// 2ずつ増やす
for (int i = 0; i < n; i += 2) {
    // i = 0, 2, 4, ...
}
```

---

## 2. 範囲 for 文（range-based for）

コンテナの全要素を順に処理する。インデックスが不要なときに使う。

```cpp
vector<int> v = {1, 2, 3, 4, 5};

for (int x : v) {
    cout << x << "\n";  // 値のコピー
}
```

### 参照で受け取る（値を変更したい / コピーコストを避けたい）

```cpp
for (int& x : v) {
    x *= 2;  // 元の要素を直接変更できる
}

// string や struct など大きい型はコピーを避けるため & を使う
vector<string> words;
for (const string& w : words) {
    cout << w << "\n";
}
```

### `auto` で型を自動推論

```cpp
for (auto x : v) { }         // コピー
for (auto& x : v) { }        // 参照（変更あり）
for (const auto& x : v) { }  // const 参照（変更なし・大きい型に推奨）
```

> 競プロでは `for (auto x : v)` と書くことが多いが、`string` や `vector` を要素に持つ場合は `const auto&` にする。

### string にも使える

```cpp
string s = "hello";
for (char c : s) {
    cout << c << "\n";
}
```

---

## 3. map / unordered_map の範囲 for

```cpp
map<string, int> mp = {{"a", 1}, {"b", 2}};

for (auto& [key, val] : mp) {  // 構造化束縛（C++17）
    cout << key << " " << val << "\n";
}

// C++14 以前の書き方
for (auto& p : mp) {
    cout << p.first << " " << p.second << "\n";
}
```

---

## 4. インデックスも欲しいとき

範囲 for はインデックスを持たないので、必要なら通常の for か enumerate 的な書き方を使う。

```cpp
// 通常の for
for (int i = 0; i < (int)v.size(); i++) {
    cout << i << " " << v[i] << "\n";
}

// インデックスを別途管理
int i = 0;
for (const auto& x : v) {
    cout << i++ << " " << x << "\n";
}
```

> `v.size()` は `size_t`（符号なし整数）を返すため、`i < v.size()` で `i` が `int` の場合に警告が出ることがある。`(int)v.size()` にキャストするのが安全。

---

## 5. ビット全探索の for

```cpp
int n = 4;
for (int bit = 0; bit < (1 << n); bit++) {
    for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) {
            // i 番目の要素を選ぶ
        }
    }
}
```

`n` が大きい（> 30）場合は `1LL << n` にする。

---

## 6. 多重 for ループ

```cpp
for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
        // grid[i][j]
    }
}
```

### ループを抜けるとき（`goto` か `flag` か `lambda`）

多重ループを一気に抜ける場合:

```cpp
// flag を使う
bool found = false;
for (int i = 0; i < h && !found; i++) {
    for (int j = 0; j < w && !found; j++) {
        if (grid[i][j] == target) found = true;
    }
}

// goto を使う（競プロでは許容されることが多い）
for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
        if (grid[i][j] == target) goto done;
    }
}
done:;

// lambda に包んで return する（最もクリーン）
auto solve = [&]() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == target) return;
        }
    }
};
solve();
```

---

## チェックリスト

- [ ] 全要素を順に処理するだけ → 範囲 for
- [ ] 要素を変更したい → `for (auto& x : v)`
- [ ] `string` / `struct` など大きい型 → `for (const auto& x : v)`
- [ ] インデックスが必要 → 通常の for、`(int)v.size()` でキャスト
- [ ] `map` を走査 → 構造化束縛 `auto& [key, val]`
- [ ] ビット全探索 → `1 << n`、大きいなら `1LL << n`
- [ ] 多重ループを一気に抜ける → `goto` か lambda
