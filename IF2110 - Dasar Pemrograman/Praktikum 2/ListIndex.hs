-- DEFINISI DAN SPESIFIKASI
module ListIndex where
    listIndex :: [Int] -> (Int -> Char) -> [Char]
    {- listIndex l f menghasilkan sebuah list of character yang melambangkan nilai-nilai indeks dari suatu list nilai integer
      dengan masukan sebuah list of integer, misalnya l sebuah fungsi yang menerima masukan sebuah integer dan menghasilkan sebuah char, misal f -}
    nilai :: Int -> Char

    -- REALISASI
    listIndex l f 
        | isEmpty l = ""
        | otherwise = konso (f (head l)) (listIndex (tail l) f)

    nilai x 
        | x >= 80 && x <= 100 = 'A'
        | x >= 70 && x < 80 = 'B'
        | x >= 65 && x < 70 = 'C'
        | x >= 55 && x < 65 = 'D'
        | x >= 0 && x < 55 = 'E'

    isEmpty l = null l
    konso e l = [e] ++ l