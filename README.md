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

Reimplementations of standard C library functions with the `ft_` prefix. None of these functions rely on any external library functions.

---

#### `ft_isalpha` — Check if alphabetic

```c
int ft_isalpha(int c);
```

Returns `1` if `c` is an uppercase or lowercase letter (`A–Z`, `a–z`), `0` otherwise.

```c
ft_isalpha('A')   // 1
ft_isalpha('3')   // 0
ft_isalpha('\n')  // 0
```

---

#### `ft_isdigit` — Check if decimal digit

```c
int ft_isdigit(int c);
```

Returns `1` if `c` is a digit (`0–9`), `0` otherwise.

```c
ft_isdigit('5')  // 1
ft_isdigit('a')  // 0
```

---

#### `ft_isalnum` — Check if alphanumeric

```c
int ft_isalnum(int c);
```

Returns `1` if `c` is alphabetic or a digit, `0` otherwise. Equivalent to `ft_isalpha || ft_isdigit`.

```c
ft_isalnum('Z')  // 1
ft_isalnum('9')  // 1
ft_isalnum('!')  // 0
```

---

#### `ft_isascii` — Check if ASCII character

```c
int ft_isascii(int c);
```

Returns `1` if `c` is between `0` and `127` (inclusive), `0` otherwise.

```c
ft_isascii(0)    // 1
ft_isascii(127)  // 1
ft_isascii(128)  // 0
```

---

#### `ft_isprint` — Check if printable character

```c
int ft_isprint(int c);
```

Returns `1` if `c` is a printable character (ASCII `32–126`, includes space), `0` otherwise.

```c
ft_isprint(' ')   // 1
ft_isprint('~')   // 1
ft_isprint('\n')  // 0
ft_isprint(127)   // 0  (DEL is not printable)
```

---

#### `ft_strlen` — String length

```c
size_t ft_strlen(const char *s);
```

Returns the number of characters in `s` before the terminating null byte `'\0'`.

```c
ft_strlen("hello")  // 5
ft_strlen("")        // 0
```

---

#### `ft_memset` — Fill memory with a constant byte

```c
void *ft_memset(void *s, int c, size_t len);
```

Fills the first `len` bytes of memory at `s` with the byte value `c`. Returns `s`.

```c
char buf[5];
ft_memset(buf, 'A', 5);
// buf = { 'A', 'A', 'A', 'A', 'A' }
```

---

#### `ft_bzero` — Zero out memory

```c
void ft_bzero(void *s, size_t n);
```

Sets the first `n` bytes of memory at `s` to zero. Equivalent to `ft_memset(s, 0, n)`.

```c
char buf[4] = {1, 2, 3, 4};
ft_bzero(buf, 4);
// buf = { 0, 0, 0, 0 }
```

---

#### `ft_memcpy` — Copy memory area (no overlap)

```c
void *ft_memcpy(void *dest, const void *src, size_t n);
```

Copies `n` bytes from `src` to `dest`. **Behavior is undefined if regions overlap.** Use `ft_memmove` for overlapping regions. Returns `dest`.

```c
char src[] = "Hello";
char dst[6];
ft_memcpy(dst, src, 6);
// dst = "Hello\0"
```

---

#### `ft_memmove` — Copy memory area (overlap safe)

```c
void *ft_memmove(void *dest, const void *src, size_t len);
```

Same as `ft_memcpy` but handles overlapping memory regions correctly by copying through a temporary buffer internally. Returns `dest`.

```c
char buf[] = "Hello";
ft_memmove(buf + 1, buf, 4);
// buf = "HHell"
```

---

#### `ft_strlcpy` — Safe string copy

