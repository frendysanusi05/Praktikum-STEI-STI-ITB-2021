# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 6 Oktober 2021
# Deskripsi : Problem 3 - Program menentukan kebenaran tebakan Tuan Dip

# Program menentukan kebenaran tebakan Tuan Dip
# Input: kaki, ortu, anak
# Output: Data Tuan Dip mungkin atau tidak mungkin benar

# KAMUS
# kaki, ortu, anak, kaki_lantai: int

# ALGORITMA
# Masukkan jumlah kaki yang menginjak lantai
kaki = int(input('Banyak kaki yang menginjak lantai: '))

# Masukkan banyak orang tua
ortu = int(input('Banyak orang tua: '))

# Masukkan banyak anak
anak = int(input('Banyak anak: '))

kaki_lantai = 2*ortu
if anak > kaki_lantai:
    kaki_lantai += (anak - kaki_lantai) * 2 # jumlah kaki ortu + jumlah kaki anak

if kaki < kaki_lantai or kaki % 2 == 1:
    print('Data Tuan Dip tidak mungkin benar.')
else: # kaki > kaki_lantai atau kaki berjumlah genap
    print('Data Tuan Dip mungkin benar.')