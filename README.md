# Substitution
Encryption algorithm in C.

Harvard CS50 course exercise.

To compile you must run `make substitution` or `clang -ggdb3 -O0 -std = c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow substitution.c - lcrypt -lcs50 -lm -o substitution`.

You must put a key of 26 non-repeated characters in the argument, it can be uppercase or lowercase.

Example:
  ```
  $ ./substitution VchPRZGJnTLsKFBDqWAXeUYMOi
  plaintext:  Hello, World!
  ciphertext: Jrssb, Ybwsp!
  ````
