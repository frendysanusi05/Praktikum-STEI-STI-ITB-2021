# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 17 November 2021
# Deskripsi : Problem 1 - Program MenghitungNilaif(X)

# Program MenghitungNilaif(X)
# Menghitung nilai f(A), f(A+1), ..., f(B) tergantung masukan A dan B

# KAMUS
# A, B, i: int

# ALGORITMA
# Fungsi sum
def sum(x):
    # Membuat fungsi sum untuk menghitung nilai f(x)
    
    # KAMUS LOKAL
    # x, fx: int
    
    # ALGORITMA
    fx = x**2 - 2*x + 5
    return fx

# Input A dan B
A = int(input('Masukkan A: '))
B = int(input('Masukkan B: '))

for i in range(A, B+1):
    print(f'f({i}) = {sum(i)}') # Memanggil fungsi sum, lalu menampilkan hasil perhitungan ke layar