```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

Copies up to `dstsize - 1` characters from `src` to `dst`, always null-terminating the result. Returns the total length of `src` (not the number of bytes copied).

```c
char dst[4];
ft_strlcpy(dst, "Hello", 4);
// dst = "Hel\0"  (returns 5)
```

> **Edge case:** If `dstsize` is `0`, nothing is written and the length of `src` is returned.

---

#### `ft_strlcat` — Safe string concatenation

```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```

Appends `src` to `dst`, ensuring the result is null-terminated and does not exceed `dstsize` bytes total. Returns the total length that would have been created (`strlen(dst) + strlen(src)`).

```c
char dst[10] = "Hello";
ft_strlcat(dst, " World", 10);
// dst = "Hello Wor\0"  (returns 11)
```

---

#### `ft_toupper` — Convert to uppercase

```c
int ft_toupper(int c);
```

Returns the uppercase equivalent of `c` if it is a lowercase letter; otherwise returns `c` unchanged.

```c
ft_toupper('a')  // 'A'
ft_toupper('Z')  // 'Z'
ft_toupper('3')  // '3'
```

---

#### `ft_tolower` — Convert to lowercase

```c
int ft_tolower(int c);
```

Returns the lowercase equivalent of `c` if it is an uppercase letter; otherwise returns `c` unchanged.

```c
ft_tolower('A')  // 'a'
ft_tolower('z')  // 'z'
```

---

#### `ft_strchr` — Find first occurrence of character

```c
char *ft_strchr(const char *s, int c);
```

Returns a pointer to the first occurrence of `c` in `s`, or `NULL` if not found. The null terminator is considered part of the string.

```c
ft_strchr("hello", 'l')   // pointer to first 'l'
ft_strchr("hello", '\0')  // pointer to the '\0' at the end
ft_strchr("hello", 'z')   // NULL
```

---

#### `ft_strrchr` — Find last occurrence of character

```c
char *ft_strrchr(const char *s, int c);
```

Same as `ft_strchr` but returns a pointer to the **last** occurrence of `c`.

```c
ft_strrchr("hello", 'l')  // pointer to second 'l'
```

---

#### `ft_strncmp` — Compare strings (up to n bytes)

```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

Compares at most `n` characters of `s1` and `s2`. Returns `0` if equal, a negative value if `s1 < s2`, or a positive value if `s1 > s2`.

```c
ft_strncmp("abc", "abc", 3)  // 0
ft_strncmp("abc", "abd", 3)  // negative (c < d)
ft_strncmp("abc", "ab", 5)   // positive ('\0' < 'c' is false; 'c' > '\0')
```

> **Edge case:** If `n` is `0`, returns `0` regardless of the strings.

---

#### `ft_memchr` — Find byte in memory

```c
void *ft_memchr(const void *s, int c, size_t n);
```

Scans the first `n` bytes of `s` for the first occurrence of byte `c`. Returns a pointer to the match, or `NULL` if not found.

```c
char buf[] = {1, 2, 3, 4, 5};
ft_memchr(buf, 3, 5)  // pointer to buf[2]
ft_memchr(buf, 9, 5)  // NULL
```

---

#### `ft_memcmp` — Compare memory areas

```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```

Compares the first `n` bytes of `s1` and `s2`. Returns `0` if equal, or the difference between the first differing bytes.

```c
ft_memcmp("abc", "abc", 3)  // 0
ft_memcmp("abc", "axc", 3)  // negative
```

---

#### `ft_strnstr` — Find substring within n characters

```c
char	*ft_strnstr(const char *big, const char *little, size_t len);
```

Finds the first occurrence of `needle` in `haystack`, searching at most `len` characters. Returns a pointer to the match, or `NULL` if not found. If `needle` is an empty string, returns `haystack`.

```c
ft_strnstr("hello world", "world", 11)  // pointer to "world"
ft_strnstr("hello world", "world", 5)   // NULL (not within 5 chars)
ft_strnstr("hello", "", 5)              // pointer to "hello"
```

---

#### `ft_atoi` — Convert string to integer

```c
int ft_atoi(const char *str);
```

Converts the initial portion of `str` to an integer. Skips leading whitespace (`\t`, `\n`, `\v`, `\f`, `\r`, ` `), handles optional `+`/`-` sign, then reads digits.

```c
ft_atoi("  -42")    // -42
ft_atoi("+100abc")  // 100
ft_atoi("abc")      // 0
```

> **Edge case:** Behavior for values outside `INT_MIN`/`INT_MAX` is undefined (follows original `atoi`).

---

#### `ft_calloc` — Allocate and zero-initialize memory

```c
void *ft_calloc(size_t count, size_t size);
```

Allocates `count * size` bytes of memory initialized to zero. Returns `unique pointer` on allocation failure.

```c
int *arr = ft_calloc(5, sizeof(int));
// arr = { 0, 0, 0, 0, 0 }
```

> **Edge case:** If either `count` or `size` is `0`, returns a unique pointer that can be safely passed to `free()`.

---

#### `ft_strdup` — Duplicate a string

```c
char *ft_strdup(const char *s1);
```

Allocates memory and returns a copy of `s1`. The caller is responsible for freeing the returned pointer.

```c
char *dup = ft_strdup("hello");
// dup = "hello" (newly allocated)
free(dup);
```

---

### Part 2 - Additional functions

Utility functions not found in the standard libc, or implemented differently. Some internally use Part 1 functions.

---

#### `ft_substr` — Extract substring

