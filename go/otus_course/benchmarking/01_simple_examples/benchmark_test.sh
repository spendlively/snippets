#!/usr/bin/env bash

# custom
go test -bench BenchmarkName -benchmem -benchtime 10s

# launch all benchmarks
#go test -bench=.

# launch specific func
#go test -bench=BenchmarkFillSlice

# benchmark memory usage
#go test -bench=BenchmarkFillSlice -benchmem

# benchmark 10 seconds long (1 sec by default)
#go test -bench=BenchmarkFillSlice -benchmem -benchtime 10s

# compare 2 benchmarks
#benchstat -delta-test none old new

# repeat benchmark 5 times
#go test -bench=BenchmarkFillSlice -benchmem -benchtime 10s -count 5

# get statistics about all executions of one benchmark
#benchstat ret

# get statistics and compare 2 benchmarks
#benchstat old new


# get cpu profile and watch them
#go test -bench=. -cpuprofile=cpu.out -memprofile=mem.out .
#go tool pprof -http=":8090" bench.test cpu.out

