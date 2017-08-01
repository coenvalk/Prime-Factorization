/*
MIT License

Copyright (c) 2017 Coen Valk

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void prime_fac(unsigned long long int n, FILE* F, bool print) {
  unsigned long long int i = 2;
  unsigned long long int lim = (unsigned long long int) sqrt(n);
  if (print) {
    printf("%llu: ", n);
  } else {
    fprintf(F, "%llu: ", n);
  }
  while (i <= lim) {
    if (n % i != 0) {
      i++;
    } else {
      if (print) {
	printf("%llu ", i);
      } else {
	fprintf(F, "%llu ", i);
      }
      n /= i;
    }
  }
  if (n != 1) {
    if (print) {
      printf("%llu", n);
    } else {
      fprintf(F, "%llu", n);
    }
  }
  if (print) {
    printf("\n");
  } else {
    fprintf(F, "\n");
  }
}

int main(int argc, char* argv[]) {
  unsigned long long int i = 2;
  unsigned long long int n;
  char* eptr;
  char* filename;
  FILE* F = NULL;
  if (argc == 3) {
    filename = argv[1];
    n = strtoull(argv[2], &eptr, 10);
    F = fopen(filename, "w");
    if (F) {
      while (i < n) {
	prime_fac(i, F, false);
	i++;
      }
      fclose(F);
    }
  } else if (argc == 2) {
    n = strtoull(argv[1], &eptr, 10);
    prime_fac(n, F, true);
  } else {
    printf("Usage: ./a.out filename number\nOR\n./a.out number\n");
  }
  return 0;
}
