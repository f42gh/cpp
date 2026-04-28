# auto / auto& まとめ（C++）

## `auto` とは

コンパイラが右辺の型を見て、型を自動推論してくれるキーワード。

```cpp
auto x = 42;          // int
auto y = 3.14;        // double
auto s = string("hi"); // string
auto v = vector<int>{1, 2, 3}; // vector<int>
```

型を明示的に書かなくてよくなる。特に長い型名のときに便利。

```cpp
// 型名が長くて書くのが面倒なとき
map<string, vector<int>>::iterator it = mp.begin(); // 長い
auto it = mp.begin(); // スッキリ
```

---

## `auto` / `auto&` / `const auto&` の違い

| 書き方 | 意味 | 元の値を変更できるか | コピーが発生するか |
|---|---|---|---|
| `auto x` | コピー | できない（別物） | する |
| `auto& x` | 参照 | できる | しない |
| `const auto& x` | const 参照 | できない | しない |

```cpp
vector<int> v = {1, 2, 3};

for (auto x : v) {
    x = 0;  // v は変わらない（x はコピー）
}

for (auto& x : v) {
    x = 0;  // v の中身が全部 0 になる（x は v[i] の参照）
}

for (const auto& x : v) {
    // x = 0;  // コンパイルエラー（変更不可）
    cout << x; // 読むだけならこれが推奨
}
```

---

## 参照（`&`）とは

変数の「別名」。コピーを作らず、元の変数そのものを指す。

```cpp
int a = 10;
int& r = a;  // r は a の参照（別名）

r = 20;
cout << a;  // 20（a が書き換わった）
```

`auto&` は「型を自動推論して参照にする」という意味。

---

## なぜ `const auto&` を使うのか

`string` や `vector` などのコピーはコストが高い。
`const auto&` にすればコピーなしで読み取れる。

```cpp
vector<string> words = {"hello", "world"};

for (auto w : words) { }         // 毎回 string がコピーされる（遅い）
for (const auto& w : words) { }  // コピーなし（速い・推奨）
```

`int` や `char` などの小さい型はコピーでも問題ない。
大きい型（`string`, `vector`, `struct` など）は `const auto&` にする習慣をつけると良い。

---

## `auto` で型推論されるもの

```cpp
auto a = 1;          // int
auto b = 1LL;        // long long
auto c = 1.0;        // double
auto d = 'a';        // char
auto e = true;       // bool
auto f = "hello";    // const char* （string ではないので注意）
auto g = string("hello"); // string

auto h = v.size();   // size_t（符号なし整数）
auto i = v.begin();  // vector<int>::iterator
```

> `auto f = "hello"` は `const char*` になる。`string` にしたいなら `string f = "hello"` か `auto f = string("hello")`。

---

## 構造化束縛（C++17）との組み合わせ

`map` や `pair` の要素を分解するときに使う。

```cpp
map<string, int> mp = {{"a", 1}, {"b", 2}};

for (const auto& [key, val] : mp) {
    cout << key << " " << val << "\n";
}

// pair
pair<int, int> p = {3, 4};
auto [x, y] = p;  // x=3, y=4
```

---

## `auto` を使わない方が良い場面

- 型が自明でないのに `auto` にすると可読性が落ちる
- `auto f = "hello"` のように意図と違う型に推論される場合

```cpp
auto result = func();  // func() が何を返すか分からないと読みにくい
int result = func();   // 型が明確で読みやすい
```

競プロでは可読性より速く書くことを優先して `auto` を多用することが多い。

---

## チェックリスト

- [ ] 長い型名を省略したい → `auto`
- [ ] 範囲 for で読むだけ → `const auto&`（コピーなし）
- [ ] 範囲 for で要素を変更したい → `auto&`
- [ ] `"hello"` は `const char*` になるので `string` が欲しければ明示
- [ ] `map` を走査するとき → `const auto& [key, val]`（構造化束縛）
- [ ] `v.size()` の型は `size_t`（符号なし）なので `int` と比較するときは注意
