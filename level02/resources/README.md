# **Level 02**

Dans ce niveau nous avons un fichier `level02.pcap` dans le repertoire courant

`.pcap` est une extension de fichier de capture reseaux donc nous allons utiliser un outils appele `wireshark` pour essayer de l'analyser

Tout d'abord il nous faut transferer le fichier `level02.pcap` en dehors de la machine virtuel, pour ca nous utilisons la commande `scp`

```
➜  cybersecurity scp -P 4242 level02@192.168.56.104:level02.pcap . 
	   _____                      _____               _     
	  / ____|                    / ____|             | |    
	 | (___  _ __   _____      _| |     _ __ __ _ ___| |__  
	  \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \ 
	  ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
	 |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|
                                                        
  Good luck & Have fun

          192.168.56.104 
level02@192.168.56.104's password: 
level02.pcap                                  100% 8302     3.4MB/s   00:00  
```

Ensuite nous donnons notre fichier a `Wireshark` pour qu'il l'analyse:
![Wireshark analyse notre fichier et nous donne cette chaine de caractere: ft_wandr...NDRel.L0L](https://github.com/Seriots/snow-crash/edit/master/level02/resources/wireshark1.png)

Nous voici avec un password mais les points represente des charactere non-imprimables donc nous regardons le code ASCII des caracteres:

![](https://github.com/Seriots/snow-crash/edit/master/level02/resources/wireshark2.png)





1.We have a level02.pcap (pcap file is WireShark file)
2.Send level02.pcap to our computer with scp command
3.Analyze the file in WireShark (open it) and follow as TCP
4. Next "." is no printable character so convert output to hexdump and see "." is carriage return
