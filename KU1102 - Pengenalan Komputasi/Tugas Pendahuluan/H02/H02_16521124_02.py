# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 27 Oktober 2021
# Deskripsi : Problem 2 - Program Mencari_Bilangan_10**x_Terkecil

# Program Mencari_Bilangan_10**x_Terkecil
# Menuliskan bilangan 10**x terkecil yang lebih dari N

# KAMUS
# N, i: int
# bool: boolean

# ALGORITMA
# Masukkan nilai N
N = int(input('Masukkan N: '))

bool = False
for i in range(N+1):
    if (10**i > N) and (bool == False):
        print(10**i) # Output
        bool = True # supaya proses pengecekan berhenti