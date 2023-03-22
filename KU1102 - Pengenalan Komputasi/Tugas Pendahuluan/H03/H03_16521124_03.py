# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 3 November 2021
# Deskripsi : Problem 3 - Program MenentukanPalindrom

# Program MenentukanPalindrom
# Menampilkan ke layar apakah string tersebut palindrom tergantung masukan string
# Asumsi masukan string hanya berisi huruf kecil (a-z)

# KAMUS
# N, i: int
# string: str
# palindrom: bool

# ALGORITMA
N = int(input('Masukkan panjang string: ')) # Input
string = input('Masukkan string: ') # Input

palindrom = True
for i in range(N):
    if (string[i] != string[(N-1) - i]): # contoh: string[2] != string[(N-1) - 2]
        palindrom = False

if palindrom: # palindrom == True
    print(f'{string} adalah palindrom')
else: # palindrom == False
    print(f'{string} bukan palindrom')