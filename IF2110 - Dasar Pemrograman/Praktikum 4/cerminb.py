# Nama: Frendy Sanusi
# NIM: 16521124
# Tanggal: 18 Maret 2022

# Program GambarBTercermin
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar B tercermin sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan: 

# KAMUS
# Variabel
#    N : int

def GambarBTercermin(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar B tercermin dengan lebar sebesar N sesuai spesifikasi soal
# Lengkapilah kamus lokal dan algoritma prosedur di bawah ini

    # KAMUS LOKAL
    # i : int

    # ALGORITMA
    for i in range(0, N, 2):
        print(' ' * i + '*' * (N-i))
    for i in range(3, N+1, 2):
        print(' ' * (N-i) + '*' * i)

def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
# Lengkapilah kamus lokal dan algoritma fungsi di bawah ini
    
    # KAMUS LOKAL
    
    # ALGORITMA
    if (N > 0 and N % 2 == 1):
        return True

# ALGORITMA PROGRAM UTAMA
N = int(input())
if IsValid(N):  # lengkapi dengan pemanggilan fungsi IsValid
    GambarBTercermin(N)    # lengkapi dengan pemanggilan prosedur GambarBTercermin
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")