cases = "1 \
\3 10 \
\3 15"

find :: [Integer] -> [Integer]
find (x:y:rest) = sum [x, x * 2 .. (y-1)] : find rest
find _ = []

solve = mapM_ print . find . map read . tail . words

main = getContents >>= solve