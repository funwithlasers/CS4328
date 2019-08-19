# Paging Algorithms

Paging algorithms for CS4328 - Operating Systems  

## Getting Started

Run the following commands to compile files (no errors, few minor warnings)  

```
gcc -std=c99 paging_algos.c  

```

### Running the programs
to run  

```
./a.out
```  
a randomly generated reference string is displayed and then the user is prompted to enter number of frames.  
>Frame size should be between 1-4.

### Notes  
This code runs the LRU and Optimal paging algorithms. If (and only if) the two have an equal number of page faults, then the FIFO algorithm is run. Reference string size can be changed through the constant declared in line 6. Only numbers 1-5 are loaded into the reference string.  
