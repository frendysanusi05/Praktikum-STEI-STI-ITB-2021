# Program Themepark
# Program menuliskan TRUE ke layar jika orang dengan tinggi t dan berat b, boleh menaiki kendaraan atraksi dengan kategori k sesuai dengan ketentuan dan FALSE jika tidak.
# Jika tidak boleh menaiki kategori apa pun, berarti nilai k = 0.

# KAMUS
# t, b, k: int

# ALGORITMA
t = int(input()) # t > 0, t = tinggi badan (cm)
b = int(input()) # b > 0, b = berat badan (kg)
k = int(input()) # k = kategori kendaraan atraksi (bernilai 0..4)

a = "TRUE"
c = "FALSE"

if (t > 100) and (b <= 150):
    if (k > 1):
        print(a)
    else: # (k == 1) or (k == 0)
        print(c)
elif (t <= 100)and (b <= 150):
    if (b > 30):
        if (k == 1) or (k == 2):
            print(a)
        else:
            print(c)
    else: # (b <= 30)
        if (k == 1):
            print(a)
        else:
            print(c)
elif (b > 150):
    if (t <= 100):
        if (k == 2):
            print(a)
        else:
            print(c)
    elif (100 < t <= 200):
        if (k == 2) or (k == 3):
            print(a)
        else:
            print(c)
    else:
        if (k == 0):
            print(a)
        else:
            print(c)