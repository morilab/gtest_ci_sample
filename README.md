# gtest_ci_sample

## フォルダ構成

```
gtest_ci_sample/
│── CMakeLists.txt       # プロジェクトのビルド設定
│── README.md            # プロジェクトの説明
│── .gitignore           # Git 無視ファイル設定
│── external/            # 外部ライブラリ（Google Test）
│   └── googletest/      # Google Test のソースコード（git submodule）
│── src/                 # 本体のソースコード
│   ├── main.cpp         # メインプログラム（オプション）
│   ├── mylib.cpp        # 実装ファイル
│   └── mylib.h          # ヘッダーファイル
│── test/                # テスト用コード
│   ├── CMakeLists.txt   # テスト用の CMakeLists
│   ├── test_example.cpp # Google Test のサンプルテスト
│   ├── test_mylib.cpp   # `mylib.cpp` のテスト
│   └── test_utils.cpp   # その他ユーティリティのテスト
│── build/               # ビルド用ディレクトリ（CMake により生成される）
│── ci/                  # CI 用の設定ファイル（GitHub Actions / GitLab CI）
│   ├── github-actions.yml  # GitHub Actions 設定
│   ├── gitlab-ci.yml       # GitLab CI 設定
└── docs/                # ドキュメント用（オプション）
    ├── API.md           # API 説明
    ├── INSTALL.md       # インストール手順
    └── USAGE.md         # 使い方
```

## cloneから実行まで

1. googletestを取得する

```
cd gtest_ci_sample
git submodule update --init --recursive
```

2. CMakeを使ってビルドする

```
cmake -S . -B build
cmake --build build
```

3. 実行する
```
> ./build/test/test_mylib
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from MyLibTest
[ RUN      ] MyLibTest.Addition
[       OK ] MyLibTest.Addition (0 ms)
[ RUN      ] MyLibTest.EvenCheck
[       OK ] MyLibTest.EvenCheck (0 ms)
[----------] 2 tests from MyLibTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 2 tests.
```

## カバレッジを取る

### 環境

* lcov: LCOV version 1.14

###  Exec

```
cmake -S . -B build -DENABLE_COVERAGE=ON
cmake --build build
```

### Exec Test

```
ctest --test-dir build
```

```
cd build
ctest
```

```
cmake --build build --target test
```

### Coverage

```
cmake --build build --target coverage
```

result:
```
$ cmake --build build --target coverage
[100%] Generating coverage report
[ 16%] Built target mylib
[ 33%] Built target gtest
[ 50%] Built target gmock
[ 66%] Built target gmock_main
[ 83%] Built target gtest_main
[100%] Built target test_mylib
Test project /home/dmori/project/gtest_ci_sample/build
    Start 1: MylibTest
1/1 Test #1: MylibTest ........................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
Capturing coverage data from /home/dmori/project/gtest_ci_sample/build
Found gcov version: 9.4.0
Using intermediate gcov format
Scanning /home/dmori/project/gtest_ci_sample/build for .gcda files ...
Found 2 data files in /home/dmori/project/gtest_ci_sample/build
Processing CMakeFiles/mylib.dir/src/mylib.cpp.gcda
Processing test/CMakeFiles/test_mylib.dir/test_mylib.cpp.gcda
Finished .info-file creation
Reading tracefile coverage.info
Extracting /home/dmori/project/gtest_ci_sample/src/mylib.cpp
Extracted 1 files
Writing data to coverage_filtered.info
Summary coverage rate:
  lines......: 100.0% (4 of 4 lines)
  functions..: 100.0% (2 of 2 functions)
  branches...: no data found
Reading data file coverage_filtered.info
Found 1 entries.
Found common filename prefix "/home/dmori/project/gtest_ci_sample"
Writing .css and .png files.
Generating output.
Processing file src/mylib.cpp
Writing directory view page.
Overall coverage rate:
  lines......: 100.0% (4 of 4 lines)
  functions..: 100.0% (2 of 2 functions)
Built target coverage
```

### report

```
$ cat build/coverage_report.txt
Reading tracefile coverage_filtered.info
             |Lines       |Functions  |Branches
Filename     |Rate     Num|Rate    Num|Rate     Num
===================================================
[/home/dmori/project/gtest_ci_sample/src/]
mylib.cpp    | 100%      4| 100%     2|    -      0
===================================================
       Total:| 100%      4| 100%     2|    -      0
```
