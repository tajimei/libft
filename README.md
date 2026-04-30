*This project has been created as part of the 42 curriculum by mtajima.*

# Libft - Your very first own library

## Description

Libft is the first project in the 42 curriculum. The goal is to reimplement a set of standard C library functions from scratch, and to create additional utility functions that will be reused throughout the curriculum.

By building this library, you gain a deep understanding of how fundamental C functions work internally — memory management, string manipulation, linked lists, and more.

The library is compiled into a static archive `libft.a` which can be linked to future projects.

---

## Instructions

### Compilation

```bash
make        # Build libft.a
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Rebuild from scratch
```

### Usage

Include the header in your source files:

```c
#include "libft.h"
```

Link the library when compiling:

```bash
cc your_file.c -L. -lft -o your_program
```

---

## Library Overview

### Part 1 - Libc functions

Reimplementations of standard C library functions with the `ft_` prefix.

| Function | Description |
|---|---|
| `ft_isalpha` | Returns 1 if character is alphabetic, 0 otherwise |
| `ft_isdigit` | Returns 1 if character is a digit, 0 otherwise |
| `ft_isalnum` | Returns 1 if character is alphanumeric, 0 otherwise |
| `ft_isascii` | Returns 1 if character is ASCII, 0 otherwise |
| `ft_isprint` | Returns 1 if character is printable, 0 otherwise |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Sets memory to zero |
| `ft_memcpy` | Copies memory area (no overlap) |
| `ft_memmove` | Copies memory area (overlap safe) |
| `ft_strlcpy` | Copies string with size limit, null-terminates |
| `ft_strlcat` | Concatenates string with size limit |
| `ft_toupper` | Converts character to uppercase |
| `ft_tolower` | Converts character to lowercase |
| `ft_strchr` | Finds first occurrence of character in string |
| `ft_strrchr` | Finds last occurrence of character in string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_memchr` | Finds first occurrence of byte in memory |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds substring within n characters |
| `ft_atoi` | Converts string to integer |
| `ft_calloc` | Allocates and zero-initializes memory |
| `ft_strdup` | Duplicates a string using malloc |

### Part 2 - Additional functions

Utility functions not found in the standard libc, or implemented differently.

| Function | Description |
|---|---|
| `ft_substr` | Returns a substring from a string |
| `ft_strjoin` | Concatenates two strings into a new one |
| `ft_strtrim` | Trims characters from both ends of a string |
| `ft_split` | Splits a string by a delimiter into an array |
| `ft_itoa` | Converts an integer to a string |
| `ft_strmapi` | Applies a function to each character, returns new string |
| `ft_striteri` | Applies a function to each character in place |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd` | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by newline to a file descriptor |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor |

### Part 3 - Linked list

Functions to manipulate singly linked lists using the `t_list` structure.

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstsize` | Returns the number of nodes in the list |
| `ft_lstlast` | Returns the last node of the list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstdelone` | Frees a single node's content and the node itself |
| `ft_lstclear` | Frees all nodes in the list and sets pointer to NULL |
| `ft_lstiter` | Applies a function to each node's content |
| `ft_lstmap` | Creates a new list by applying a function to each node |

---

## Resources

### References

