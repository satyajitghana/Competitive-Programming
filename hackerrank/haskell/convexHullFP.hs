-- import Data.List
-- import Data.Tuple

-- type Point = (Double, Double)

-- hull :: [Point] -> [Point]
-- hull l = filterPoints (orderByPolarAngel (findStart l) l)

-- filterPoints :: [Point] -> [Point]
-- filterPoints (x:y:z:xs)
--     | ccw x y z = x : filterPoints (y : z : xs)
--     | otherwise = x :  filterPoints (z : xs)
-- filterPoints x = x

-- ccw :: Point -> Point -> Point -> Bool
-- ccw (x1, y1) (x2, y2) (x3, y3) = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1) >= 0

-- orderByPolarAngel :: Point -> [Point] -> [Point]
-- orderByPolarAngel p = sortBy (polarAngelCompare p)
--     where polarAngelCompare = \ f p1 p2 -> compare (polarAngel f p2) (polarAngel f p1)
--           polarAngel = \ (x1, y1) (x2, y2) -> (x2-x1)/(y2-y1)

-- findStart :: [Point] -> Point
-- findStart = swap . minimum . map swap


import Text.Printf
import Data.List

type Point = (Double, Double)

-- Euclidean distance
dist :: (Double, Double) -> (Double, Double) -> Double
dist (x1, y1) (x2, y2) = sqrt (f x1 x2 + f y1 y2)
  where f a b = (a - b)^2

-- Use Graham scan, https://en.wikipedia.org/wiki/Graham_scan
-- Three points are a counter-clockwise turn if ccw > 0, clockwise if
-- ccw < 0, and collinear if ccw = 0 because ccw is a determinant that
-- gives twice the signed  area of the triangle formed by p1, p2 and p3.
ccv :: Num a => (a, a) -> (a, a) -> (a, a) -> a
ccv (x1, y1) (x2, y2) (x3, y3) = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)

-- Find bottom-most point taking into account the x coordinate
findMinYPoint :: [Point] -> Point
findMinYPoint (p:points) = f p points
  where
    f prev [] = prev
    f p0@(x0,y0) (p1@(x1,y1):points) | y1 < y0 = f p1 points
                                     -- NB: select point with smaller x if y's are equal
                                     | (y1 == y0) && (x1 < x0) = f p1 points
                                     | otherwise = f p0 points

filterSameAngle :: [(Point, Double)] -> [Point]
filterSameAngle lst = map fst . filter snd $ r
  where
    r = zipWith (\(pa, ra) (pb, rb) -> (pa, ra /= rb)) lst (drop 1 lst ++ [head lst])

pretty :: [Point] -> String
pretty = unlines . map h
  where h (x, y) = printf "\t%0.f %.0f" x y

build :: [Point] -> [Point] -> [Point]
build hull [] = hull
build hs@[h1] ps@(p:points) = build ([p, h1]) points
build hs@(h2:h1:hull) ps@(p:points) = hull'
  where
    rightTurn = ccv h1 h2 p < 0
    collinear = ccv h2 h1 p == 0
    hull' | rightTurn = build (h1:hull) ps  -- Remove head and retry
          | collinear = build (p:h1:hull) points  -- Replace the head with p
          | otherwise = build (p:hs) points  -- Add p

convexHull :: [(Double, Double)] -> [(Double, Double)]
convexHull points = hull
  where
    -- 1) Find the bottom-most point
    p0@(x0, y0) = findMinYPoint points

    -- 2) Sort in increasing order of the angle they and the point P make with the x-axis
    sorted' = let
                 o (a, ra) (b, rb) | ra > rb = GT
                                   -- NB: Nearest points first, further points GT
                                   | (ra == rb) && (dist a p0 > dist b p0) = GT
                                   | otherwise = LT
             in sortBy o hullP

    -- For performance, instead of atan, do not calculate the
    -- angle. Use e.g. cos for ordering intead
    f (x, y) = r'
      where r = atan $ (y - y0) / (x - x0)
            -- NB: Avoid negative angles values
            r' | r < 0 = r + 2*pi
               | otherwise = r

    hullP = map (\p -> (p, f p)) $ delete p0 points

    -- 3) NB: Remove points with same angles that are closer from p0
    sorted = filterSameAngle sorted'

    -- 4) Recursively build the convex hull
    hull = build [p0] sorted

distance p1 p2 = sqrt ((x2 - x1) ** 2 + (y2 - y1) ** 2)
    where x1 = fst p1
          x2 = fst p2
          y1 = snd p1
          y2 = snd p2

repeatFirst x = take (length x + 1) (cycle x)

findDist :: [(Double, Double)] -> [Double]
findDist []     = []
findDist [x]    = []
findDist (x:xs) = distance x (head xs) : findDist xs

-- makes pair of the alternative elements in the list
makeP :: [Double] -> [Point]
makeP (x:y:rest) = (x,y) : makeP rest
makeP _ = []

cases = "6    \
\1 1    \
\2 5    \
\3 3    \
\5 3    \
\3 2    \
\2 2"

solve :: String -> IO ()
solve = printf "%.1f\n" . sum .  findDist . repeatFirst . convexHull . makeP . map read . tail . words

main = getContents >>= solve