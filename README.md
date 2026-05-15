# C++ 学習ノート

個人の C++ 学習リポジトリ。主に競技プログラミング（AtCoder 等）の文脈で書かれている。

---

## このリポジトリの構成

```
learn/cpp/
├── README.md          ← このファイル
├── *.md               ← トピック別の解説ノート（メイン）
├── .cpp/              ← 対応する実験・練習コード
└── cpp-intro/         ← 江添さんの教材クローン（読み専用・触らない）
```

**ノートが主体、コードは補助。** `.md` に解説・まとめを書き、`.cpp/` に動作確認のコードを置く構造。

---

## ノート一覧

### 基礎構文

| ファイル | 内容 |
|---|---|
| `helloworld.md` | 最小構成・`#include` / `main` / `cout` |
| `cout-comment.md` | 出力と `//` `/* */` コメント |
| `calc.md` | 算術演算子（+ − × ÷ %）・複合代入 |
| `三項演算子.md` | `? :` 演算子・Python との対比 |
| `diff.md` | if/else による差の判定 |
| `if.md` | if/else if/else・switch・break・continue・goto・多重ループ脱出 |
| `for.md` | 基本 for / 範囲 for / map 走査 / ビット全探索 / 多重ループ |
| `auto.md` | `auto` / `auto&` / `const auto&` の使い分け・構造化束縛 |

### 型・数値

| ファイル | 内容 |
|---|---|
| `longlong.md` | `long long` の使い方・オーバーフロー罠・`1LL` イディオム |
| `ASCII_char.md` | `char(n)` 変換・ASCII テーブル・`isalpha` 等 |
| `precise_out.md` | `printf("%.16f")` / `setprecision` で精度指定 |

### コンテナ

| ファイル | 内容 |
|---|---|
| `vector.md` | vector の宣言・アクセス・push_back / pop_back / ループ |
| `array_vec.md` | cin で n 個入力して vector に格納するパターン |
| `arr_str.md` | string のメソッド（substr / find 等）・文字種判定 |
| `vec.md` | スタブ（未着手） |
| `vec_char.md` | スタブ（未着手） |
| `vector_char.md` | スタブ（未着手） |

### アルゴリズム

| ファイル | 内容 |
|---|---|
| `find_duplicate.md` | 重複検査：set / map / unordered_set / unique / カウンタ配列 |
| `grid.md` | 2次元グリッド操作・上下左右移動・BFS距離管理 |
| `map.md` | map / unordered_map / set の基本・カウンタ・存在確認 |
| `coordinate.md` | 座標問題パターン：pair・距離計算・座標変換・座標圧縮 |

### メモ

| ファイル | 内容 |
|---|---|
| `note.md` | 未解決の疑問メモ（random、型推論など） |

---

## .cpp/ ディレクトリについて

`.cpp/` には対応するコードファイルが入っている。**学習中のメモ書きなので typo やバグが残っているものがある**。主な既知の問題：

| ファイル | 問題 |
|---|---|
| `array_vec.cpp` | `vecvor<int>` → `vector<int>` の typo |
| `ASCII_char.cpp` | `cout >>` → `cout <<` の typo |
| `precise_out.cpp` | `cin <<d` → `cin >>d`、`%16` → `%.16f` など |
| `三項演算子.cpp` | 変数 `n` が未宣言 |
| `vec.cpp` `vec_char.cpp` `vector_char.cpp` | Hello World のスタブのまま |

---

## cpp-intro/ について

江添亮さんの C++ 教材（`cpp-intro`）のクローン。**このリポジトリの管理対象外**。読み物として参照するだけで、編集・移動・削除しない。

---

## LLM へのコンテキスト

- オーナーは C++ 初学者で、Python 経験あり（コード内に Python との対比メモが散見される）
- 主な目的は競技プログラミング（AtCoder）の基礎固め
- `bits/stdc++.h` と `using namespace std;` を前提としたコードスタイル
- ノートは日本語、コードは英語（変数名・コメント混在）
- 解説は「なぜそう書くか」「Python との違い」を重視する傾向がある
- スタブファイル（Hello World のまま）はまだ着手していないトピックの placeholder
