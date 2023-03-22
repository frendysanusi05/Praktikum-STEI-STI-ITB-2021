# Module untuk menulis data file keperluan praktikum

# type dataSiswa  : (NoInduk: string, KodeKursus : string, Nilai : integer)

def TulisDataSiswa(namafile):
    # Menulis data mahasiswa ke file namafile
    # Kamus
    # f : file teks
    # Algoritma
    f = open(namafile,'w')
    row1 = input().rstrip() # NoInduk
    # simpan sampai teks = 99999999
    while (row1 != "99999999"):
        # asumsikan selalu baca 3 data
        f.write(row1 + "\n") # write NoInduk
        row2 = input() # KdKul
        f.write(row2 + "\n") # write KodeKursus
        row3 = input() # nilai
        f.write(row3 + "\n") # write Nilai
        # simpan ke file
        row1 = input().rstrip() # next-NoInduk
    # tulis mark
    f.write(row1) # mark
    f.close()
    return