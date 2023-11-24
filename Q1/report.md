# Question 1 

1. Part a,b,c Implemented in C, with b and c using vector instruction (to be compiled with -mavx)

2. Part 4 Reads and Writes a large array (1GB) to and from memory (with compiler optimization disabled) and the 4.sh script averages this over multiple runs. The average runs can be seen in the outputs.txt file of directory 4.
``` 
Average Memory Write Bandwidth: 5.75 GB/s
Average Memory Read Bandwidth: 7.10 GB/s
(over 10 runs, increase ITERATIONS for higher accuracy)
```
3. Part 5 takes a similar approach, performing a large number of floating point operations and averaging the runs for many iterations to compute GFLOPS.
```
Average GFLOPS: 1.43
```
4. We can notice in part 6, eval_1.sh, eval_2.sh and eval_3.sh respectively use perf events task-clock: generalization to denote CPU utilization and cache-misses: to denote number of cache misses which estimates memory usage (higher cache-misses = more memory accesses). We can notice in the respective runs (under reports of question 6) that as the vector sizes are increases, while CPU utilization roughly stays the same the cache misses consistently increase, hence indicating that all the programs are ```memory-bound```.