```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

Allocates and returns a substring from `s`, starting at index `start` with maximum length `len`. Returns `NULL` on allocation failure.

> **Dependencies:** `ft_strlen`, `ft_strlcpy`

```c
ft_substr("Hello World", 6, 5)  // "World"
ft_substr("Hello", 10, 5)       // "" (start exceeds string length)
ft_substr("Hello", 0, 3)        // "Hel"
```

> **Edge case:** If `start >= strlen(s)`, returns an empty string `""`.

---

#### `ft_strjoin` — Concatenate two strings

```c
char *ft_strjoin(char const *s1, char const *s2);
```

Allocates and returns a new string that is the concatenation of `s1` and `s2`. Returns `NULL` on allocation failure. The caller must free the result.

> **Dependencies:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`

```c
ft_strjoin("Hello", " World")  // "Hello World"
ft_strjoin("", "abc")           // "abc"
```

---

#### `ft_strtrim` — Trim characters from both ends

```c
char *ft_strtrim(char const *s1, char const *set);
```

Allocates and returns a copy of `s1` with all characters contained in `set` removed from both the beginning and end. Returns `NULL` on allocation failure.

```c
ft_strtrim("  hello  ", " ")     // "hello"
ft_strtrim("xxhelloxx", "x")     // "hello"
ft_strtrim("aabcaa", "a")        // "bc"
ft_strtrim("hello", "xyz")       // "hello" (nothing to trim)
ft_strtrim("aaaa", "a")          // ""
```

> **Edge case:** If the entire string consists of characters from `set`, returns an empty string `""`.

---

#### `ft_split` — Split string by delimiter

```c
char **ft_split(char const *s, char c);
```

Allocates and returns a null-terminated array of strings obtained by splitting `s` using character `c` as delimiter. Each string is independently allocated. Returns `NULL` if any allocation fails.

> **Dependencies:** `ft_strlen`, `ft_substr`

```c
char **res = ft_split("hello world foo", ' ');
// res[0] = "hello"
// res[1] = "world"
// res[2] = "foo"
// res[3] = NULL

// Freeing:
int i = 0;
while (res[i])
    free(res[i++]);
free(res);
```

> **Edge case:** Consecutive delimiters are treated as a single delimiter — no empty strings are included in the result.

---

#### `ft_itoa` — Convert integer to string

```c
char *ft_itoa(int n);
```

Allocates and returns a string representation of the integer `n`. Handles negative numbers. Returns `NULL` on allocation failure.

```c
ft_itoa(42)           // "42"
ft_itoa(-100)         // "-100"
ft_itoa(0)            // "0"
ft_itoa(INT_MIN)      // "-2147483648"
```

---

#### `ft_strmapi` — Apply function to each character (returns new string)

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

Applies function `f` to each character of `s`, passing the index as the first argument and the character as the second. Returns a newly allocated string with the results. Returns `NULL` on allocation failure.

```c
// Convert all chars to uppercase using index-aware function
char to_upper(unsigned int i, char c) { (void)i; return ft_toupper(c); }
ft_strmapi("hello", to_upper)  // "HELLO"
```

---

#### `ft_striteri` — Apply function to each character (in place)

```c
void ft_striteri(char *s, void (*f)(unsigned int, char *));
```

Applies function `f` to each character of `s` in place, passing the index and a pointer to the character. Unlike `ft_strmapi`, this modifies the original string directly and returns nothing.

```c
void make_upper(unsigned int i, char *c) { (void)i; *c = ft_toupper(*c); }
char s[] = "hello";
ft_striteri(s, make_upper);
// s = "HELLO"
```

---

#### `ft_putchar_fd` — Output character to file descriptor

```c
void ft_putchar_fd(char c, int fd);
```

Writes character `c` to file descriptor `fd` using `write()`.

```c
ft_putchar_fd('A', 1);   // writes 'A' to stdout
ft_putchar_fd('!', 2);   // writes '!' to stderr
```

---

#### `ft_putstr_fd` — Output string to file descriptor

```c
void ft_putstr_fd(char *s, int fd);
```

Writes string `s` to file descriptor `fd`.

```c
ft_putstr_fd("Hello", 1);  // writes "Hello" to stdout
```

---

#### `ft_putendl_fd` — Output string with newline to file descriptor

```c
void ft_putendl_fd(char *s, int fd);
```

Writes string `s` followed by a newline `'\n'` to file descriptor `fd`.

```c
ft_putendl_fd("Hello", 1);  // writes "Hello\n" to stdout
```

---

#### `ft_putnbr_fd` — Output integer to file descriptor

```c
void ft_putnbr_fd(int n, int fd);
```

