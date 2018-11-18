checkFunc :: [Integer] -> Bool
checkFunc x = all (\e -> occurences e x == 1) x

occurences x = length . filter (== x)

first (x:y:xs) = x : first xs
first _ = []

parseCases :: [Integer] -> [Bool]
parseCases [] = []
parseCases (x:xs) = checkFunc (first (take (fromIntegral x * 2) xs)) : parseCases (drop (fromIntegral x * 2) xs)

testCases = "2 \
\3  \
\1 1 \ 
\2 2  \
\3 3  \
\4 \
\1 2 \
\2 4 \
\3 6 \ 
\4 8"

boolTo x | x == True = "YES"
         | otherwise = "NO"

test = mapM_ putStrLn. map boolTo . parseCases . map read . tail . words

main = getContents >>= test