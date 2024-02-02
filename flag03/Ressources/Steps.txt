1. There is an executable which print Exploit Me in the term
2. We use ghidra to rebuild original code and see there is a system function who calls "echo builtin"
3. in Env Var we have replace path to original echo to a custom echo who execute getflag because executable have the right of group flag03 

-------------------------

export PATH=/var/crash:/bin