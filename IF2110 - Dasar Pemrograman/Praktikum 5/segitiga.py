# Program Segitiga
# Menerima masukan alas dan tinggi dan masukan harus divalidasi agar selalu > 0. Jika <= 0 akan mengeluarkan pesan error
# Setelah valid, program akan menghitung luas segitiga

# KAMUS
# alas, tinggi, count : int
# masukan, space : string
# cek : bool

# ALGORITMA
masukan = input()
masukan += ' '
space = ' '
cek = True
count = 0

for i in masukan:
    count += 1

for i in range(count):
    if (masukan[i] == ' '):
        if cek:
            cek = False
            alas = int(space)
            space = ' '
        else:
            tinggi = int(space)
    else:
        space += masukan[i]

if (alas <= 0 or tinggi <= 0):
    print("Alas dan tinggi harus > 0")
else:
    print(round(0.5 * alas * tinggi))