# Nama: Frendy Sanusi
# NIM: 16521124

# Program GambarSegitiga
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar segitiga sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan: 

# KAMUS
# Variabel
#    N : int

def GambarSegitiga(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar segitiga dengan tinggi sebesar N sesuai spesifikasi soal
# Lengkapilah kamus lokal dan algoritma prosedur di bawah ini
    # KAMUS LOKAL
    # j : int

    # ALGORITMA
    j = N//2
    for i in range(j+1):
        print(' ' * 2*(j-i) + '*' * (2*i + 1))
    for i in range(1, j+1):
        print(' ' * 2*i + '*' * (N-2*i) )

def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
# Lengkapilah kamus lokal dan algoritma fungsi di bawah ini
    # KAMUS LOKAL
    
    # ALGORITMA
    if (N > 0) and (N % 2 == 1):
        return True
    else:
        return False

# ALGORITMA PROGRAM UTAMA
N = int(input())
if IsValid(N):  # lengkapi dengan pemanggilan fungsi IsValid
    GambarSegitiga(N)    # lengkapi dengan pemanggilan prosedur GambarSegitiga
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")