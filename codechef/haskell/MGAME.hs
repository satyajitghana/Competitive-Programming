cases = "2 \
\1 10 \
\2 10 \
\3 10 \
\4 10 \
\5 10 \
\6 10 \
\7 10 \
\8 10 \
\9 10 \
\10 10"

pair (x:y:xs) = (x, y) : pair xs
pair _ = []

solve = mapM_ (print . calculate) . pair . map read . tail . words

calculate :: (Integer , Integer) -> Integer
calculate (1, p) = p^3
calculate (2, p) = p^3
calculate (n, p) = t1^2+t2*t1+t2^2
            where   t1 = p - (n-1)`div`2
                    t2 = p-n

main = getContents >>= solve