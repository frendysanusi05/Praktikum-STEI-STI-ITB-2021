# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 27 Oktober 2021
# Deskripsi : Problem 1 - Program mengubah bilangan positif menjadi 1

# Program Mengubah_N_Menjadi_1
# Mengubah bilangan positif N menjadi 1
# Jika N bilangan ganjil, kurangi N dengan 1
# Jika N bilangan genap, bagi N dengan 2

# KAMUS
# N, i: int
# Masukkan N harus bilangan positif

# ALGORITMA
# Input
N = int(input('Masukkan bilangan N: '))

# Proses
if (N >= 1): # N harus positif
    i = 0
    while (N != 1): # pengulangan terjadi jika N tidak sama dengan 1
        if (N % 2 == 0): # jika N bilangan genap
            N /= 2
        else: # jika N bilangan ganjil
            N -= 1
        i += 1

    print(f'Banyak langkah yang diperlukan adalah {i}.') # Output