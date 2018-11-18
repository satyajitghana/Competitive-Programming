mstring :: String -> String
mstring [] = []
mstring (x:y:xs) = [y] ++ [x] ++ mstring xs

cases = "2 \
\abcdpqrs \
\az"

solve = mapM_ (putStrLn . mstring) . tail . words

main = getContents >>= solve