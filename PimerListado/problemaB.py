def max_jumping_distance(N, heights):
    max_distance = 0
    left = [0] * N
    right = [0] * N

    # Encuentra la montaña más alta a la izquierda de cada montaña
    left[0] = heights[0]
    for i in range(1, N):
        left[i] = max(left[i - 1], heights[i])

    # Encuentra la montaña más alta a la derecha de cada montaña
    right[N - 1] = heights[N - 1]
    for i in range(N - 2, -1, -1):
        right[i] = max(right[i + 1], heights[i])

    # Para cada montaña, calculamos la posible distancia de salto
    for i in range(1, N - 1):
        min_height = min(left[i - 1], right[i + 1])
        if min_height > heights[i]:
            max_distance = max(max_distance, min_height - heights[i])

    return max_distance


N = int(input())
heights = list(map(int, input().split()))


print(max_jumping_distance(N, heights))
