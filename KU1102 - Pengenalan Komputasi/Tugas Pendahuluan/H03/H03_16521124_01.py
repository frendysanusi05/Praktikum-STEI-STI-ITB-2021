# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 3 November 2021
# Deskripsi : Problem 1 - Program MenampilkanBilanganTerbalik

# Program MenampilkanBilanganTerbalik
# Menampilkan N buah bilangan, namun terbalik, tergantung masukan N

# KAMUS
# N, i, j: int
# arr[i]: array [0..N-1] of int - dengan index arr 0 sampai dengan N-1

# ALGORITMA
N = int(input('Masukkan N: ')) # Input

# Proses
arr = [0 for i in range(N)] # Membuat array berukuran N dengan isi 0
for i in range(N):
    # Mengisi arr dengan menggunakan looping
    arr[i] = int(input()) # Input

j = N-1 # supaya sesuai dengan index pada arr karena index dimulai dari 0 s.d. N-1
while (j >= 0):
    print(arr[j]) # Output
    j -= 1