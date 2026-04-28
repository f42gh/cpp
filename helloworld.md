# Hello, World!

C++ プログラムの最小構成。

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Hello, world!" << endl;
}
```

## ポイント

| 要素 | 意味 |
|---|---|
| `#include <bits/stdc++.h>` | 競技プログラミングでよく使われる万能ヘッダ。標準ライブラリを一括でインクルード |
| `using namespace std;` | `std::cout` を `cout` と省略して書けるようにする |
| `int main()` | プログラムのエントリポイント |
| `cout << "..."` | 標準出力へ文字列を送る |
| `endl` | 改行 + バッファフラッシュ。改行だけなら `'\n'` のほうが速い |
