#!/usr/bin/env python3
"""
Fixed Point Precision Comparison Tool
Compares result.txt (42Tokyo benchmark) with log file and analyzes mathematical accuracy
"""

import re
import sys
from decimal import Decimal, getcontext

# 高精度計算のための設定
getcontext().prec = 50

def parse_calculation_line(line):
    """計算行を解析して式と結果を抽出"""
    # 形式: "    計算式 : 結果値"
    pattern = r'\s*(.+?)\s*:\s*([-+]?\d+\.?\d*)'
    match = re.match(pattern, line.strip())
    if match:
        expression = match.group(1).strip()
        result = float(match.group(2))
        return expression, result
    return None, None

def evaluate_expression(expr):
    """数学式を評価して真値を計算"""
    try:
        # 16進数表記を10進数に変換
        expr = re.sub(r'0x([0-9a-fA-F]+)', lambda m: str(int(m.group(1), 16)), expr)
        
        # 安全な評価のために許可する文字のみに制限
        allowed_chars = set('0123456789+-*/.() ')
        if not all(c in allowed_chars for c in expr):
            return None
            
        # Decimalを使用して高精度計算
        # まず通常のfloat計算
        result = eval(expr)
        return float(result)
    except:
        return None

def compare_files(result_file, log_file):
    """2つのファイルを比較分析"""
    print("=" * 80)
    print("Fixed Point Precision Comparison Analysis")
    print("=" * 80)
    print(f"Benchmark: {result_file} (42Tokyo Standard)")
    print(f"Current:   {log_file} (Your Implementation)")
    print("=" * 80)
    
    try:
        with open(result_file, 'r') as f:
            result_lines = f.readlines()
        with open(log_file, 'r') as f:
            log_lines = f.readlines()
    except FileNotFoundError as e:
        print(f"Error: {e}")
        return
    
    differences = []
    
    for i, (result_line, log_line) in enumerate(zip(result_lines, log_lines), 1):
        result_expr, result_val = parse_calculation_line(result_line)
        log_expr, log_val = parse_calculation_line(log_line)
        
        # 有効な計算行のみ処理
        if result_expr and log_expr and result_val is not None and log_val is not None:
            # 値が異なる場合のみ詳細分析
            if abs(result_val - log_val) > 1e-6:
                true_value = evaluate_expression(result_expr)
                if true_value is not None:
                    differences.append({
                        'line': i,
                        'expression': result_expr,
                        'true_value': true_value,
                        'benchmark': result_val,
                        'current': log_val,
                        'benchmark_error': abs(result_val - true_value),
                        'current_error': abs(log_val - true_value),
                        'difference': abs(result_val - log_val)
                    })
    
    # 分析結果を出力
    if not differences:
        print("No significant differences found between files.")
        return
    
    print(f"\nFound {len(differences)} significant differences:\n")
    
    # 演算タイプごとに分類
    division_ops = []
    multiplication_ops = []
    other_ops = []
    
    for diff in differences:
        if '/' in diff['expression']:
            division_ops.append(diff)
        elif '*' in diff['expression']:
            multiplication_ops.append(diff)
        else:
            other_ops.append(diff)
    
    # 除算演算の分析
    if division_ops:
        print("📊 DIVISION OPERATIONS ANALYSIS")
        print("-" * 50)
        benchmark_better = 0
        current_better = 0
        
        for diff in division_ops:
            expr = diff['expression']
            true_val = diff['true_value']
            bench_val = diff['benchmark']
            curr_val = diff['current']
            bench_err = diff['benchmark_error']
            curr_err = diff['current_error']
            
            better = "BENCHMARK" if bench_err < curr_err else "CURRENT"
            if bench_err < curr_err:
                benchmark_better += 1
            else:
                current_better += 1
                
            print(f"Line {diff['line']:2d}: {expr}")
            print(f"  Mathematical Truth: {true_val:.6f}")
            print(f"  Benchmark (42Tokyo): {bench_val:.6f} (error: {bench_err:.6f})")
            print(f"  Current (Your code): {curr_val:.6f} (error: {curr_err:.6f})")
            print(f"  More Accurate: {better}")
            print()
        
        print(f"Division Summary: Benchmark better: {benchmark_better}, Current better: {current_better}")
        print()
    
    # 乗算演算の分析
    if multiplication_ops:
        print("🔢 MULTIPLICATION OPERATIONS ANALYSIS")
        print("-" * 50)
        benchmark_better = 0
        current_better = 0
        
        for diff in multiplication_ops:
            expr = diff['expression']
            true_val = diff['true_value']
            bench_val = diff['benchmark']
            curr_val = diff['current']
            bench_err = diff['benchmark_error']
            curr_err = diff['current_error']
            
            better = "BENCHMARK" if bench_err < curr_err else "CURRENT"
            if bench_err < curr_err:
                benchmark_better += 1
            else:
                current_better += 1
                
            print(f"Line {diff['line']:2d}: {expr}")
            print(f"  Mathematical Truth: {true_val:.6f}")
            print(f"  Benchmark (42Tokyo): {bench_val:.6f} (error: {bench_err:.6f})")
            print(f"  Current (Your code): {curr_val:.6f} (error: {curr_err:.6f})")
            print(f"  More Accurate: {better}")
            print()
        
        print(f"Multiplication Summary: Benchmark better: {benchmark_better}, Current better: {current_better}")
        print()
    
    # その他の演算
    if other_ops:
        print("⚡ OTHER OPERATIONS ANALYSIS")
        print("-" * 50)
        for diff in other_ops:
            expr = diff['expression']
            bench_val = diff['benchmark']
            curr_val = diff['current']
            
            print(f"Line {diff['line']:2d}: {expr}")
            print(f"  Benchmark: {bench_val:.6f}")
            print(f"  Current:   {curr_val:.6f}")
            print(f"  Difference: {diff['difference']:.6f}")
            print()
    
    # 総合評価
    total_benchmark_better = sum(1 for d in differences if d['benchmark_error'] < d['current_error'])
    total_current_better = len(differences) - total_benchmark_better
    
    print("=" * 80)
    print("🏆 OVERALL ACCURACY COMPARISON")
    print("=" * 80)
    print(f"Total differences analyzed: {len(differences)}")
    print(f"Benchmark (42Tokyo) more accurate: {total_benchmark_better} cases")
    print(f"Current (Your code) more accurate: {total_current_better} cases")
    
    if total_benchmark_better > total_current_better:
        print("\n📈 RECOMMENDATION: Consider adopting benchmark algorithms for better precision")
    elif total_current_better > total_benchmark_better:
        print("\n🎯 EXCELLENT: Your implementation is more accurate than the benchmark!")
    else:
        print("\n⚖️  BALANCED: Both implementations have similar accuracy")
    
    print("=" * 80)

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 compare_fixed_results.py <result.txt> <log>")
        print("Example: python3 compare_fixed_results.py result.txt log")
        sys.exit(1)
    
    result_file = sys.argv[1]
    log_file = sys.argv[2]
    
    compare_files(result_file, log_file)

if __name__ == "__main__":
    main()
