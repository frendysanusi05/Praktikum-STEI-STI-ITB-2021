# Program Penduduk
# Membaca masukan N (jumlah desa dalam kecamatan) dengan asumsi N selalu valid.
# Membaca masukan N buah jumlah penduduk desa dengan asumsi selalu > 0.
# Menghitung jumlah penduduk kecamatan (total penduduk desa).

# KAMUS
# N, Sum, i, penduduk: int

# ALGORITMA
N = int(input())
Sum = 0
for i in range(N):
    penduduk = int(input())
    Sum += penduduk
print(Sum)