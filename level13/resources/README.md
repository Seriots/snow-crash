
# **Level 13**

Pour le level13, nous avons un executable

```
level13@SnowCrash:~$ ls -l
total 8
-rwsr-sr-x 1 flag13 level13 7303 Aug 30  2015 level13
level13@SnowCrash:~$ ./level13
UID 2013 started us but we we expect 4242
```

Lorsque que l'on execute ce programme il nous dit qu'on doit avoir l'UID 4242 pour pouvoir recuperer notre token

On decompile le programme (ou on peux le deviner) et on se rend compte que le programme utilise `getuid` pour verifier si c'est le bon utilisateurs qui lance l'executable

Cependant, avec `gdb` nous pouvons modifier le contenue des variables durant l'execution, donc nous allons modifier la valeur de notre uid juste avant la verification

```
level13@SnowCrash:~$ gdb ./level13
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
(gdb) b main
Breakpoint 1 at 0x804858f
(gdb) b getuid
Breakpoint 2 at 0xb7ee4cc0
(gdb) run
Starting program: /home/user/level13/level13

Breakpoint 1, 0x0804858f in main ()
(gdb) n
Single stepping until exit from function main,
which has no line number information.

Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
(gdb) info register
eax            0x1      1
ecx            0xbffff7c4       -1073743932
edx            0xbffff754       -1073744044
ebx            0xb7fd0ff4       -1208152076
esp            0xbffff70c       0xbffff70c
ebp            0xbffff728       0xbffff728
esi            0x0      0
edi            0x0      0
eip            0xb7ee4cc0       0xb7ee4cc0 <getuid>
eflags         0x200296 [ PF AF SF IF ID ]
cs             0x73     115
ss             0x7b     123
ds             0x7b     123
es             0x7b     123
fs             0x0      0
gs             0x33     51
(gdb) n
Single stepping until exit from function getuid,
which has no line number information.
0x0804859a in main ()
(gdb) info register
eax            0x7dd    2013
ecx            0xbffff7c4       -1073743932
edx            0xbffff754       -1073744044
ebx            0xb7fd0ff4       -1208152076
esp            0xbffff710       0xbffff710
ebp            0xbffff728       0xbffff728
esi            0x0      0
edi            0x0      0
eip            0x804859a        0x804859a <main+14>
eflags         0x210246 [ PF ZF IF RF ID ]
cs             0x73     115
ss             0x7b     123
ds             0x7b     123
es             0x7b     123
fs             0x0      0
gs             0x33     51
(gdb) set $eax=4242
(gdb) n
Single stepping until exit from function main,
which has no line number information.
your token is 2A31L79asukciNyi8uppkEuSx
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6

```

> ### NEXT : [Level 14](/level14/resources/README.md)
