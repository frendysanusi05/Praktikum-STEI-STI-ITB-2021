-- DEFINISI DAN SPESIFIKASI
module ListOfInteger where

nbOcc :: [Int] -> Int -> Int
{- nbOcc l x menghasilkan jumlah kemunculan x pada list of integer l dengan syarat x adalah sebuah integer dan l mungkin kosong -}

-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [Int] -> Bool
-- isEmpty l  true jika list of integer l kosong

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [Int] -> Int
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [Int] -> [Int]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- REALISASI
nbOcc l x
   | isEmpty l = 0   -- Basis
   | x == (head l) = 1 + nbOcc (tail l) x   -- Rekurens 1
   | otherwise = nbOcc (tail l) x   -- Rekurens 2

isEmpty l = null l
