all: prime_fac

prime_fac: prime_factorization.c
	clang prime_factorization.c -lm -o prime_fac.out

test1:
	./prime_fac.out 2 > output.txt
	diff output.txt tests/test1.txt

test2:
	./prime_fac.out 9 > output.txt
	diff output.txt tests/test2.txt

test3:
	./prime_fac.out 0 > output.txt
	diff output.txt tests/test3.txt

test4:
	./prime_fac.out 18446744073709551557 > output.txt
	diff output.txt tests/test4.txt

test5:
	./prime_fac.out output.txt 1000000
	diff output.txt primes-1000000.txt

test: test1 test2 test3 test4 test5
	rm output.txt
