# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 6 Oktober 2021
# Deskripsi : Program menentukan jenis sebuah bilangan

# Program Problem 3
# Menentukan jenis sebuah bilangan
# Input: X
# Output: cetak apakah bilangan tersebut positif genap, positif ganjil, nol, atau negatif

# KAMUS
# X: int

# ALGORITMA
# Masukkan sebuah bilangan
X = int(input('Masukkan X: '))

if X > 0: # Jika X bilangan positif
    if X % 2 == 0: # Jika X bilangan genap
        print('X adalah bilangan positif genap')
    else: # Jika X bilangan ganjil
        print('X adalah bilangan positif ganjil')
    
elif X == 0: # Jika X bilangan nol
    print('X adalah bilangan nol')

else: # Jika X bilangan negatif
    print('X adalah bilangan negatif')