Writes integer `n` as a string to file descriptor `fd`. Handles negative numbers and `INT_MIN`.

```c
ft_putnbr_fd(42, 1);    // writes "42" to stdout
ft_putnbr_fd(-7, 1);    // writes "-7" to stdout
```

---

### Part 3 - Linked list

Functions to manipulate singly linked lists using the `t_list` structure.

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

`content` stores the node's data as `void *`, allowing any data type. `next` points to the next node, or `NULL` if it's the last node.

---

#### `ft_lstnew` — Create new node

```c
t_list *ft_lstnew(void *content);
```

Allocates and returns a new node with `content` set to the given value and `next` set to `NULL`. Returns `NULL` on allocation failure.

```c
t_list *node = ft_lstnew("hello");
// node->content = "hello", node->next = NULL
```

---

#### `ft_lstadd_front` — Add node at beginning

```c
void ft_lstadd_front(t_list **lst, t_list *new);
```

Inserts `new` at the front of the list. Updates `*lst` to point to the new head.

```c
// Before: A -> B -> NULL
ft_lstadd_front(&lst, new_node);
// After:  new -> A -> B -> NULL
```

---

#### `ft_lstsize` — Count nodes

```c
int ft_lstsize(t_list *lst);
```

Returns the number of nodes in the list.

```c
// A -> B -> C -> NULL
ft_lstsize(lst)  // 3
ft_lstsize(NULL) // 0
```

---

#### `ft_lstlast` — Get last node

```c
t_list *ft_lstlast(t_list *lst);
```

Returns a pointer to the last node in the list. Returns `NULL` if the list is empty.

```c
// A -> B -> C -> NULL
ft_lstlast(lst)  // pointer to C
```

---

#### `ft_lstadd_back` — Add node at end

```c
void ft_lstadd_back(t_list **lst, t_list *new);
```

Appends `new` to the end of the list. If the list is empty, `new` becomes the head.

```c
// Before: A -> B -> NULL
ft_lstadd_back(&lst, new_node);
// After:  A -> B -> new -> NULL
```

---

#### `ft_lstdelone` — Delete a single node

