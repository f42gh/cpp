# 重複検査のベストプラクティス（競プロ向け）

## 方針の選び方

| 目的 | 使うべきもの |
|---|---|
| 重複の有無だけ知りたい | `set` |
| 重複の回数も知りたい | `map` / `unordered_map` |
| ソート済みなら | `std::unique` |
| 順序が重要でない・高速化したい | `unordered_set` / `unordered_map` |

---

## 1. `set` で重複チェック（最もシンプル）

```cpp
#include <set>
#include <vector>
using namespace std;

vector<int> v = {1, 2, 3, 2, 4};
set<int> seen;
bool has_dup = false;

for (int x : v) {
    if (!seen.insert(x).second) {  // insert が失敗 = 既に存在する
        has_dup = true;
        break;
    }
}
```

> `insert()` の戻り値は `pair<iterator, bool>`。`second` が `false` なら挿入失敗 = 重複。

全要素挿入後に `set` のサイズで判定する書き方もある:

```cpp
set<int> s(v.begin(), v.end());
bool has_dup = s.size() != v.size();  // サイズが違えば重複あり
```

---

## 2. `map` で出現回数を数える

```cpp
#include <map>
map<int, int> cnt;

for (int x : v) {
    cnt[x]++;
}

for (auto& [val, freq] : cnt) {
    if (freq > 1) {
        // val が freq 回出現
    }
}
```

---

## 3. `unordered_set` / `unordered_map`（高速版）

ハッシュテーブルベースなので平均 O(1)。ただし最悪 O(n)（ハッシュ衝突）。

```cpp
#include <unordered_set>
unordered_set<int> seen;

for (int x : v) {
    if (seen.count(x)) {
        // 重複発見
    }
    seen.insert(x);
}
```

> 競プロでハック対策が必要な場合は `set` / `map` を使う（`unordered_*` はハッシュ衝突で TLE を狙われることがある）。

---

## 4. ソート + `unique`（インプレース・追加メモリ不要）

```cpp
#include <algorithm>
vector<int> v = {3, 1, 2, 1, 3};

sort(v.begin(), v.end());
auto it = unique(v.begin(), v.end()); // 重複を末尾に追いやる
bool has_dup = it != v.end();

v.erase(it, v.end()); // 重複除去して v を縮める（座標圧縮などで使う）
```

> `unique` はソート済みが前提。隣接する重複のみ除去するため、事前ソートが必要。

---

## 5. 文字列（`string`）の重複チェック

```cpp
#include <set>
string s = "abcabd";
set<char> seen;
bool has_dup = false;

for (char c : s) {
    if (!seen.insert(c).second) {
        has_dup = true;
        break;
    }
}
```

アルファベット小文字限定なら `bitset` や `int` のビットフラグが速い:

```cpp
int flag = 0;
for (char c : s) {
    int bit = 1 << (c - 'a');
    if (flag & bit) { /* 重複 */ }
    flag |= bit;
}
```

---

## 6. 値の範囲が小さい場合（配列カウンタ）

値が `0 ~ N` 程度の整数なら `vector<int>` カウンタが最速:

```cpp
vector<int> cnt(N + 1, 0);
for (int x : v) {
    cnt[x]++;
    if (cnt[x] > 1) {
        // 重複発見
    }
}
```

---

## 計算量まとめ

| 方法 | 時間計算量 | 空間計算量 | 備考 |
|---|---|---|---|
| `set` | O(n log n) | O(n) | 安定・ハック耐性あり |
| `unordered_set` | O(n) 平均 | O(n) | 最速だがハック注意 |
| sort + `unique` | O(n log n) | O(1) | 元の配列を壊す |
| 配列カウンタ | O(n) | O(値の範囲) | 値が小さい整数限定 |
| `map` | O(n log n) | O(n) | 回数も必要なとき |

---

## チェックリスト

- [ ] 重複の有無だけ → `set` のサイズ比較か `insert().second`
- [ ] 回数も必要 → `map<T, int>`
- [ ] ソート済みまたはソートしていい → `unique` でメモリ節約
- [ ] 値が小さい整数 → カウンタ配列が最速
- [ ] `unordered_*` はハック対策が必要な場合は避ける
- [ ] `unique` の前には必ず `sort`
