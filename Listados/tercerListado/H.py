import re

# Función para transformar los caracteres de la cadena de entrada
def chng(x):
    if x == 95:  # '_'
        return x
    if x == 76:  # 'L'
        return 2
    return 0 if x in [65, 69, 73, 79, 85] else 1  # 'A', 'E', 'I', 'O', 'U' -> 0


# Función para transformar toda la cadena
def transform_input(input_string):
    transformed_list = []
    for char in input_string:
        transformed_list.append(chng(ord(char)))
    return transformed_list


# Función para verificar si una palabra es agradable.
def es_agradable(palabra):
    # Verificar si tiene al menos una 'L'
    if 'L' not in palabra:
        return False
    
    # Verificar si hay 3 vocales o consonantes consecutivas
    if re.search(r'[AEIOU]{3}', palabra) or re.search(r'[^AEIOU]{3}', palabra):
        return False
    
    return True

# Función recursiva para contar combinaciones válidas
def count(i, s, contiene_L=False):
    # Caso base: hemos procesado toda la cadena
    if i == len(s):
        return 1 if contiene_L else 0

    # Si el carácter actual no es '_'
    if s[i] != 95:
        # Verificar si hay 3 vocales o consonantes consecutivas
        if i >= 2 and (all((s[i-2], s[i-1], s[i])) or not any((s[i-2], s[i-1], s[i]))):
            return 0
        # Continuar con el siguiente carácter
        return count(i + 1, s, contiene_L or (s[i] == 2))

    total_count = 0
    # Probar con vocal (0), consonante (1) y 'L' (2)
    for j in [0, 1, 2]:
        # Determinar el multiplicador basado en el tipo de carácter
        multiplier = 5 if j == 0 else (1 if j == 2 else 20)
        
        # Si estamos en los primeros dos caracteres, no hay riesgo de 3 consecutivos
        if i < 2:
            original_value = s[i]
            s[i] = j
            total_count += multiplier * count(i + 1, s, (j == 2) or contiene_L)
            s[i] = original_value
        
        # Verificar si al agregar este carácter se forman 3 consecutivos iguales
        elif (all((s[i-2], s[i-1], j)) or not any((s[i-2], s[i-1], j))):
            continue
        else:
            original_value = s[i]
            s[i] = j
            total_count += multiplier * count(i + 1, s, (j == 2) or contiene_L)
            s[i] = original_value

    return total_count

# Función para generar todas las combinaciones posibles de palabras agradables
def contar_palabras_agradables(cadena):
    alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    guiones = cadena.count('_')

    # Transformar la entrada
    transformed_input = transform_input(cadena)
    
    # Si no hay guiones bajos, solo se valida la palabra original
    if guiones == 0:
        return 1 if es_agradable(cadena) else 0

    return count(0, transformed_input)




# Leer la entrada
cadena = input().strip()
# Imprimir el resultado
print(contar_palabras_agradables(cadena))
