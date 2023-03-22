-- Menghitung Luas Segitiga             luasSegitiga(a,t)

-- DEFINISI DAN SPESIFIKASI
module LuasSegitiga where
    luasSegitiga :: Float -> Float -> Float
        {- luasSegitiga(a,t) merupakan fungsi untuk menghitung luas segitiga berdasarkan masukan
            2 buah bilangan real a dan t dengan a adalah alas segitiga dan t adalah tinggi segitiga.
            Program telah mengasumsikan masukan a > 0 dan t > 0 -}

-- REALISASI
    luasSegitiga a t = 1/2 * a * t
    -- Menghitung luas segitiga

-- APLIKASI
-- luasSegitiga 3 4