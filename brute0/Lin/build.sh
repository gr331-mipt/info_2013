#! /bin/sh

# *** Preprocessor ***
gcc -E -P brute0.c -o brute0.i
# *** Compiler ***
gcc -S brute0.i
# *** Assembler ***
as brute0.s -o brute0.o

# *** Preprocessor ***
gcc -E -P passwd0.c -o passwd0.i
# *** Compiler ***
gcc -S passwd0.i
# *** Assembler ***
as passwd0.s -o passwd0.o

# *** Linker ***
gcc brute0.o passwd0.o -o brute0
