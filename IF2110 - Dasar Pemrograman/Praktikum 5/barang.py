# Program Barang
# Membaca masukan N (jumlah barang) dengan asumsi N selalu valid (N > 0) dan masukan harga barang sebanyak N dengan asumsi masukan selalu valid.
# Menghitung jumlah harga barang

# KAMUS
# N, sum, i : int

# ALGORITMA
N = int(input()) # jumlah barang
sum = 0
for i in range(N):
    sum = sum + int(input())
print(sum)