@REM *** Preprocessor ***
cl /nologo /EP /I..\include brute0.c > brute0.i
@REM *** Compiler ***
cl /nologo /FA /TC /c brute0.i
@REM *** Assembler ***
ml /nologo /I..\include /c brute0.asm

@REM *** Preprocessor ***
cl /nologo /EP /I..\include passwd0.c > passwd0.i
@REM *** Compiler ***
cl /nologo /FA /TC /c passwd0.i
@REM *** Assembler ***
ml /nologo /I..\include /c passwd0.asm

@REM *** Linker ***
link /nologo /libpath:..\lib /libpath:"\Program Files\Microsoft SDKs\Windows\v6.0A\Lib" brute0.obj passwd0.obj