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

