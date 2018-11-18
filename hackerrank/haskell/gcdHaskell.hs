gcd' list = gcd (head list ) (head $ tail list)
main = interact $ show . gcd' . map read . words