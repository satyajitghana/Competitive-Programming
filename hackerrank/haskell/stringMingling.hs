mstring :: String -> String -> String
mstring [] [] = []
mstring (x:xs) (y:ys) = [x] ++ [y] ++ mstring xs ys

cases = "abcde \
\pqrst"

test x = putStrLn $ mstring first second
            where first = head $ words x
                  second = head $ tail $ words x

main = getContents >>= test