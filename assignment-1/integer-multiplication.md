## Programming Assignment #1

In this programming assignment you will implement one or more of the integer multiplication algorithms described in lecture.

To get the most out of this assignment, your program should restrict itself to multiplying only pairs of single-digit numbers. You can implement the grade-school algorithm if you want, but to get the most out of the assignment you'll want to implement recursive integer multiplication and/or Karatsuba's algorithm.

So: what's the product of the following two 64-digit numbers?

`3141592653589793238462643383279502884197169399375105820974944592`

`2718281828459045235360287471352662497757247093699959574966967627`

## Recursive Method

To solve it, I'm using a recursive approach, over the formula given in class:

```
    // if
    x = 1234
    y = 5678

    // then a, b, c and d will be:
    a = 12
    b = 34
    c = 56
    d = 78

    // then we can apply the formula
    10^n*ac + 10^(n/2)*(ad + bc) + bd
```

p.s. Sharing this solution, I want to show that is possible to solve this problem using JavaScript and help people that are having problems dealing with BigIntegers. I don't recommend anyone to cheat and copy this solution. Try to write it on your own first.
