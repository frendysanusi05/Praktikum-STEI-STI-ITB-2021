# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 27 Oktober 2021
# Deskripsi : Problem 3 - Program Menentukan_Jenis_Bilangan_X

# Program Menentukan_Jenis_Bilangan_X
# Menentukan apakah X adalah bilangan prima

# KAMUS
# X, i: int
# bool: boolean

# ALGORITMA
# Masukkan nilai X
X = int(input('Masukkan X: '))

if (X > 1): # bilangan prima dimulai dari 2
    bool = True
    for i in range(2, X):
        if (X % i == 0) and (bool == True):
            print(f'{X} bukan bilangan prima') # Output
            bool = False # supaya proses pengecekan berhenti

    if (bool == True): # atau if (x == 2)
        print(f'{X} adalah bilangan prima') # Output
else: # X <= 1
    print(f'{X} bukan bilangan prima') # Output