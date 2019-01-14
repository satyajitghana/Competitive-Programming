import Data.List

gcd' [] = 1
gcd' [x] = x
gcd' (x:xs) = gcd x (gcd' xs)

check (x:y:z:rest) = (gcd' [x, y, z] == 1) && (gcd x y /= 1 && gcd y z /= 1) && check (y:z:rest)
check _ = True

check' (x:y:rest) = check ([x, y]++rest++[x, y])

-- usage : check' [6, 10, 15, 21, 35, 55, 33]

unique [] = []
unique (x:xs) = x:unique (filter (x /=) xs)

list = [6, 15, 10, 35, 21, 14, 77, 55, 33, 22, 143, 91, 39, 26, 65]
list2 = [6, 15, 10, 35, 21, 14, 77, 55, 33, 22]

newlist list = [x | x <- permutations list, check' x, x!!0 == 6, x!!1 == 15, x!!2 == 35, x!!3 == 77]

test = mapM_ print $ (unique . newlist) [6, 15, 10, 35, 21, 14, 77, 55, 33, 22]