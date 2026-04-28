# long long in C++（競プロ向けまとめ）

## 基本

`long long` は64ビット符号付き整数型。

| 型 | ビット数 | 最大値 | 最小値 |
|---|---|---|---|
| `int` | 32bit | 約 2.1 × 10⁹ | 約 -2.1 × 10⁹ |
| `long long` | 64bit | 約 9.2 × 10¹⁸ | 約 -9.2 × 10¹⁸ |

```cpp
long long x = 1e18;  // OK
int y = 1e18;        // オーバーフロー（危険）
```

## 宣言と初期化

```cpp
long long a = 1000000000LL;  // LL サフィックスで long long リテラル
long long b = 1e18;          // double 経由なので誤差に注意（後述）
long long c = 1'000'000'000; // 桁区切り（C++14以降）

// using で型エイリアス（競プロでよく使う）
using ll = long long;
ll n, m;
```

## 競プロでよく使う定数

```cpp
using ll = long long;

const ll INF = 1e18;       // 無限大代わり（long long の範囲内）
const ll MOD = 1e9 + 7;    // よくある mod
const ll MOD2 = 998244353; // もう一つよくある mod
```

> `int INF = 1e9` はよく見るが、2つ足すとオーバーフローするので `2e9` 以上は `ll` にする。

## オーバーフローの罠

### int 同士の演算結果は int

```cpp
int a = 1000000, b = 1000000;
long long c = a * b;  // NG: a * b が int で計算されてからキャスト → オーバーフロー

long long d = (long long)a * b;  // OK: 一方を ll にキャスト
long long e = 1LL * a * b;       // OK: よく使うイディオム
```

### リテラルも注意

```cpp
long long x = 2000000000 * 3;  // NG: 右辺が int 演算
long long y = 2000000000LL * 3; // OK
```

## `1LL <<` シフト演算

```cpp
long long mask = 1LL << 40;  // OK
long long bad  = 1   << 40;  // NG: int の 1 を 40 ビットシフト → UB
```

ビット全探索などで `i < (1LL << n)` と書くのが定石。

## scanf / printf での書式指定子

```cpp
long long x;
scanf("%lld", &x);   // %lld を使う（%d は NG）
printf("%lld\n", x);
```

cin / cout を使う場合は問題なし。

## `long long` の最大値・最小値

```cpp
#include <climits>
LLONG_MAX; // 9223372036854775807 ≈ 9.2 × 10¹⁸
LLONG_MIN; // -9223372036854775808

#include <limits>
std::numeric_limits<long long>::max();
```

`INF = LLONG_MAX` を使うと `INF + 1` でオーバーフローするので、`INF = 1e18` や `INF = 4e18` などを使う。

## `double` との変換注意

```cpp
long long x = 1e18;  // double → ll 変換: 誤差あり
// 1e18 は 2 進数では正確に表現できないため ±数 の誤差が生じる可能性がある

long long y = (long long)1e18; // 同じ問題
long long z = 1000000000000000000LL; // リテラルで書くと確実
```

## mod 演算との組み合わせ

```cpp
const ll MOD = 1e9 + 7;

ll ans = (a * b) % MOD;            // a, b が ll ならこれで十分
ll ans2 = ((a % MOD) * (b % MOD)) % MOD; // a, b が非常に大きい場合
```

`(ll)a * b % MOD` は `((ll)a * b) % MOD` と解釈されるので意図通り。

## `__int128`（参考）

`long long` の範囲（約 9.2 × 10¹⁸）も超える場合は `__int128` を使う（GCC 拡張）。

```cpp
__int128 x = (__int128)1e27;
// cin / cout は非対応なので自前で変換が必要
```

## チェックリスト

- [ ] 答えが 2 × 10⁹ を超えるなら `long long` を使う
- [ ] `int * int` の結果を `long long` に入れるとき `1LL *` でキャスト
- [ ] シフト演算は `1LL <<` にする
- [ ] `INF` を `LLONG_MAX` にしない（加算でオーバーフロー）
- [ ] `1e18` のリテラルは誤差に注意し、厳密な値が必要なら整数で書く
- [ ] `scanf` では `%lld` を使う
