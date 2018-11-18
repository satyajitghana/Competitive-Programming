import Data.List

fGroup :: String -> String
fGroup s | length s == 1 = [head s]
         | otherwise = head s : show (length s)

cases = "aaabaaaaccaaaaba"

solve = concatMap fGroup . group

main = interact solve