```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

Frees the content of `lst` using `del`, then frees the node itself. **Does not affect the next node.**

```c
ft_lstdelone(node, free);
// Frees node->content with free(), then frees node
// The rest of the list is untouched
```

> **Note:** `del` is called on `content`, not on the node pointer. The caller is responsible for unlinking the node before calling this if necessary.

---

#### `ft_lstclear` — Delete and free entire list

```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```

Deletes and frees all nodes in the list using `del` for content, then sets `*lst` to `NULL`.

```c
ft_lstclear(&lst, free);
// All nodes freed, lst = NULL
```

---

#### `ft_lstiter` — Apply function to each node

```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```

Iterates through the list and applies `f` to the `content` of each node. Does not modify the list structure.

```c
void print_content(void *content) { printf("%s\n", (char *)content); }
ft_lstiter(lst, print_content);
```

---

#### `ft_lstmap` — Create new list by applying function

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

Creates and returns a new list by applying `f` to the content of each node in `lst`. If any allocation fails, the partial new list is freed using `del` and `NULL` is returned.

```c
void *to_upper_str(void *content)
{
    // returns a new uppercase copy of the string
}
t_list *new_lst = ft_lstmap(lst, to_upper_str, free);
// new_lst contains transformed content; original lst is untouched
```

> **Note:** `del` is used only for cleanup on failure — it is not called on the original list.

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

---

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

標準 C ライブラリ関数を `ft_` プレフィックス付きで再実装したものです。外部ライブラリ関数には一切依存していません。

---

#### `ft_isalpha` — アルファベット判定

```c
int ft_isalpha(int c);
```

`c` が大文字または小文字のアルファベット（`A–Z`、`a–z`）であれば `1`、そうでなければ `0` を返す。

```c
ft_isalpha('A')   // 1
ft_isalpha('3')   // 0
ft_isalpha('\n')  // 0
```

---

#### `ft_isdigit` — 数字判定

```c
int ft_isdigit(int c);
```

`c` が数字（`0–9`）であれば `1`、そうでなければ `0` を返す。

```c
ft_isdigit('5')  // 1
ft_isdigit('a')  // 0
```

---

#### `ft_isalnum` — 英数字判定

```c
int ft_isalnum(int c);
```

`c` がアルファベットまたは数字であれば `1`、そうでなければ `0` を返す。`ft_isalpha || ft_isdigit` と等価。

```c
ft_isalnum('Z')  // 1
ft_isalnum('9')  // 1
ft_isalnum('!')  // 0
```

---

#### `ft_isascii` — ASCII 文字判定

```c
int ft_isascii(int c);
```

`c` が `0` 以上 `127` 以下であれば `1`、そうでなければ `0` を返す。

```c
ft_isascii(0)    // 1
ft_isascii(127)  // 1
ft_isascii(128)  // 0
```

---

#### `ft_isprint` — 印字可能文字判定

```c
int ft_isprint(int c);
```

`c` が印字可能文字（ASCII `32–126`、スペースを含む）であれば `1`、そうでなければ `0` を返す。

```c
ft_isprint(' ')   // 1
ft_isprint('~')   // 1
ft_isprint('\n')  // 0
ft_isprint(127)   // 0  (DEL は印字不可)
```

---

#### `ft_strlen` — 文字列の長さ

```c
size_t ft_strlen(const char *s);
```

`s` の終端ヌルバイト `'\0'` より前の文字数を返す。

```c
ft_strlen("hello")  // 5
ft_strlen("")        // 0
```

---

#### `ft_memset` — メモリを定数バイトで埋める

```c
void *ft_memset(void *s, int c, size_t len);
```

`s` から始まる `len` バイトのメモリをバイト値 `c` で埋める。`s` を返す。

```c
char buf[5];
ft_memset(buf, 'A', 5);
// buf = { 'A', 'A', 'A', 'A', 'A' }
```

---

#### `ft_bzero` — メモリをゼロで初期化

```c
void ft_bzero(void *s, size_t n);
```

`s` から始まる `n` バイトのメモリをゼロで初期化する。`ft_memset(s, 0, n)` と等価。

```c
char buf[4] = {1, 2, 3, 4};
ft_bzero(buf, 4);
// buf = { 0, 0, 0, 0 }
```

---

#### `ft_memcpy` — メモリ領域のコピー（オーバーラップ非対応）

```c
void *ft_memcpy(void *dest, const void *src, size_t n);
```

`src` から `dest` へ `n` バイトをコピーする。**領域が重なる場合の動作は未定義。** オーバーラップする場合は `ft_memmove` を使うこと。`dest` を返す。

```c
char src[] = "Hello";
char dst[6];
ft_memcpy(dst, src, 6);
// dst = "Hello\0"
```

---

#### `ft_memmove` — メモリ領域のコピー（オーバーラップ対応）

```c
void *ft_memmove(void *dest, const void *src, size_t len);
```

`ft_memcpy` と同様だが、メモリ領域が重なる場合も正しく動作する。`dest` を返す。

```c
char buf[] = "Hello";
ft_memmove(buf + 1, buf, 4);
// buf = "HHell"
```

---

#### `ft_strlcpy` — サイズ制限付き文字列コピー

```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

`src` から最大 `dstsize - 1` 文字を `dst` にコピーし、常にヌル終端する。戻り値は `src` の全長（コピーしたバイト数ではない）。

```c
char dst[4];
ft_strlcpy(dst, "Hello", 4);
// dst = "Hel\0"  (戻り値: 5)
```

> **エッジケース:** `dstsize` が `0` の場合、何も書き込まず `src` の長さを返す。

---

#### `ft_strlcat` — サイズ制限付き文字列連結

```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```

`dst` の末尾に `src` を追加し、合計が `dstsize` バイトを超えないようにヌル終端する。戻り値は作成されたであろう文字列の全長（`strlen(dst) + strlen(src)`）。

```c
char dst[10] = "Hello";
ft_strlcat(dst, " World", 10);
// dst = "Hello Wor\0"  (戻り値: 11)
```

---

#### `ft_toupper` — 大文字に変換

```c
int ft_toupper(int c);
```

`c` が小文字であれば対応する大文字を、そうでなければ `c` をそのまま返す。

```c
ft_toupper('a')  // 'A'
ft_toupper('Z')  // 'Z'
ft_toupper('3')  // '3'
```

---

#### `ft_tolower` — 小文字に変換

```c
int ft_tolower(int c);
```

`c` が大文字であれば対応する小文字を、そうでなければ `c` をそのまま返す。

```c
ft_tolower('A')  // 'a'
ft_tolower('z')  // 'z'
```

---

#### `ft_strchr` — 文字の最初の出現位置を検索

```c
char *ft_strchr(const char *s, int c);
```

`s` 内で `c` が最初に出現する位置へのポインタを返す。見つからない場合は `NULL`。ヌル終端文字も検索対象に含まれる。

```c
ft_strchr("hello", 'l')   // 最初の 'l' へのポインタ
ft_strchr("hello", '\0')  // 末尾の '\0' へのポインタ
ft_strchr("hello", 'z')   // NULL
```

