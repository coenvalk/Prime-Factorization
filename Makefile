all: prime_fac

prime_fac: prime_factorization.c
	clang prime_factorization.c -lm -o prime_fac.out
