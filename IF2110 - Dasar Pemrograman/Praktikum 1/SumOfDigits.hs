-- Menghitung Penjumlahan Digit Bilangan Positif        sumOfDigits(n)

-- DEFINISI DAN SPESIFIKASI
module SumOfDigits where
    sumOfDigits :: Int -> Int
        -- sumOfDigits n menghasilkan penjumlahan setiap bilangan tunggal yang membentuk n
        -- prekondisi n >= 0    

    -- REALISASI
    sumOfDigits n
        | (div n 10 == 0) = n                           -- BASIS
        | otherwise = sumOfDigits(div n 10) + mod n 10  -- REKURENS

    -- APLIKASI
    -- sumOfDigits 234