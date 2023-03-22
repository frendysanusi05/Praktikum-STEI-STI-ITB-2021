-- DEFINISI DAN SPESIFIKASI
module ListOfCharacter where

konkat :: [Char] -> [Char] -> [Char]
{- konkat lc1 lc2 menerima masukan 2 buah list of character, misalnya lc1 dan lc2, yang masing-masing mungkin kosong, dan menghasilkan list baru yang merupakan penggabungan lc1 dengan lc2 (lc1 di awal). -}

-- REALISASI
konkat lc1 lc2
   | isEmpty lc2 = lc1
   | otherwise = konkat (konsDot lc1 (head lc2)) (tail lc2)

isEmpty l = null l
konsDot l e = l ++ [e]