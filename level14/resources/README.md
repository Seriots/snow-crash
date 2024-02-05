## **Level 14**

Pour le level 14, on a rien dans le repertoire courant donc notre seul solution et d'exploiter `getflag`

Et sur le meme principe que le `level13`, avec `gdb`

```
level14@SnowCrash:~$ gdb getflag
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /bin/getflag...(no debugging symbols found)...done.
(gdb) b main
Breakpoint 1 at 0x804894a
(gdb) b getuid
Breakpoint 2 at 0x80484b0
(gdb) run
Starting program: /bin/getflag

Breakpoint 1, 0x0804894a in main ()
(gdb) n
Single stepping until exit from function main,
which has no line number information.
You should not reverse this
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
(gdb) n
Single stepping until exit from function __libc_start_main,
which has no line number information.
[Inferior 1 (process 2554) exited with code 01]
(gdb) n
The program is not being run.
(gdb) b getuid
Note: breakpoint 2 also set at pc 0xb7ee4cc0.
Breakpoint 3 at 0xb7ee4cc0
(gdb) n
The program is not being run.
(gdb) run
Starting program: /bin/getflag

Breakpoint 1, 0x0804894a in main ()
(gdb) n
Single stepping until exit from function main,
which has no line number information.
You should not reverse this
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
(gdb) info register
eax            0x1      1
ecx            0xffffffff       -1
edx            0x0      0
ebx            0xb7fd0ff4       -1208152076
esp            0xbffff750       0xbffff750
ebp            0x0      0x0
esi            0x0      0
edi            0x0      0
eip            0xb7e454d3       0xb7e454d3 <__libc_start_main+243>
eflags         0x210246 [ PF ZF IF RF ID ]
cs             0x73     115
ss             0x7b     123
ds             0x7b     123
es             0x7b     123
fs             0x0      0
gs             0x33     51
(gdb) n
Single stepping until exit from function __libc_start_main,
which has no line number information.
[Inferior 1 (process 2557) exited with code 01]
```
Ne marchant pas, on decide de decompiler le code pour comprendre pourquoi
```
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  bVar1 = false;
  lVar2 = ptrace(PTRACE_TRACEME,0,1,0);
  if (lVar2 < 0) {
    puts("You should not reverse this");
    uVa
```
On remarque qu'il y a une autre fonction dont on doit modifier la sortie

```
(gdb) b ptrace
Breakpoint 4 at 0xb7f146d0
(gdb) run
Starting program: /bin/getflag

Breakpoint 1, 0x0804894a in main ()
(gdb) n
Single stepping until exit from function main,
which has no line number information.

Breakpoint 4, 0xb7f146d0 in ptrace () from /lib/i386-linux-gnu/libc.so.6
(gdb) info register
eax            0x0      0
ecx            0xbffff7e4       -1073743900
edx            0xbffff774       -1073744012
ebx            0xb7fd0ff4       -1208152076
esp            0xbffff61c       0xbffff61c
ebp            0xbffff748       0xbffff748
esi            0x0      0
edi            0x0      0
eip            0xb7f146d0       0xb7f146d0 <ptrace>
eflags         0x200292 [ AF SF IF ID ]
cs             0x73     115
ss             0x7b     123
ds             0x7b     123
es             0x7b     123
fs             0x0      0
gs             0x33     51
(gdb) n
Single stepping until exit from function ptrace,
which has no line number information.
0x0804898e in main ()
(gdb) n
Single stepping until exit from function main,
which has no line number information.
You should not reverse this
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
(gdb) n
Single stepping until exit from function __libc_start_main,
which has no line number information.
[Inferior 1 (process 2570) exited with code 01]
(gdb) n
The program is not being run.
(gdb) run
Starting program: /bin/getflag

Breakpoint 1, 0x0804894a in main ()
(gdb) n
Single stepping until exit from function main,
which has no line number information.

Breakpoint 4, 0xb7f146d0 in ptrace () from /lib/i386-linux-gnu/libc.so.6
(gdb) n
Single stepping until exit from function ptrace,
which has no line number information.
0x0804898e in main ()
(gdb) info register
eax            0xffffffff       -1
ecx            0xb7e2b900       -1209878272
edx            0xffffffc8       -56
ebx            0xb7fd0ff4       -1208152076
esp            0xbffff620       0xbffff620
ebp            0xbffff748       0xbffff748
esi            0x0      0
edi            0x0      0
eip            0x804898e        0x804898e <main+72>
eflags         0x210282 [ SF IF RF ID ]
cs             0x73     115
ss             0x7b     123
ds             0x7b     123
es             0x7b     123
fs             0x0      0
gs             0x33     51
(gdb) set $eax=0
(gdb) n
Single stepping until exit from function main,
which has no line number information.

Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
(gdb) n
Single stepping until exit from function getuid,
which has no line number information.
0x08048b02 in main ()
(gdb) info register
eax            0x7de    2014
ecx            0xb7fda000       -1208115200
edx            0x20     32
ebx            0xb7fd0ff4       -1208152076
esp            0xbffff620       0xbffff620
ebp            0xbffff748       0xbffff748
esi            0x0      0
edi            0x0      0
eip            0x8048b02        0x8048b02 <main+444>
eflags         0x210246 [ PF ZF IF RF ID ]
cs             0x73     115
ss             0x7b     123
ds             0x7b     123
es             0x7b     123
fs             0x0      0
gs             0x33     51
(gdb) set $eax=3014
(gdb) n
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```

Voila pour notre snow_crash !
