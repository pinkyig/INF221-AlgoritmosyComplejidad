def asociar_listas(lista1Ordenada, lista2Ordenada):
    # Creando diccionario de asociaciones
    asociaciones = {}
    for i in range(len(lista1Ordenada)):
        asociaciones[lista1Ordenada[i]] = lista2Ordenada[i]
    return asociaciones


while True:
    n = int(input())
    if n == 0:
        break

    primera_lista = [int(input()) for _ in range(n)]
    segunda_lista = [int(input()) for _ in range(n)]

    # Ordenando listas y guarandolas en nuevas listas
    primera_lista_ordenada = sorted(primera_lista)
    segunda_lista_ordenada = sorted(segunda_lista)


    asociaciones = asociar_listas(primera_lista_ordenada, segunda_lista_ordenada)

    # Recorriendo la lista 1 sin ordenar y printrando los valores asociados del elemento i

    for i in primera_lista:
        print(asociaciones[i])
    print()
