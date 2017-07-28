This is a program that finds the prime factorization of either
one number N, or finds the prime factorization of all numbers
under N and stores that in a file.

```
USAGE:

INPUT:
./prime_fac.out 10
EXPECTED OUTPUT:
10: 2 5

INPUT:
./prime_fac.out primes.txt 10
EXPECTED OUTPUT: in primes.txt
2: 2
3: 3
4: 2 2
5: 5
6: 2 3
7: 7
8: 2 2 2
9: 3 3
```

Included is text files that are already filled with prime factorizations.

Performance: on my laptop
```
./prime_fac primes-100.txt 100
	    0.004s
./prime_fac primes-1000.txt 1000
	    0.007s
./prime_fac primes-10000.txt 10000
	    0.038s
./prime_fac primes-100000.txt 100000
	    0.279s
./prime_fac primes-1000000.txt 1000000
	    6.475s

./prime_fac 18446744073709551557
	    (largest prime that can be represented in an unsigned long long int)
	    38.397s
```
