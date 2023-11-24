# Question 2
- binaries stores the compiled cpp outputs, programs are the implemented questions, and reports contains the outputs from the shell scripts implemented (eval_b and c). 

1. Part 2only iterates to 2^9 because of memory constraint issues, this can be run on a system with higher memory capacity with 2^14 by simply modifying the shell script mentioned above. Also, only the L1 and L2 cache information is denoted due to unavailability of L3 events on the processor this code is implemented on. (CPI values are calculated and added in the markdown separately)

```
Running for value: 16
l2_cache_misses_from_dc_misses: 14702
l2_cache_accesses_from_dc_misses: 52665
L1-dcache-load-misses: 35135
L1-dcache-loads: 1835831
L1-icache-load-misses: 2590
L1-icache-loads: 1082943
instructions: 3378966
cycles: 912321
CPI : 0.27
--------------------------------
Running for value: 32
l2_cache_misses_from_dc_misses: 24836
l2_cache_accesses_from_dc_misses: 53973
L1-dcache-load-misses: 36358
L1-dcache-loads: 3122027
L1-icache-load-misses: 2656
L1-icache-loads: 1100565
instructions: 7023847
cycles: 1784632
CPI : 0.25
--------------------------------
Running for value: 64
l2_cache_misses_from_dc_misses: 52527
l2_cache_accesses_from_dc_misses: 57573
L1-dcache-load-misses: 39934
L1-dcache-loads: 13124805
L1-icache-load-misses: 2537
L1-icache-loads: 1126934
instructions: 35754067
cycles: 9173645
CPI : 0.256
--------------------------------
Running for value: 128
l2_cache_misses_from_dc_misses: 14226
l2_cache_accesses_from_dc_misses: 285156
L1-dcache-load-misses: 254021
L1-dcache-loads: 90677394
L1-icache-load-misses: 4508
L1-icache-loads: 1264955
instructions: 279925833
cycles: 81411831
CPI : 0.29
--------------------------------
Running for value: 256
l2_cache_misses_from_dc_misses: 33201
l2_cache_accesses_from_dc_misses: 2648235
L1-dcache-load-misses: 2635758
L1-dcache-loads: 711330621
L1-icache-load-misses: 4676
L1-icache-loads: 2340147
instructions: 2164980625
cycles: 608009915
CPI : 0.028
--------------------------------
Running for value: 512
l2_cache_misses_from_dc_misses: 5701839
l2_cache_accesses_from_dc_misses: 195717300
L1-dcache-load-misses: 195766969
L1-dcache-loads: 5674419023
L1-icache-load-misses: 12694
L1-icache-loads: 8622775
instructions: 17136748551
cycles: 5041962712
CPI : 0.29
--------------------------------

```
---
2. The tiled multiplication is implemented and we can see the respective cache grind outputs in the reports_tile.txt inside reports directory. We notice that
```
There is a steady decrease in number of issued first level cache access as tile size increases. Since we tested upto 64 and that has the lowest number of instructions, and it has the lowest number of cache miss ratio in the LLd and LLi level (which represents l2 in this sytem):
Cache Miss Ratio with tile size = 64 : 0.027
Cache Miss Ratio with tile size = 32 : 0.040
Cache Miss Ratio with tile size = 16 : 0.3
Cache Miss Ratio with tile size = 8 : 0.24
```
We can conclude that 64 is the optimal tile size for the onces tested on. 

```
Instruction with size 512 in tiled multiplication : 168786755756 (command not shown, used perf)
Instruction with size 512 in strassesns: 1254085595269 
Ratio ~ Strassens takes around 7.4 times more instructions. 
```





