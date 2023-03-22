# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 3 November 2021
# Deskripsi : Problem 1 - Program MenentukanJumlahVokalDanKonsonan

# Program MenentukanJumlahVokalDanKonsonan
# Menentukan berapa huruf vokal dan huruf konsonan dari string tersebut
# Asumsi masukan string hanya berupa huruf kecil (a-z) dan spasi

# KAMUS
# N, count_vokal, count_konsonan, char: int
# string: str

# ALGORITMA
# Input
N = int(input('Masukkan N: '))
string = input('Masukkan string: ')
# Deklarasi awal variabel
count_vokal = 0
count_konsonan = 0

for char in range(N):
    # Kondisi ketika string[char] = huruf vokal
    if (string[char] == 'a') or (string[char] == 'e') or (string[char] == 'i') or (string[char] == 'o') or (string[char] == 'u'):
        count_vokal += 1
    # Kondisi ketika string[char] = ''
    elif (string[char] == ' '):
        count_konsonan += 0 # bisa juga count_vokal += 0 karena pengecekan spasi tidak mempengaruhi jumlah vokal dan konsonan
    # Kondisi ketika string[char] = huruf konsonan
    else:
        count_konsonan += 1

print(f'Terdapat {count_vokal} huruf vokal dan {count_konsonan} huruf konsonan.') # Output