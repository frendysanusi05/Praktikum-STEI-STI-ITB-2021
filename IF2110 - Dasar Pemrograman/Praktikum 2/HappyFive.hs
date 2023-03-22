-- DEFINISI DAN SPESIFIKASI
module HappyFive where
    happyFive :: [Int] -> [Int]
    {- happyFive l menghasilkan list yang berhubungan dengan 5 atau kelipatan 5 dengan angka di dalam list
       hanya bernilai satuan atau puluhan -}

    -- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
    konso :: Int -> [Int] -> [Int]
    {- konso e l menghasilkan sebuah list dari e (sebuah elemen) dan l (list of elemen) dengan e sebagai elemen pertama dari list l -}

    -- DEFINISI DAN SPESIFIKASI PREDIKAT
    isEmpty :: [Int] -> Bool
    {- isEmpty l mengembalikan nilai True jika list of elemen l merupakan list kosong -}

    -- DEFINISI DAN SPESIFIKASI SELEKTOR
    -- head : [Int] -> Int 
    -- head l menghasilkan elemen pertama dari list l dengan syarat l bukan merupakan list kosong 

    -- tail : [Int] -> [Int] 
    -- tail l menghasilkan list tanpa elemen pertama dari list l dengan syarat l bukan merupakan list kosong

    -- REALISASI
    happyFive l
        | isEmpty l = []                                                            -- Basis
        | (mod (head l) 5) == 0 = konso (head l) (happyFive (tail l))               -- Rekurens 1
        | (head l) >= 50 && (head l) <= 59 = konso (head l) (happyFive (tail l))    -- Rekurens 2
        | otherwise = happyFive (tail l)                                            -- Rekurens 3

    isEmpty l = null l
    konso e l = [e] ++ l

    -- APLIKASI
    -- happyFive [1, 2, 7, 5, 15, 17, 13, 14, 21, 20, 51, 52]