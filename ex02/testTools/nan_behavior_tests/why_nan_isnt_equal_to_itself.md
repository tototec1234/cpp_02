素晴らしい質問です！`rounded != rounded`が1（true）を返すのは、`NaN`（Not a Number）の非常に特殊な性質によるものです。

## `NaN`の特殊な性質

**`NaN`は自分自身とも等しくない**という、数学的には奇妙に見える性質を持っています。これはIEEE 754浮動小数点標準で定義されている仕様です。

実際に確認してみましょう：
Ran tool

```bash
c++ nan_comparison_test.cpp -o nan_comparison_test && ./nan_comparison_test
```

Ran tool
```bash
rm nan_comparison_test
```

## 実行結果の解説

テスト結果を見ると、驚くべき違いが明確に表れています：

### 通常の値の場合
```
normal_value == normal_value: 1  ← 期待通り true
normal_value != normal_value: 0  ← 期待通り false
```

### `NaN`の場合
```
nan_value == nan_value: 0  ← 自分自身と等しくない！（false）
nan_value != nan_value: 1  ← 自分自身と等しくない！（true）
```

## なぜこのような動作になるのか？

### 1. **IEEE 754標準の規定**
- **`NaN`は任意の値と比較しても常に`false`を返す**（自分自身を含む）
- この規定はIEEE 754浮動小数点標準で明確に定義されています

### 2. **数学的な意味**
- `NaN`は「Not a Number」つまり「数値ではない」
- 数値ではないものは、何とも（自分自身とも）比較できない
- よって、全ての比較演算（`==`, `<`, `>`, `<=`, `>=`）が`false`を返す
- `!=`だけは例外的に`true`を返す

### 3. **実用的な目的**
- **`NaN`を検出する標準的な方法**として使われる
- `if (value != value)`で`NaN`かどうかを判定できる
- `std::isnan()`関数の内部実装もこの性質を利用している

## つまり

```cpp
rounded != rounded  // これは「roundedがNaNかどうか」をチェックする慣用句
```

ご指摘の通り、通常なら「右辺と左辺が同じなら必ず0を返す」べきですが、**`NaN`だけは例外**として、この特殊な動作をするように設計されているのです。

これは一見奇妙に見えますが、浮動小数点数の世界では標準的で重要な仕様なのです！