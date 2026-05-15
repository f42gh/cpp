# map / unordered_map / set の使い方

競プロでの「辞書・カウント・存在確認」に使うコンテナ。

## 使い分け早見表

| やりたいこと | 使うもの | 計算量 |
|---|---|---|
| 存在確認だけ | `set<T>` | O(log n) |
| 存在確認（速度優先） | `unordered_set<T>` | O(1) 平均 |
| キーに値を対応させる | `map<K,V>` | O(log n) |
| 同上・速度優先 | `unordered_map<K,V>` | O(1) 平均 |

> `unordered_*` はハッシュ衝突でTLEを狙われることがある。ハック対策が必要な場面では `map` / `set` を使う。

---

## map の基本

```cpp
map<string, int> mp;

// 追加・更新
mp["alice"] = 3;
mp["bob"] = 7;

// アクセス（存在しないキーを [] でアクセスすると 0 で追加されてしまう）
cout << mp["alice"];  // 3

// 存在確認（[] を使わない）
if (mp.count("alice")) {
    cout << mp.at("alice");  // .at() は存在しないとき例外を投げる
}

// 削除
mp.erase("alice");

// ループ（キーの昇順で走査される）
for (auto& [key, val] : mp) {
    cout << key << " " << val << "\n";
}
```

## カウンタとして使う（最頻出）

```cpp
map<int, int> cnt;
vector<int> v = {3, 1, 2, 1, 3, 3};

for (int x : v) cnt[x]++;

// 出現回数を確認
cout << cnt[3];  // 3
```

---

## unordered_map の基本

使い方は `map` と同じ。ループ順序がキーの昇順でない点だけ違う。

```cpp
unordered_map<string, int> mp;
mp["alice"] = 3;
if (mp.count("alice")) { ... }
```

---

## set の基本

値の集合。重複なし、ソート済み。

```cpp
set<int> s;

s.insert(5);
s.insert(3);
s.insert(5);  // 無視される

cout << s.size();  // 2

if (s.count(5)) { /* ある */ }

s.erase(3);

// ループ（昇順）
for (int x : s) cout << x << "\n";
```

---

## unordered_set の基本

`set` の高速版。ループ順序は不定。

```cpp
unordered_set<int> s;
s.insert(5);
if (s.count(5)) { /* ある */ }
```

---

## pair をキーにしたいとき

`unordered_map` は `pair` をキーにできない（ハッシュ関数がない）。`map` を使う。

```cpp
map<pair<int,int>, int> mp;
mp[{1, 2}] = 5;
if (mp.count({1, 2})) { ... }
```

---

## チェックリスト

- [ ] `mp[key]` は存在しないキーを勝手に追加する → 存在確認は `count()` か `find()`
- [ ] ループ中に要素を削除するときは `erase` の戻り値（次のイテレータ）を使う
- [ ] `pair` をキーにするなら `map`（`unordered_map` は使えない）
- [ ] 重複チェックのパターン → [find_duplicate.md](find_duplicate.md)
