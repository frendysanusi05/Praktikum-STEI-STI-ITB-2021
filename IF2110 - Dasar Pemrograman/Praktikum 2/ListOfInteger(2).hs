-- DEFINISI DAN SPESIFIKASI
module ListOfInteger where

elmtKeN :: [Int] -> Int -> Int
{- elmtKeN l n menerima masukan sebuah list of integer l dan sebuah integer n dan menghasilkan elemen ke-n
   dari list of integer l. Syarat masukan n adalah 0 < n<= banyaknya elemen l dan syarat masukan l adalah tidak boleh kosong -}

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [Int] -> Int
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [Int] -> [Int]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- REALISASI
elmtKeN l n
   | n == 1 = head l   -- Basis
   | otherwise = elmtKeN (tail l) (n-1)   -- Rekurens