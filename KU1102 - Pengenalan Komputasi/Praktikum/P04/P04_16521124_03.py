# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 17 November 2021
# Deskripsi : Problem 3 - Program MenentukanKelilingPulau

# Program MenentukanKelilingPulau
# Menentukan keliling pulau
# Jika peta[i][j] == 0 maka adalah lautan
# Jika peta[i][j] == 0 maka adalah daratan

# KAMUS
# brs, klm, keliling: int

# ALGORITMA
# Input
brs = int(input('Masukkan nilai brs: '))
klm = int(input('Masukkan nilai klm: '))

# Akan dibuat seluruh baris pertama dan baris terakhir serta kolom pertama dan kolom
# terakhir menjadi 0 untuk memudahkan mencari keliling
# Sementara sisa elemen akan diisi tergantung masukan
peta = [[0 for j in range(klm+2)] for i in range(brs+2)]
for i in range(1, brs+1):
    for j in range(1, klm+1):
        peta[i][j] = int(input(f'Masukkan nilai petak baris {i} kolom {j}: '))

keliling = 0
for i in range(brs+2):
    for j in range(klm+2):
        if (peta[i][j] == 0):
            if (i != brs+1) and (j != klm+1):   # Jika i != index terakhir brs
                                                # Jika j != index terakhir klm
                if (peta[i+1][j] == 1):
                    keliling += 1
                if (peta[i][j+1] == 1):
                    keliling += 1
                if (peta[i-1][j] == 1):
                    keliling += 1
                if (peta[i][j-1] == 1):
                    keliling += 1
            else: # Jika i == index terakhir brs dan j == index terakhir klm
                if (peta[i-1][j] == 1):
                    keliling += 1
                if (peta[i][j-1] == 1):
                    keliling += 1
                
print(f'Keliling pulau tersebut adalah {keliling}.')