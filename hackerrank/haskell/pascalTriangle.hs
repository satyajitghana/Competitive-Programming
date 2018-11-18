asum [x] = []
asum (x:xs) = (x + head xs) : asum xs

ptriangle :: Integer -> [Integer]
ptriangle 1 = [1]
ptriangle 2 = [1, 1]
ptriangle 3 = [1, 2, 1]
ptriangle n = [1]++mid++[1]
                where mid = asum $ ptriangle $ n-1

formatT x = concatMap (\ x -> show x ++ " ") x

cases = "4"

test = mapM_ (putStrLn . formatT . ptriangle) . (\x -> [1..x]) . read

main = getContents >>= test