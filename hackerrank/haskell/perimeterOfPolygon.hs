import Text.Printf

distance p1 p2 = sqrt ((x2 - x1) ** 2 + (y2 - y1) ** 2)
                    where x1 = fromIntegral $ fst p1
                          x2 = fromIntegral $ fst p2
                          y1 = fromIntegral $ snd p1
                          y2 = fromIntegral $ snd p2

pairs (x:xs) = (x, head xs) : pairs (tail xs)
pairs _ = []

findDist :: [(Integer, Integer)] -> [Double]
findDist []     = []
findDist [x]    = []
findDist (x:xs) = distance x (head xs) : findDist xs

cases = "4 \
\0 0 \
\0 1 \
\1 1 \
\1 0"

repeatFirst x = take (length x + 1) (cycle x)

parseInput x = pairs (tail $ map read (words x) :: [Integer])

-- try : test cases
-- to test if it works for the cases
test = printf "%.1f\n" . sum .  findDist . repeatFirst . parseInput

main = getContents >>= test