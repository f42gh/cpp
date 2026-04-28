# 制御フロー

## if / else if / else

条件に応じて処理を分岐する。

```cpp
// if.cpp より
int tmp = 0;
if (tmp == 0) {
    cout << "tmp is zero" << endl;
}
else if (!(tmp == 0) || tmp == 1) {
    cout << "tmp is one or something without zero" << endl;
}
else {
    cout << "tmp is not zero and two" << endl;
}
```

- 条件式は `bool` に評価される式なら何でも使える
- `else if` は何個でも連結できる
- `else` は省略可能

### 論理演算子

| 演算子 | 意味 | 例 |
|---|---|---|
| `&&` | かつ | `x > 0 && x < 10` |
| `\|\|` | または | `x == 0 \|\| x == 1` |
| `!` | 否定 | `!(x == 0)` |

---

## switch

整数・`char` の値で多分岐する。`if-else if` の連鎖より高速になることがある。

```cpp
int day = 3;

switch (day) {
    case 1:
        cout << "月曜" << endl;
        break;
    case 2:
        cout << "火曜" << endl;
        break;
    case 3:
        cout << "水曜" << endl;  // ここに入る
        break;
    default:
        cout << "その他" << endl;
}
```

### フォールスルー

`break` を書かないと次の `case` の処理も実行される（フォールスルー）。
意図的に行う場合は C++17 の `[[fallthrough]]` で明示する。

```cpp
int val = 3;

switch (val) {
    case 3:
        [[fallthrough]];  // 意図的にフォールスルーすることを明示
    case 4:
        cout << "3 か 4" << endl;  // val==3 でもここが実行される
        break;
    default:
        cout << "other" << endl;
}
```

---

## break

ループまたは `switch` を即座に抜ける。

```cpp
// 1〜100 の中で最初に 7 の倍数を見つけたら止める
for (int i = 1; i <= 100; i++) {
    if (i % 7 == 0) {
        cout << "最初の7の倍数: " << i << endl;  // 7
        break;
    }
}
```

---

## continue

ループの残りの処理をスキップして、次のイテレーションへ進む。

```cpp
// 1〜10 のうち奇数だけ表示
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) continue;  // 偶数はスキップ
    cout << i << " ";
}
// 出力: 1 3 5 7 9
```

---

## 多重ループからの脱出

C++ にはラベル付き `break`（Java の機能）がないため、以下のいずれかで対処する。

### フラグを使う（推奨）

```cpp
bool found = false;

for (int i = 0; i < 5 && !found; i++) {
    for (int j = 0; j < 5; j++) {
        if (i * j > 6) {
            cout << "i=" << i << " j=" << j << endl;  // i=2 j=4
            found = true;
            break;  // 内側を抜け、外側も !found で止まる
        }
    }
}
```

### goto を使う（非推奨）

可読性が下がるため、基本的には避ける。どうしても必要な場合のみ。

```cpp
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (i * j > 6) goto done;
    }
}
done:
cout << "ループ終了" << endl;
```

---

## goto

指定したラベルへ無条件にジャンプする。スパゲッティコードの原因になるため非推奨。
エラー処理などでやむを得ない場合に限り使われることがある。

```cpp
int n = 0;
retry:
    cout << "n = " << n << endl;
    n++;
    if (n < 3) goto retry;
// 出力:
// n = 0
// n = 1
// n = 2
```
