-- DEFINISI DAN SPESIFIKASI
module AlternateSort where

alternateSort :: [Int] -> [Int]
{- alternateSort l menghasilkan l3 (list baru) dengan isi list berupa urutan dari elemen terkecil l1, elemen terbesar l2, dan seterusnya
   hingga l1 dan l2 menjadi list kosong. l1 dan l2 yang dimaksud adalah hasil pembagian list l menjadi 2 list dengan panjang yang sama. Jika
   panjang l adalah ganjil, maka l1 akan memiliki 1 elemen lebih banyak daripada l2. -}

getMin :: [Int] -> Int
{- getMin l menghasilkan elemen terkecil dari list l -}

delNthElement :: Int -> [Int] -> [Int]
{- delNthElement n l menghasilkan list baru tanpa elemen n dari list l -}

sortList :: [Int] -> [Int]
{- sortList l menghasilkan list baru dengan isi semua elemen l yang sudah terurut -}

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
konso :: Int -> [Int] -> [Int]
{- konso e l menghasilkan sebuah list of integer dari e (sebuah integer) dan l 
   (list of integer), dengan e sebagai elemen pertama: e o l -> l' -}

-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [Int] -> Bool
-- isEmpty l  true jika list of integer l kosong

isOneElmt :: [Int] -> Bool
-- isOneElmt l true jika list of integer l hanya mempunyai satu elemen

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [Int] -> Int
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [Int] -> [Int]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- last :: [Int] -> Int
-- last l menghasilkan elemen terakhir list l, l tidak kosong

-- init :: [Int] -> [Int]
-- init l menghasilkan list tanpa elemen terakhir list l, l tidak kosong

-- REALISASI
alternateSort l
   | isEmpty l || isOneElmt l = l
   | otherwise = konso (head (sortList l)) (konso (last(sortList l)) (alternateSort (init(tail(sortList l)))))

getMin l
   | isOneElmt l = head l
   | (head l) < (last l) = getMin (init l)
   | otherwise = getMin (tail l)

delNthElement n l
   | isEmpty l = []
   | n == (head l) = tail l
   | otherwise = konso (head l) (delNthElement n (tail l))

sortList l
   | isEmpty l = []
   | otherwise = konso (getMin l) (sortList (delNthElement (getMin l) l))

isOneElmt l = (length l) == 1
isEmpty l = null l
konso e l = [e] ++ l

-- APLIKASI
-- alternateSort[5,2,5,2,1]