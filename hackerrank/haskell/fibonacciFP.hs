fib 0 = 0
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)

fibs = 0 : 1 : zipWith (+) fibs ( tail fibs)

solve = mapM_ (print . (`mod` (10^8+7)) . (fibs !!) . read) . tail . words 

main = getContents >>= solve