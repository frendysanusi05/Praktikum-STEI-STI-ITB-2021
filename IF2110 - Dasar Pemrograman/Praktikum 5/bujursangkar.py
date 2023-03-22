# Program Bujursangkar
# Menghitung luas bujur sangkar (persegi) tergantung masukan yang divalidasi

# KAMUS
# sisi: int

# ALGORITMA
sisi = int(input())

if (sisi > 0):
    print(sisi**2)
else:
    print("Sisi harus > 0")