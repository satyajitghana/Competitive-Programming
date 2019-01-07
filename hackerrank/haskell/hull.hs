import Data.List

type R1 = Double
type R2 = (R1, R1)

-- makes pair of the alternative elements in the list
makeP :: [R1] -> [R2]
makeP (x:y:rest) = (x,y) : makeP rest
makeP _ = []

cases = "6    \
\1 1    \
\2 5    \
\3 3    \
\5 3    \
\3 2    \
\2 2"

solve = makeP . map read . tail . words

main = undefined