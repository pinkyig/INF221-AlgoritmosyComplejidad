def ordenarCancionesPorAtributos():
    #Separando los atributos por espacios
    atributos = input().split()

    # Leyendo el número de canciones y guardarlas en una lista de listas
    m = int(input())
    canciones= []
    for _ in range(m):
        cancion= input().split()
        canciones.append(cancion)
    
    # Leyendo el número de comandos y guardandolos en una lista cada uno
    n = int(input())
    comandos = []
    for _ in range(n):
        comando = input()
        comandos.append(comando)

    # Ordenando las canciones por cada atributo 
    for comando in comandos:
        indice_atributo = atributos.index(comando)
        

        canciones = sorted(canciones, key=lambda x: x[indice_atributo])
        
        print(" ".join(atributos))
        
        for cancion in canciones:
            print(" ".join(cancion))
            
        print()
    

ordenarCancionesPorAtributos()

