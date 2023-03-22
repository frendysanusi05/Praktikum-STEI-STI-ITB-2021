-- DEFINISI DAN SPESIFIKASI
module ListOfInteger where
    nbElmt :: [Int] -> Int
    {- nbElmt l menghasilkan banyaknya elemen dalam list (0 jika list kosong) berdasarkan masukan sebuah list of integer (mungkin kosong) -}
    
    -- DEFINISI DAN SPESIFIKASI PREDIKAT
    isEmpty :: [Int] -> Bool
    {- isEmpty l mengembalikan nilai True jika list of elemen l merupakan list kosong -}

    -- DEFINISI DAN SPESIFIKASI SELEKTOR
    -- tail : [Int] -> [Int] 
    -- tail l menghasilkan list tanpa elemen pertama dari list l dengan syarat l bukan merupakan list kosong

    -- REALISASI
    nbElmt l
        | isEmpty l = 0                     -- Basis
        | otherwise = 1 + nbElmt (tail l)   -- Rekurens

    isEmpty l = null l

    -- APLIKASI
    -- nbElmt []
    -- nbElmt [1,2,3]