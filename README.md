# Diff Finder

The application is designed to solve problem of comparing two ascii based files line by line and giving the differences between two source files in terms of A\B.
Default algorithm implementations are binary search and linear search algorithms. The code is designed to be extendable in terms of implementing custom algorithms.

## Build

`make all`

## Run

Binary Comparison

`./bin/diff './sample-data/src1.lst' './sample-data/src2.lst' 'B'`

Linear Comparison

`./bin/diff './sample-data/src1.lst' './sample-data/src2.lst' 'L'`

or with make

`TEST_PARAMS="'./sample-data/src1.lst' './sample-data/src2.lst' 'B'" make test`

Reference Data File stored in [./sample-data](./sample-data)

## Performance Benchmarking

Generating sample data bash command
`for i in {1..200}; do echo -e "$i" >> ./sample-data/src1gen.lst; done;`

Generate compare file
`for i in {100..200}; do echo -e "$i" >> ./sample-data/src2gen.lst; done;`

### Benchmark Results

#### Linear Search

`./bin/diff ./sample-data/src1gen.lst ./sample-data/src2gen.lst L`

```sh
./bin/diff
./sample-data/src1gen.lst
./sample-data/src2gen.lst
L
Algorithm factory
LinearSearch algorithm is setting up...
Comparison started


#### Performance Result #####

N (A Src)   N (B Dest)   Op Count   Time (Micro Seconds)  ( A∩B ) Found   ( A\B ) Not Found
      200          101      15251                   1158            101                  99

```

#### Binary Search

`./bin/diff ./sample-data/src1gen.lst ./sample-data/src2gen.lst B`

```sh
./bin/diff
./sample-data/src1gen.lst
./sample-data/src2gen.lst
B
Algorithm factory
BinarySearch algorithm is setting up...
Comparison started


#### Performance Result #####

N (A Src)   N (B Dest)   Op Count   Time (Micro Seconds)  ( A∩B ) Found   ( A\B ) Not Found
      200          101       2058                    221            101                  99
```