---

#### `ft_strrchr` — 文字の最後の出現位置を検索

```c
char *ft_strrchr(const char *s, int c);
```

`ft_strchr` と同様だが、**最後に** 出現する位置へのポインタを返す。

```c
ft_strrchr("hello", 'l')  // 2番目の 'l' へのポインタ
```

---

#### `ft_strncmp` — 文字列の比較（最大 n バイト）

```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

`s1` と `s2` を最大 `n` 文字まで比較する。等しければ `0`、`s1 < s2` なら負の値、`s1 > s2` なら正の値を返す。

```c
ft_strncmp("abc", "abc", 3)  // 0
ft_strncmp("abc", "abd", 3)  // 負の値 (c < d)
ft_strncmp("abc", "ab", 5)   // 正の値 ('c' > '\0')
```

> **エッジケース:** `n` が `0` の場合、文字列の内容に関わらず `0` を返す。

---

#### `ft_memchr` — メモリ内のバイト検索

```c
void *ft_memchr(const void *s, int c, size_t n);
```

`s` の先頭 `n` バイトの中でバイト `c` が最初に出現する位置へのポインタを返す。見つからない場合は `NULL`。

```c
char buf[] = {1, 2, 3, 4, 5};
ft_memchr(buf, 3, 5)  // buf[2] へのポインタ
ft_memchr(buf, 9, 5)  // NULL
```

---

#### `ft_memcmp` — メモリ領域の比較

```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```

`s1` と `s2` の先頭 `n` バイトを比較する。等しければ `0`、そうでなければ最初に異なるバイトの差を返す。

```c
ft_memcmp("abc", "abc", 3)  // 0
ft_memcmp("abc", "axc", 3)  // 負の値
```

---

#### `ft_strnstr` — n 文字以内での部分文字列検索

```c
char	*ft_strnstr(const char *big, const char *little, size_t len);
```

`haystack` の先頭 `len` 文字以内で `needle` を検索し、最初に一致した位置へのポインタを返す。見つからない場合は `NULL`。`needle` が空文字列の場合は `haystack` を返す。

```c
ft_strnstr("hello world", "world", 11)  // "world" へのポインタ
ft_strnstr("hello world", "world", 5)   // NULL (5文字以内にない)
ft_strnstr("hello", "", 5)              // "hello" へのポインタ
```

---

#### `ft_atoi` — 文字列を整数に変換

```c
int ft_atoi(const char *str);
```

`str` の先頭部分を整数に変換する。先頭の空白（`\t`、`\n`、`\v`、`\f`、`\r`、` `）をスキップし、省略可能な `+`/`-` 符号を処理してから数字を読み込む。

```c
ft_atoi("  -42")    // -42
ft_atoi("+100abc")  // 100
ft_atoi("abc")      // 0
```

> **エッジケース:** `INT_MIN`/`INT_MAX` を超える値の動作は未定義（元の `atoi` の仕様に従う）。

---

#### `ft_calloc` — メモリ確保とゼロ初期化

```c
void *ft_calloc(size_t count, size_t size);
```

`count * size` バイトのメモリをゼロで初期化して確保する。確保失敗時は `unique pointer` を返す。

```c
int *arr = ft_calloc(5, sizeof(int));
// arr = { 0, 0, 0, 0, 0 }
```

> **エッジケース:** `count` または `size` が `0` の場合、`free()` に安全に渡せるユニークなポインタを返す。

---

#### `ft_strdup` — 文字列の複製

```c
char *ft_strdup(const char *s1);
```

メモリを確保して `s1` のコピーを返す。返されたポインタの解放は呼び出し元の責任。

```c
char *dup = ft_strdup("hello");
// dup = "hello" (新たに確保されたメモリ)
free(dup);
```

---

### パート2 - 追加関数

標準 libc には存在しない、または異なる形で存在するユーティリティ関数群です。一部の関数はパート1の関数を内部で利用しています。

---

#### `ft_substr` — 部分文字列の切り出し

```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

`s` のインデックス `start` から最大 `len` 文字の部分文字列を確保して返す。確保失敗時は `NULL`。

> **内部依存:** `ft_strlen`、`ft_strlcpy`

```c
ft_substr("Hello World", 6, 5)  // "World"
ft_substr("Hello", 10, 5)       // "" (start が文字列長を超える)
ft_substr("Hello", 0, 3)        // "Hel"
```

> **エッジケース:** `start >= strlen(s)` の場合、空文字列 `""` を返す。

---

#### `ft_strjoin` — 2つの文字列の連結

```c
char *ft_strjoin(char const *s1, char const *s2);
```

