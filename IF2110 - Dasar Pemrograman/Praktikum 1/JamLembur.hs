-- Apakah Termasuk Jam lembur?          jamLembur(j,m,d)

-- DEFINISI DAN SPESIFIKASI
module JamLembur where
    jamLembur :: Int -> Int -> Int -> (Bool, Int, Int, Int)
    {- jamLembur(j,m,d) merupakan fungsi untuk menunjukkan apakah
        kru mendapatkan jam lembur atau tidak tergantung masukan
        j [0..23], m [0..59], dan d [0..59]. Jam pulang kru konser resmi
        adalah 16:30:00-}
        
    -- REALISASI
    jamLembur j m d =
        let konversiKeDetik = j*3600 + m*60 + d -- mengubah masukan ke detik
            jamKerja = 16*3600 + 30*60 -- jam pulang kru konser resmi 16:30:00
            selisihWaktu = abs(konversiKeDetik - jamKerja) -- selisih antara masukan dan jam pulang kru resmi
            selisihJam = div selisihWaktu 3600 -- konversi selisihWaktu ke bagian jam
            selisihMenit = div (selisihWaktu - selisihJam*3600) 60 -- konversi selisihWaktu ke bagian menit
            selisihDetik = mod selisihWaktu 60 -- konversi selisihWaktu ke bagian detik
        in
            if (j >= 16) && (m >= 30) then (True, selisihJam, selisihMenit, selisihDetik)
            else (False, selisihJam, selisihMenit, selisihDetik)
        
    -- APLIKASI
    -- jamLembur 17 15 00