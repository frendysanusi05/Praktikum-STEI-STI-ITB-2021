# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 17 November 2021
# Deskripsi : Problem 3 - Program MatriksSegitigaPascal

# Program MatriksSegitigaPascal
# Inisialisasi matriks dengan semua nilai baris pertama bernilai 1
# dan semua nilai kolom pertama bernilai 1.
# Mengisi setiap isi matriks yang belum ada nilainya dengan
# jumlah dari bilangan di atas dan kirinya tergantung masukan N.

# KAMUS
# N, i, j: int
# A: matriks of integer

# ALGORITMA
# Input N
N = int(input('Masukkan N: '))
# Inisialisasi matriks A berukuran N x N dengan semua elemen-elemen matriks bernilai 1
A = [[1 for j in range(N)] for i in range(N)]

# Karena semua nilai baris pertama dan kolom pertama harus bernilai 1,
# maka akan dicari nilai bilangan dari baris kedua dan kolom kedua sampai baris dan kolom ke-N
for i in range(1, N):
    for j in range(1, N):
        # Mengisi matriks dengan jumlah dari bilangan di atas dan kirinya
        # A[i-1][j] = bilangan di atas elemen A[i][j]
        # A[i][j-1] = bilangan di kiri elemen A[i][j]
        A[i][j] = A[i-1][j] + A[i][j-1]

# Mencetak isi matriks ke layar
for i in range(N):
    for j in range(N):
        print(A[i][j], end=' ')
    print()