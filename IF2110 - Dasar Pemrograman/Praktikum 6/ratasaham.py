# Program RataRataSaham
# Spesifikasi :
# Membaca nama sebuah file text dan menuliskan nilai rata-rata kepemilikan saham dalam keadaan terurut berdasarkan IdPemilik
# Akhir file ditandai dengan mark = "99999999"
import tulisdata

# KAMUS
mark = "99999999"
# namafile: string
# arr: array of dataSiswa
# row1, row2, row3: string
# Pass, i, Sum, N, CurrentIdPemilik: int
# Temp: dataSiswa
# rata: float

# ALGORITMA PROGRAM UTAMA
namafile = input()
tulisdata.TulisDataSaham(namafile)

f = open(namafile,'r')
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

    arr.append(mark)
    i = 0
    while (i < len(arr)-1):
        CurrentIdPemilik = arr[i][0]
        Sum = 0
        N = 0
        while (arr[i][0] == CurrentIdPemilik and i < len(arr)-1):
            Sum += arr[i][2]
            N += 1
            i += 1

        rata = "%.2f" %(Sum / N)
        print(str(CurrentIdPemilik) + "=" + str(rata))

f.close()