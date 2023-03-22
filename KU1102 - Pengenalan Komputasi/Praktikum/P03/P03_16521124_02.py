# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 3 November 2021
# Deskripsi : Problem 2 - Program BermainLampuSejajar

# Program BermainLampuSejajar
# Jika menekan suatu tombol, tombol tersebut dan tombol di kanan serta di kirinya akan berubah kondisi.
# Kondisi tombol mati adalah 0
# Kondisi tombol menyala adalah 1
# Tombol diberi nomor 1 untuk paling kiri, dan bertambah 1 seterusnya.

# KAMUS
# N, berapa_kali, i, tekan, j, k, l, m: int
# arr: array [0..N-1] of int - dengan index 0 sampai dengan N-1

# ALGORITMA
# Input
N = int(input('Masukkan banyak lampu: '))
berapa_kali = int(input('Masukkan berapa kali Tuan Kil menekan tombol: '))

arr = [0 for i in range(N)] # Membuat array berukuran N dengan isi 0
for i in range(berapa_kali):
    tekan = int(input(f'Tombol yang ditekan ke {i+1}: ')) # Input
    # Jika tekan == 1, maka indexnya adalah 0 sehingga tidak bisa memproses index -1
    # Jika tekan == N, maka indexnya adalah N-1 sehingga tidak bisa memproses index N
    # Oleh karena itu, dibuatlah 3 pengandaian:
    # Kondisi tekan == bukan lampu kiri dan bukan lampu kanan
    if (tekan != 1) and (tekan != N):  
        for j in range(tekan-2, tekan+1): # memproses lampu di kirinya, lampu tersebut, dan lampu di kanannya
            # Jika arr[j] == 0, maka arr[j] diubah menjadi 1
            if (arr[j] == 0):
                arr[j] = 1
            # Jika arr[j] == 1, maka arr[j] diubah menjadi 0
            else: # arr[j] == 1
                arr[j] = 0
    # Kondisi tekan == lampu kiri
    elif (tekan == 1):
        for k in range(tekan+1): # memproses lampu tersebut dan lampu di kanannya
            if (arr[k] == 0):
                arr[k] = 1
            else: # arr[j] == 1
                arr[k] = 0
    # Kondisi tekan == lampu kanan
    elif (tekan == N):
        for l in range(tekan-2, tekan): # memproses lampu di kirinya dan lampu tersebut
            if (arr[l] == 0):
                arr[l] = 1
            else: # arr[j] == 1
                arr[l] = 0

print('Keadaan akhir rangkaian lampu adalah ', end='') # Output
for m in range(N): # hanya digunakan untuk mencetak elemen arr secara berurutan (tanpa spasi)
    if (m == N-1): # artinya ini adalah elemen arr terakhir sehingga untuk mengakhiri kalimat, digunakan tanda titik
        print(arr[m], end='.')
    else:
        print(arr[m], end='')
