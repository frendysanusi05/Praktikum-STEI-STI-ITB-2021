-- DEFINISI DAN SPESIFIKASI
module ListOfCharacter where
    inverse :: [Char] -> [Char]
    {- inverse lc menghasilkan list yang berisi elemen-elemen lc dengan urutan yang dibalik. lc adalah masukan sebuah
       list of character -}

    -- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
    konso :: Char -> [Char] -> [Char]
    {- konso e lc menghasilkan sebuah list dari e (sebuah elemen) dan lc(list of elemen) dengan e sebagai elemen pertama dari list lc -}

    -- DEFINISI DAN SPESIFIKASI PREDIKAT
    isEmpty :: [Char] -> Bool
    {- isEmpty lc mengembalikan nilai True jika list of elemen lc merupakan list kosong -}

    -- DEFINISI DAN SPESIFIKASI SELEKTOR
    -- last : [Char] -> Char
    -- last lc menghasilkan elemen terakhir dari list lc dengan syarat lc bukan merupakan list kosong

    -- init : [Char] -> [Char]
    -- init lc menghasilkan list tanpa elemen terakhir dari list lc dengan syarat lc bukan merupakan list kosong

    -- REALISASI
    inverse lc
        | isEmpty lc = ""                                   -- Basis
        | otherwise = konso (last lc) (inverse (init lc))   -- Rekurens

    isEmpty lc = null lc
    konso e lc = [e] ++ lc

    -- APLIKASI
    -- inverse ['s','a','y']