`s1` と `s2` を連結した新しい文字列を確保して返す。確保失敗時は `NULL`。呼び出し元が解放する責任を持つ。

> **内部依存:** `ft_strlen`、`ft_strlcpy`、`ft_strlcat`

```c
ft_strjoin("Hello", " World")  // "Hello World"
ft_strjoin("", "abc")           // "abc"
```

---

#### `ft_strtrim` — 両端からの文字削除

```c
char *ft_strtrim(char const *s1, char const *set);
```

`s1` の先頭と末尾から `set` に含まれる文字をすべて削除したコピーを確保して返す。確保失敗時は `NULL`。

```c
ft_strtrim("  hello  ", " ")     // "hello"
ft_strtrim("xxhelloxx", "x")     // "hello"
ft_strtrim("aabcaa", "a")        // "bc"
ft_strtrim("hello", "xyz")       // "hello" (削除対象なし)
ft_strtrim("aaaa", "a")          // ""
```

> **エッジケース:** 文字列全体が `set` の文字で構成される場合、空文字列 `""` を返す。

---

#### `ft_split` — デリミタによる文字列分割

```c
char **ft_split(char const *s, char c);
```

文字 `c` をデリミタとして `s` を分割し、ヌル終端の文字列配列を確保して返す。各文字列は独立して確保される。確保失敗時は `NULL`。

> **内部依存:** `ft_strlen`、`ft_substr`

```c
char **res = ft_split("hello world foo", ' ');
// res[0] = "hello"
// res[1] = "world"
// res[2] = "foo"
// res[3] = NULL

// 解放方法:
int i = 0;
while (res[i])
    free(res[i++]);
free(res);
```

> **エッジケース:** 連続するデリミタは1つとして扱われる — 空文字列は結果に含まれない。

---

#### `ft_itoa` — 整数を文字列に変換

```c
char *ft_itoa(int n);
```

整数 `n` の文字列表現を確保して返す。負の数を処理する。確保失敗時は `NULL`。

```c
ft_itoa(42)       // "42"
ft_itoa(-100)     // "-100"
ft_itoa(0)        // "0"
ft_itoa(INT_MIN)  // "-2147483648"
```

---

#### `ft_strmapi` — 各文字に関数を適用（新しい文字列を返す）

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

`s` の各文字にインデックスと文字を引数として関数 `f` を適用し、結果の新しい文字列を確保して返す。確保失敗時は `NULL`。

```c
char to_upper(unsigned int i, char c) { (void)i; return ft_toupper(c); }
ft_strmapi("hello", to_upper)  // "HELLO"
```

---

#### `ft_striteri` — 各文字に関数を適用（元の文字列を変更）

```c
void ft_striteri(char *s, void (*f)(unsigned int, char *));
```

`s` の各文字にインデックスと文字へのポインタを引数として関数 `f` を適用し、元の文字列を直接変更する。`ft_strmapi` と異なり、新しい文字列は作成せず戻り値もない。

```c
void make_upper(unsigned int i, char *c) { (void)i; *c = ft_toupper(*c); }
char s[] = "hello";
ft_striteri(s, make_upper);
// s = "HELLO"
```

---

#### `ft_putchar_fd` — ファイルディスクリプタへの文字出力

```c
void ft_putchar_fd(char c, int fd);
```

`write()` を使って文字 `c` をファイルディスクリプタ `fd` に書き込む。

```c
ft_putchar_fd('A', 1);  // stdout に 'A' を出力
ft_putchar_fd('!', 2);  // stderr に '!' を出力
```

---

#### `ft_putstr_fd` — ファイルディスクリプタへの文字列出力

```c
void ft_putstr_fd(char *s, int fd);
```

文字列 `s` をファイルディスクリプタ `fd` に書き込む。

```c
ft_putstr_fd("Hello", 1);  // stdout に "Hello" を出力
```

---

#### `ft_putendl_fd` — ファイルディスクリプタへの文字列＋改行出力

```c
void ft_putendl_fd(char *s, int fd);
```

文字列 `s` に続けて改行 `'\n'` をファイルディスクリプタ `fd` に書き込む。

```c
ft_putendl_fd("Hello", 1);  // stdout に "Hello\n" を出力
```

---

#### `ft_putnbr_fd` — ファイルディスクリプタへの整数出力

```c
void ft_putnbr_fd(int n, int fd);
```

整数 `n` を文字列としてファイルディスクリプタ `fd` に書き込む。負の数と `INT_MIN` を処理する。

```c
ft_putnbr_fd(42, 1);   // stdout に "42" を出力
ft_putnbr_fd(-7, 1);   // stdout に "-7" を出力
```

