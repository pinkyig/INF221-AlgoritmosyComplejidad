def BAPC():
    funciones = input().strip()
    numeroElementos = int(input().strip())
    lista = input().strip()

    if len(funciones) > numeroElementos:
        print("error")
        return
    
    # Eliminamos los corchetes y separamos los valores
    valoresLista = lista[1:-1].split(",") if lista[1:-1] else []

    rev = True  # Flag para indicar si la lista está invertida

    for funcion in funciones:
        if funcion == "R":
            rev = not rev
        elif funcion == "D":
            if not valoresLista:
                print("error")
                return
            if rev:
                valoresLista.pop()  # Quitar el último elemento si está invertida
            else:
                valoresLista.pop(0)  # Quitar el primer elemento si no está invertida

    if rev:
        #Imprimir la lista reconstruida en orden inverso
        print("[" + ",".join(valoresLista[::-1]) + "]")
    else:
        print("[" + ",".join(valoresLista) + "]")

testCases = int(input().strip())
for _ in range(testCases):
    BAPC()


