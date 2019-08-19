# Intro to pipes

Introductory assignment to pipes in C for CS4328 - Operating Systems  

## Getting Started

Run the following commands to compile binary files

```
gcc -std=c99 pre.c -o pre  
gcc -std=c99 sort.c -o sort  
gcc -std=c99 c2p.c -o c2p  
gcc -std=c99 fork.c -o fork  
```

### Running the programs

"pre" and "sort" are labeled according to the instructions and can be run respectively with  

```
./pre  
./sort  
```  
"c2p" ("child-to-parent") is the combination of the "pre" and "sort" through a pipe and is run with  

```
./c2p
```

"fork" is the last part of the assignment where the parent forks a child process to run a unix command of variable length and is run  
```
./fork <unixcmd -flag1 -flag2 ... -flagn>  
```
