# ASCII コードと char 変換

整数を `char` にキャストすると、対応する ASCII 文字を得られる。

```cpp
#include<iostream>
using namespace std;
int main(){
    int n; cin >> n;
    cout << char(n) << endl;  // ASCII コード n の文字を出力
}
```

## 実行例

| 入力 `n` | 出力 |
|---|---|
| 65 | A |
| 97 | a |
| 48 | 0 |

## よく使う ASCII コードの範囲

| 範囲 | 文字 |
|---|---|
| 48〜57 | `'0'`〜`'9'` |
| 65〜90 | `'A'`〜`'Z'` |
| 97〜122 | `'a'`〜`'z'` |

## 逆変換（char → int）

```cpp
char c = 'A';
int code = (int)c;   // 65
int code2 = c - 'A'; // 0（'A' からの距離）
```

> **注意**: コード中の `cout >>` は誤り。出力は `cout <<` を使う。
