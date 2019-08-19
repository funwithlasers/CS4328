# Multithreading

Multithreading assignment for CS4328 - Operating Systems  

## Getting Started

Run the following commands to compile files  

```
gcc -std=c99 -lm -lpthread a.c -o a.out  
gcc -std=c99 -lm -lpthread b.c -o b.out
```

### Running the programs

to run  

```
./a.out  
./b.out
```  

for part (a) the results are correct (4000) about half the time and incorrect the other half, indicating errors in the threading process.

for part (b) the total is always 4000 indicating the treading has been done properly.
