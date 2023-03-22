# Program SortSiswa
# Spesifikasi : 
# Membaca sebuah file "siswa.txt" dan mencetak ke layar semua data dalam keadaan terurut berdasarkan NoInduk.
# Proses pengurutan menggunakan insertion sort
#  Jika file teks kosong akan tercetak "File kosong". Mark file = 99999999.
import tulisdata

# KAMUS
mark = "99999999"
# namafile: string
# arr : array of dataSiswa
# row1, row2, row3 : string
# i : int

# ALGORITMA PROGRAM UTAMA
namafile = input()
tulisdata.TulisDataSiswa(namafile)

f = open(namafile, 'r')
arr = []

row1 = f.readline()
if (row1 == mark):
    print("File kosong")
else:
    while (row1 != mark):
        row2 = f.readline()
        row3 = f.readline()
        arr.append([int(row1), row2, int(row3)])
        row1 = f.readline()

    for Pass in range(1, len(arr)):
        Temp = arr[Pass]
        i = Pass - 1

        while (Temp[0] < arr[i][0]) and (i > 0):
            arr[i+1] = arr[i]
            i = i - 1

        if (Temp[0] >= arr[i][0]):
            arr[i+1] = Temp
        else:
            arr[i+1] = arr[i]
            arr[i] = Temp

    for i in range(len(arr)):
        print(arr[i][0],end=",")
        print(arr[i][1].rstrip(),end=',')
        print(arr[i][2])

f.close()