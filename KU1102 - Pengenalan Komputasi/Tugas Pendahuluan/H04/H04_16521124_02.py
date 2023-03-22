# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 17 November 2021
# Deskripsi : Problem 2 - Program BanyaknyaBilanganPositifDiDalamMatriks

# Program BanyaknyaBilanganPositifDiDalamMatriks
# Membaca matriks A berukuran N x M
# Menghitung banyaknya bilangan positif di dalam matriks
# Menampilkan hasil perhitungan dan isi matriks ke layar

# KAMUS
# N, M, count, i, j: int
# A: matriks of integer

# ALGORITMA
# Input N dan M
N = int(input('Masukkan N: '))
M = int(input('Masukkan M: '))
A = [[0 for j in range(M)] for i in range(M)] # Deklarasi matriks berukuran N x M
count = 0

for i in range(N):
    for j in range(M):
        # Mengisi elemen-elemen pada matriks A berukuran N x M
        A[i][j] = int(input(f'Masukkan nilai A[{i+1}][{j+1}]: '))
        if (A[i][j] > 0): # Jika elemennya bernilai positif
            count += 1

print(f'Ada {count} bilangan positif di matriks.')
# Mencetak isi matriks ke layar
for i in range(N):
    for j in range(M):
        print(A[i][j], end=' ')
    print()