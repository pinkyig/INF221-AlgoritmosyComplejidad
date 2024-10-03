import sys

# Lee toda la entrada del flujo estándar hasta el final (control + d)
input_data = sys.stdin.read().strip()
palabras = input_data.split()

# Eliminando elementos repetidos de la lista
palabras = list(set(palabras))
combinaciones = []


for i in palabras:
    for j in palabras:
        if i != j:
            combinaciones.append(i+j)



combinaciones = list(set(combinaciones))
combinaciones.sort()


for i in combinaciones:
    print(i)
            

