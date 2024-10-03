#Funcion que normaliza las clases sociales a una longitud máxima
def normalizar_clase(valores, longitud_maxima):
    while len(valores) < longitud_maxima:
        valores.append(2)
    return tuple(valores)



# Diccionario para convertir las clases sociales a números
class_dict = {"lower": 3, "middle": 2, "upper": 1}

T = int(input())  # número de casos de prueba

for _ in range(T):

    n = int(input())  # número de personas
    personas = []
    max_length = 0
    
    for _ in range(n):
        entrada = input().split(': ')
        nombre = entrada[0] #Nombre de la persona
        clase = entrada[1].split()[0]  #Clases sociales de la persona
        
        claseLista = [class_dict[cls] for cls in clase.split("-")][::-1]
        
        personas.append([nombre, claseLista])
        
        # Actualizando la longitud máxima de la lista de clases
        max_length = max(max_length, len(claseLista))
    
    #Normalizando
    for nombre, clase in personas:
        clase = normalizar_clase(clase, max_length)
    
    # Ordenando las personas por su clase social y nombre
    personas.sort(key=lambda t: (t[1], t[0]))

    for name, _ in personas:
        print(name)

    for _ in range(30):
        print("=", end="")
    print()




