cases = "3 \
\10 \
\5 \
\10000"

solve = mapM_ (putStrLn . show . round . sqrt . read) . tail . words

main = getContents >>= solve