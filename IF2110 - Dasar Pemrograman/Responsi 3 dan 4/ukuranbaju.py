# Nama: Frendy Sanusi
# NIM: 16521124

# Program UkuranBaju
# Menerima 2 buah integer positif, misalnya t (tinggi) dan b (berat)
# Menuliskan kode ukuran baju (1 adalah M, 2 adalah L, 3 adalah XL) atau kode 4 adalah untuk yang tidak mendapatkan kaos.

# KAMUS
# t, b, kode : int

# ALGORITMA
t = int(input())
b = int(input())

if (t <= 150):
    kode = 1 # M
elif (t > 170) and (60 < b <= 80):
    kode = 3 # XL
elif (150 < t <= 170):
    if (b <= 80):
        kode = 2 # L
    else:
        kode = 3 # XL
else:
    kode = 4 # tidak dapat kaos

print(kode)