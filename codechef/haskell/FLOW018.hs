cases = "3 \ 
\3 \
\4 \
\5"

solve = mapM_ ( putStrLn . show . (\x -> product [1..x]) . read) . tail . words

main = getContents >>= solve