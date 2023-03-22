-- Klasifikasi Komputer         klasifikasi(cpu, gpu, hd)

-- DEFINISI DAN SPESIFIKASI
module KlasifikasiKomputer where
    klasifikasi :: Int -> Int -> Int -> Int
    {- klasifikasi(cpu, gpu, hd) merupakan fungsi untuk mengelompokkan
        komputer berdasarkan masukan cpu (kemampuan CPU), gpu (kemampuan GPU),
        dan hd (kemampuan harddisk) -}

-- REALISASI
    klasifikasi cpu gpu hd
        | (cpu < 2) || (gpu < 2) || (hd < 2) = 1
        | (cpu < 5) || (gpu < 5) = 2
        | (cpu <= 7) && (gpu <= 7) && (hd <= 7) = 3
        | (cpu <= 7) || (gpu <= 7) || (hd <= 7) = 4
        | (cpu > 7) && (gpu > 7) && (hd > 7) = 5
    -- Prioritas kelompok diurut dari nomor kelompok yang terkecil

-- APLIKASI
-- klasifikasi 8 9 4