# NIM/Nama : 16521124/Frendy Sanusi
# Tanggal : 17 November 2021
# Deskripsi : Problem 1 - Program MenghitungVolumeRumah

# Program MenghitungVolumeRumah
# Menghitung volume rumah yang terbentuk dari
# gabungan kubus dan limas segi empat beraturan tergantung masukan sisi kubus dan tinggi limas
# Diberikan besar sisi alas limas sama besar dengan sisi kubus

# KAMUS
# rusuk, t_limas, total_volume: float
# asumsi masukan berupa bilangan positif dan satuan panjang adalah meter

# ALGORITMA
def kubus(r): # Fungsi kubus
    # Membuat fungsi kubus untuk menghitung volume kubus
    
    # KAMUS LOKAL
    # r, volume_kubus: float
    
    # ALGORITMA
    volume_kubus = r**3 # Rumus volume kubus
    return volume_kubus

def limas4(r, t): # Fungsi limas4
    # Membuat fungsi limas untuk menghitung volume limas segi empat beraturan
    
    # KAMUS LOKAL
    # r, t, volume_limas: float
    
    # ALGORITMA
    volume_limas = (1/3) * r**2 * t # Rumus volume limas segi empat beraturan
    return volume_limas

# Input
rusuk = float(input('Masukkan panjang sisi kubus: '))
t_limas = float(input('Masukkan tinggi limas: '))

total_volume = kubus(rusuk) + limas4(rusuk, t_limas) # Memanggil fungsi kubus dan fungsi limas4
print(f'Volume rumah yang terbentuk adalah {total_volume} meter kubik.')