---

### パート3 - 連結リスト

`t_list` 構造体を使った単方向連結リストを操作する関数群です。

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

`content` はノードのデータを `void *` として保持し、任意の型のデータを格納できます。`next` は次のノードへのポインタ、最後のノードの場合は `NULL` です。

---

#### `ft_lstnew` — 新規ノードの作成

```c
t_list *ft_lstnew(void *content);
```

`content` に指定された値を設定し、`next` を `NULL` に初期化した新しいノードを確保して返す。確保失敗時は `NULL`。

```c
t_list *node = ft_lstnew("hello");
// node->content = "hello", node->next = NULL
```

---

#### `ft_lstadd_front` — リスト先頭へのノード追加

```c
void ft_lstadd_front(t_list **lst, t_list *new);
```

`new` をリストの先頭に挿入する。`*lst` を新しい先頭ノードに更新する。

```c
// 変更前: A -> B -> NULL
ft_lstadd_front(&lst, new_node);
// 変更後: new -> A -> B -> NULL
```

---

#### `ft_lstsize` — ノード数のカウント

```c
int ft_lstsize(t_list *lst);
```

リスト内のノード数を返す。

```c
// A -> B -> C -> NULL
ft_lstsize(lst)   // 3
ft_lstsize(NULL)  // 0
```

---

#### `ft_lstlast` — 最後のノードを取得

```c
t_list *ft_lstlast(t_list *lst);
```

リストの最後のノードへのポインタを返す。リストが空の場合は `NULL`。

```c
// A -> B -> C -> NULL
ft_lstlast(lst)  // C へのポインタ
```

---

#### `ft_lstadd_back` — リスト末尾へのノード追加

```c
void ft_lstadd_back(t_list **lst, t_list *new);
```

`new` をリストの末尾に追加する。リストが空の場合、`new` が先頭ノードになる。

```c
// 変更前: A -> B -> NULL
ft_lstadd_back(&lst, new_node);
// 変更後: A -> B -> new -> NULL
```

---

#### `ft_lstdelone` — 単一ノードの削除

```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

`del` を使って `lst` のコンテンツを解放し、ノード自体を解放する。**次のノードには影響しない。**

```c
ft_lstdelone(node, free);
// free() で node->content を解放し、その後 node を解放
// リストの残りは変更されない
```

> **注意:** `del` はノードポインタではなく `content` に対して呼び出される。必要に応じて呼び出し元がノードのリンクを外してから呼ぶ責任がある。

---

#### `ft_lstclear` — リスト全体の削除と解放

```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```

コンテンツの解放に `del` を使いながら、リストの全ノードを削除・解放し、`*lst` を `NULL` に設定する。

```c
ft_lstclear(&lst, free);
// 全ノード解放済み、lst = NULL
```

---

#### `ft_lstiter` — 各ノードへの関数適用

```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```

リストを走査し、各ノードの `content` に `f` を適用する。リスト構造は変更しない。

```c
void print_content(void *content) { printf("%s\n", (char *)content); }
ft_lstiter(lst, print_content);
```

---

#### `ft_lstmap` — 関数を適用した新しいリストの作成

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

`lst` の各ノードのコンテンツに `f` を適用した新しいリストを作成して返す。確保失敗時は `del` を使って途中の新しいリストを解放し、`NULL` を返す。

```c
void *to_upper_str(void *content)
{
    // 文字列の大文字コピーを返す
}
t_list *new_lst = ft_lstmap(lst, to_upper_str, free);
// new_lst には変換済みのコンテンツが含まれる。元の lst は変更されない
```

> **注意:** `del` は失敗時のクリーンアップにのみ使用される — 元のリストに対しては呼び出されない。

---

## 参考資料

### リファレンス

- [C 標準ライブラリ - cppreference](https://en.cppreference.com/w/c)
- [man pages オンライン](https://man7.org/linux/man-pages/)
- [42 Norm](https://github.com/42School/norminette)

### AI の使用について

このプロジェクトを通じて、Claude（Anthropic）を学習サポートツールとして使用しました。具体的には以下の用途で使用しています：

- **関数の仕様理解**：各関数の動作やエッジケースを、自分で実装する前に理解するために対話形式で仕様を理解。英語のsubjectを正しく理解するため、翻訳にも利用した。
- **概念の理解**：`static` 関数、`size_t`、ファイルディスクリプタ、関数ポインタ、連結リスト構造などの概念理解に使用。
- **コピーはしていません**：全ての実装は手書きで行い、テストを通じて動作を確認しました。