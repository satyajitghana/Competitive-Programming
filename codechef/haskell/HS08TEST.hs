import Text.Printf

cases = "30 120.00"

findBal :: (Double, Double) -> Double
findBal (x,y) 
    | floor x `mod` 5 == 0 && remaining > 0 = remaining
    | otherwise = y
        where remaining = y - x - 0.5

pairs [] = []
pairs xs = zip xs (tail xs)

show2Decimals :: Double -> String
show2Decimals = printf "%.2f"

solve = mapM_ (putStrLn . show2Decimals . findBal) . pairs . map read . words

-- main = solve cases
main = getContents >>= solve