- [C Standard Library - cppreference](https://en.cppreference.com/w/c)
- [man pages online](https://man7.org/linux/man-pages/)
- [42 Norm](https://github.com/42School/norminette)

### AI Usage
Claude (Anthropic) was used throughout this project as a learning support tool. Specifically:

- **Function specifications**: Each function's behavior and edge cases were understood through interactive dialogue before implementing independently. Also used for translating the English subject to ensure correct understanding.
- **Concept explanations**: Used to understand concepts such as `static` functions, `size_t`, file descriptors, function pointers, and linked list structure.
- **Code was not copied directly**: All implementations were written by hand and verified through testing.



*以下日本語版*

# Libft - はじめての自作ライブラリ

## 説明

Libft は 42 カリキュラムの最初のプロジェクトです。標準 C ライブラリの関数群をゼロから再実装し、カリキュラム全体を通じて再利用できる追加のユーティリティ関数を作成することが目標です。

このライブラリを構築することで、メモリ管理・文字列操作・連結リストなど、C言語の基礎関数がどのように内部で動作しているかを深く理解することができます。

ライブラリは静的アーカイブ `libft.a` としてコンパイルされ、将来のプロジェクトにリンクして使用します。

---

## 使い方

### コンパイル

```bash
make        # libft.a をビルド
make clean  # オブジェクトファイルを削除
make fclean # オブジェクトファイルと libft.a を削除
make re     # 最初からリビルド
```

### 使用方法

ソースファイルにヘッダをインクルード：

```c
#include "libft.h"
```

コンパイル時にライブラリをリンク：

```bash
cc your_file.c -L. -lft -o your_program
```

---

## ライブラリの詳細

### パート1 - libc 関数

標準 C ライブラリ関数を `ft_` プレフィックス付きで再実装したものです。

| 関数 | 説明 |
|---|---|
| `ft_isalpha` | アルファベットなら 1、そうでなければ 0 を返す |
| `ft_isdigit` | 数字なら 1、そうでなければ 0 を返す |
| `ft_isalnum` | 英数字なら 1、そうでなければ 0 を返す |
| `ft_isascii` | ASCII 文字なら 1、そうでなければ 0 を返す |
| `ft_isprint` | 印字可能文字なら 1、そうでなければ 0 を返す |
| `ft_strlen` | 文字列の長さを返す |
| `ft_memset` | メモリを指定したバイト値で埋める |
| `ft_bzero` | メモリをゼロで初期化する |
| `ft_memcpy` | メモリ領域をコピーする（オーバーラップ非対応） |
| `ft_memmove` | メモリ領域をコピーする（オーバーラップ対応） |
| `ft_strlcpy` | サイズ制限付きで文字列をコピーし、ヌル終端する |
| `ft_strlcat` | サイズ制限付きで文字列を連結する |
| `ft_toupper` | 文字を大文字に変換する |
| `ft_tolower` | 文字を小文字に変換する |
| `ft_strchr` | 文字列中で最初に現れる文字の位置を返す |
| `ft_strrchr` | 文字列中で最後に現れる文字の位置を返す |
| `ft_strncmp` | 2つの文字列を最大 n 文字まで比較する |
| `ft_memchr` | メモリ領域内で最初に現れるバイトの位置を返す |
| `ft_memcmp` | 2つのメモリ領域を比較する |
| `ft_strnstr` | n 文字以内で部分文字列を検索する |
| `ft_atoi` | 文字列を整数に変換する |
| `ft_calloc` | メモリを確保しゼロで初期化する |
| `ft_strdup` | malloc を使って文字列を複製する |

### パート2 - 追加関数

標準 libc には存在しない、または異なる形で存在するユーティリティ関数群です。

| 関数 | 説明 |
|---|---|
| `ft_substr` | 文字列から部分文字列を切り出して返す |
| `ft_strjoin` | 2つの文字列を連結した新しい文字列を返す |
| `ft_strtrim` | 文字列の両端から指定文字を取り除く |
| `ft_split` | デリミタで文字列を分割し配列として返す |
| `ft_itoa` | 整数を文字列に変換する |
| `ft_strmapi` | 各文字に関数を適用し新しい文字列を返す |
| `ft_striteri` | 各文字に関数を適用し元の文字列を直接変更する |
| `ft_putchar_fd` | 指定したファイルディスクリプタに文字を出力する |
| `ft_putstr_fd` | 指定したファイルディスクリプタに文字列を出力する |
| `ft_putendl_fd` | 指定したファイルディスクリプタに文字列と改行を出力する |
| `ft_putnbr_fd` | 指定したファイルディスクリプタに整数を出力する |

### パート3 - 連結リスト

`t_list` 構造体を使った単方向連結リストを操作する関数群です。

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| 関数 | 説明 |
|---|---|
| `ft_lstnew` | 新しいリストノードを作成する |
| `ft_lstadd_front` | リストの先頭にノードを追加する |
| `ft_lstsize` | リストのノード数を返す |
| `ft_lstlast` | リストの最後のノードを返す |
| `ft_lstadd_back` | リストの末尾にノードを追加する |
| `ft_lstdelone` | ノードの content と ノード自体を解放する |
| `ft_lstclear` | リストの全ノードを解放し、ポインタを NULL にする |
| `ft_lstiter` | 各ノードの content に関数を適用する |
| `ft_lstmap` | 各ノードに関数を適用した新しいリストを返す |

---

## 参考資料

### リファレンス

- [C 標準ライブラリ - cppreference](https://en.cppreference.com/w/c)
- [man pages オンライン](https://man7.org/linux/man-pages/)
- [42 Norm](https://github.com/42School/norminette)

### AI の使用について

このプロジェクトを通じて、Claude（Anthropic）を学習サポートツールとして使用しました。具体的には以下の用途で使用しています：

- **関数の仕様理解**：各関数の動作やエッジケースを、自分で実装する前に理解するために対話形式で仕様を理解。英語のsubjectを正しく理解するため、翻訳にも利用した。
- **概念の説明**：`static` 関数、`size_t`、ファイルディスクリプタ、関数ポインタ、連結リスト構造などの概念理解に使用。
- **コピーはしていません**：全ての実装は手書きで行い、テストを通じて動作を確認しました。