brute0.exe: brute0.obj passwd0.obj
	link /nologo /libpath:..\lib /libpath:"\Program Files\Microsoft SDKs\Windows\v6.0A\Lib" brute0.obj passwd0.obj

brute0.obj: brute0.c
	cl /nologo /I..\include /c brute0.c

passwd0.obj: passwd0.c
	cl /nologo /I..\include /c passwd0.c
