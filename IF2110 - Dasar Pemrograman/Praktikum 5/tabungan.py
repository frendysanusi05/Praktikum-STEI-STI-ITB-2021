# Program Tabungan
# Menerima masukan N (jumlah siswa) dengan N selalu > 0, kemudian menerima masukan N buah nilai tabungan dengan nilai tabungan selalu > 0
# Menghitung jumlah tabungan

# KAMUS
# N, Sum, i : int

# ALGORITMA
N = int(input())
Sum = 0
for i in range(N):
    Sum += int(input())
print(Sum)