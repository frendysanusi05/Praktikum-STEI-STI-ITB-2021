-- DEFINISI DAN SPESIFIKASI
module ListOfInteger where
    setDiff :: [Int] -> [Int] -> [Int]
    {- setDiff l1 l2 mengembalikan sebuah list of integer yang elemennya adalah semua elemen l1 yang tidak ada di l2. -}

    -- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
    konso :: Int -> [Int] -> [Int]
    {- konso e l menghasilkan sebuah list dengan e sebagai elemen list pertama dari l dengan l tidak kosong -}

    -- DEFINISI DAN SPESIFIKASI PREDIKAT
    isEmpty :: [Int] -> Bool 
    {- isEmpty l mengembalikan nilai True jika l list kosong -}

    -- REALISASI
    setDiff l1 l2 
        | isEmpty l1 = []       -- Basis 1
        | isEmpty l2 = l1       -- Basis 2
        | (head l1) `notElem` l2 = konso (head l1) (setDiff (tail l1) l2) -- Rekurens 1
        | otherwise = setDiff (tail l1) l2  -- Rekurens 2

    isEmpty l = null l
    konso e l = [e] ++ l
    
    -- APLIKASI
    -- setDiff [2,4,6,8,10] [3,4,5,6]