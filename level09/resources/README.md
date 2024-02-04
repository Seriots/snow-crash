
# **Level 09**

Pour le level09, on a un executable et un fichier `token` dans le repertoire courant


```
level09@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
```

Lorsque l'on execute `level08` avec `token` comme argument on a

```
level09@SnowCrash:~$ ./level09 token
tpmhr
```

Puis avec `aaaaaaaaaaaa`

```
level09@SnowCrash:~$ ./level09 aaaaaaaaaaaa
abcdefghijkl

```

On comprend que l'executable encode une chaine de caractere un ajoutant a chaque caractere sont index

Lorsque l'on affiche le contenue de `token`

```
level09@SnowCrash:~$ cat token
f4kmm6p|=�p�n��DB�Du{��
```

On ecrit donc un script permettant de decrypter la key en faisant l'inverse

![decode](decode_key.c)

On envoie le script avec scp a la machine

```
 scp -P 4242 ~/decode_key.c level09@192.168.56.104:/var/crash/decode_key.c
```
On copie `token` dans `/var/crash`

```
level09@SnowCrash:~$ cp token /var/crash/newtoken
level09@SnowCrash:~$ cd -
/var/crash
level09@SnowCrash:/var/crash$ chmod 777 newtoken

```

On le compile et on l'execute

```

level09@SnowCrash:/var/crash$ gcc decode_key.c
level09@SnowCrash:/var/crash$ ./a.out newtoken
f3iji1ju5yuevaus41q1afiuq
```

> ## *BONUS*
> ### NEXT : [Level 10](/level10/resources/README.md)
