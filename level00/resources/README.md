# **Level 00**

Pour le premier niveau on commence dans un dossier vide sans aucune information et avec des droits tres restreint.

> En fouillant on trouve deux endroits nous permettant de faire deux dossier: \
> `/var/crash` et `/tmp` qui nous permettent d'ecrire des fichiers et de les executer

Ensuite on essaye de chercher tout les fichiers lies aux utilisateurs level00 et flag00 qui nous interressent:

```
level00@SnowCrash:~$ find / -user flag00 2> /var/crash/error.txt
/usr/sbin/john
/rofs/usr/sbin/john
```

Le fichier `/usr/sbin/john` contient une chaine de caractere:

```
level00@SnowCrash:/tmp$ cat /usr/sbin/john
cdiiddwpgswtgt
```

Comme ce n'est pas le mot de passe, on suppose qu'il est encodee (code cesar) :

[Decode Cesar](https://www.dcode.fr/chiffre-cesar)

```
cdiiddwpgswtgt > nottoohardhere
```
