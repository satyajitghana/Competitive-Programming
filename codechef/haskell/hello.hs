fact 0 = 1
fact n = n * fact (n-1)

fib = 0 : 1 : [x+y | (x, y) <- zip fib (tail fib)]