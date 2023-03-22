# Nama: Frendy Sanusi
# NIM: 16521124

# Program Beasiswa
# Membaca 2 buah bilangan real, misalnya ip (0..4) dan pot (>= 0)
# Menuliskan ke layar kategori beasiswa (0..4) yang diperoleh mahasiswa

# KAMUS
# ip, pot : float
# kategori : int

# ALGORITMA
ip = float(input())
pot = float(input())

if (ip >= 3.5):
    kategori = 4
elif (ip < 3.5) and (pot < 1):
    kategori = 1
elif (1 <= pot < 5) and (ip < 3.5):
    if (ip >= 2):
        kategori = 3
    else:
        kategori = 2
else:
    kategori = 0

print(kategori)