-- Menghitung Konversi Suhu         konversiSuhu(t,k)

-- DEFINISI DAN SPESIFIKASI
module KonversiSuhu where
    konversiSuhu :: Float -> Char -> Float
    {- konversiSuhu(t,k) merupakan fungsi untuk mengonversi suhu t derajat
        Celcius menjadi suhu dalam satuan k. Masukan k diasumsikan selalu
        berupa 'R', 'F', dan 'K' -}
-- REALISASI
    konversiSuhu t k
        | (k == 'R') = 4/5 * t          -- Konversi ke Reamur
        | (k == 'F') = (9/5 * t) + 32   -- Konversi ke Fahrenheit
        | (k == 'K') = t + 273.15       -- Konversi ke Kelvin

-- APLIKASI
-- konversiSuhu 25 'R'