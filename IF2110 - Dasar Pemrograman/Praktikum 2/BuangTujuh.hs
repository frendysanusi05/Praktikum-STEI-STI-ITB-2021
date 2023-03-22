-- DEFINISI DAN SPESIFIKASI
module BuangTujuh where

buangTujuh :: [Int] -> [Int]
{- buangTujuh l menghasilkan list baru tanpa memiliki elemen yang berhubungan dengan angka 7 atau kelipatan 7.
   Asumsi masukan adalah list yang hanya memiliki angka berupa satuan atau puluhan. -}

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
konso :: Int -> [Int] -> [Int]
{- konso e l menghasilkan sebuah list of integer dari e (sebuah integer) dan l 
   (list of integer), dengan e sebagai elemen pertama: e o l -> l' -}

-- DEFINISI DAN SPESIFIKASI PREDIKAT
isEmpty :: [Int] -> Bool
-- isEmpty l  true jika list of integer l kosong

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- head :: [Int] -> Int
-- head l menghasilkan elemen pertama list l, l tidak kosong

-- tail :: [Int] -> [Int]
-- tail l menghasilkan list tanpa elemen pertama list l, l tidak kosong

-- REALISASI
buangTujuh l
   | isEmpty l = []   -- Basis
   | mod (head l) 7 == 0 || mod (head l) 10 == 7 || div (head l) 10 == 7 = buangTujuh (tail l)   -- Rekurens 1
   | otherwise = konso (head l) (buangTujuh (tail l))   -- Rekurens 2

isEmpty l = null l
konso e l = [e] ++ l