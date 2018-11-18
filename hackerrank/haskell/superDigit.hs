digSum :: Integer -> Integer
digSum x | x < 9 = x
         | otherwise = digSum $ x `mod` 10 + x `div` 10

findSum :: [Integer] -> Integer
findSum n = digSum $ y * digSum x
            where x = head n
                  y = head $ tail n

cases = "148 3"

solve = findSum . map read . words

main = interact $ show . solve