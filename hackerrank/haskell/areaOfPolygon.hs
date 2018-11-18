import Text.Printf

pterm p1 p2 = x1*y2-y1*x2
                where x1 = fst p1
                      x2 = fst p2
                      y1 = snd p1
                      y2 = snd p2

pairs (x:xs) = (x, head xs) : pairs (tail xs)
pairs _ = []

findArea :: [(Double, Double)] -> [Double]
findArea []     = []
findArea [x]    = []
findArea (x:xs) = 1.0 * pterm x (head xs) : findArea xs

cases = "4 \
\0 0 \
\0 1 \
\1 1 \
\1 0"

repeatFirst x = take (length x + 1) (cycle x)

parseInput x = pairs (tail $ map read (words x) :: [Double])

-- try : test cases
-- to test if it works for the cases
test = printf "%.1f\n" . abs . (/ 2) . sum .  findArea . repeatFirst . parseInput

main = getContents >>= test