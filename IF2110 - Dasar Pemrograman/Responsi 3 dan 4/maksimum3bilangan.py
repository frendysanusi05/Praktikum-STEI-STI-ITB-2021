# Program maksimum3bilangan
# Menerima masukan 3 buah integer dan menuliskan nilai terbesar di antara ketiganya

# KAMUS
# a, b, c: int

# ALGORITMA
a = int(input())
b = int(input())
c = int(input())

if (a <= b <= c) or (b <= a <= c):
    print(c)
elif (a <= c <= b) or (c <= a <= b):
    print(b)
else: # if (b <= c <= a) or (c <= b <= a)
    print(a)