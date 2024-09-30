import bisect


cantidadDeTamanios,cantidadDeColoresJoe  = input().split()
cantidadDeTamanios = int(cantidadDeTamanios)
cantidadDeColoresJoe = int(cantidadDeColoresJoe)


#Rellenando la lista de tamaños
tamanios = []
for _ in range(cantidadDeTamanios):
    tamanio = int(input())
    tamanios.append(tamanio)

tamanios.sort()


#Rellenando la lista de colores
colores = []
for _ in range(cantidadDeColoresJoe):
    color = int(input())
    colores.append(color)


#Utilizando busqueda binaria para encontrar el tamanio mas cercano por arrina

totalSobrante = 0
for color in colores:
    indice = bisect.bisect_left(tamanios, color)
    tamanio_elegido = tamanios[indice]
    totalSobrante += tamanio_elegido - color
    

print(totalSobrante)

