# 文字列操作（string）

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;                    // 空白区切りで 1 単語入力
    string sub = s.substr(2, 4); // インデックス 2 から 4 文字を切り出す

    // 文字が小文字かどうか判定
    if (s[i] >= 'a' && s[i] <= 'z') { /* small letter */ }
}
```

## 主なメソッド・操作

| 操作 | 書き方 | 説明 |
|---|---|---|
| 長さ | `s.size()` / `s.length()` | 文字数 |
| 文字アクセス | `s[i]` | i 番目の文字（0 始まり） |
| 部分文字列 | `s.substr(pos, len)` | pos から len 文字 |
| 検索 | `s.find("ab")` | 最初に出現する位置（なければ `string::npos`） |
| 結合 | `s1 + s2` | 2 つの文字列を連結 |
| 比較 | `s1 == s2` | 文字列全体の比較 |

## 文字の種類を判定する（`<cctype>`）

```cpp
isalpha(c)  // アルファベット
isdigit(c)  // 数字
islower(c)  // 小文字
isupper(c)  // 大文字
tolower(c)  // 小文字に変換
toupper(c)  // 大文字に変換
```
