-- DEFINISI DAN SPESIFIKASI
module OffsetList where
    offsetList :: [Int] -> (Int -> Int) -> [Int]
    {- offsetList l f menerima masukan sebuah list of integer yang melakukan perubahan nilai pada elemen list sesuai
       dengan aturan tertentu (yang ditentukan oleh sebuah fungsi offset dan menghasilkan sebuah list baru dengan
       elemen hasil offset) -}

    plus2 :: Int -> Int
    {- plus2 x akan menghasilkan list baru dengan setiap nilai elemen yang sudah bertambah 2 -}

    minus1 ::Int -> Int
    {- minus1 x akan menghasilkan list baru dengan setiap nilai elemen yang sudah berkurang 1 -}

    offKond :: Int -> Int
    {- offKond a akan menghasilkan list baru dengan nilai setiap elemen yang diubah sesuai ketentuan range tertentu -}

    -- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
    konso :: Int -> [Int] -> [Int]
    {- konso e l menghasilkan sebuah list dengan e sebagai elemen list pertama dari l dengan l tidak kosong -}

    -- DEFINISI DAN SPESIFIKASI PREDIKAT
    isEmpty :: [Int] -> Bool 
    {- isEmpty l mengembalikan nilai True jika l list kosong -}

    -- REALISASI
    offsetList l offset
        | isEmpty l = []                                        -- Basis
        | otherwise = konso (offset (head l)) (offsetList (tail l) offset)    -- Rekurens

    plus2 x = x + 2
    minus1 x = x - 1
    offKond a
        | a >= 0 && a <= 40 = 10
        | a < 0 = 0
        | a > 40 = 20

    isEmpty l = null l
    konso e l = [e] ++ l

    -- APLIKASI
    -- offset [2,9,14,1,5,6] plus2