# Primer Informe - Evaluación Experimental de Algoritmos de Ordenamiento y Multiplicación de Matrices

Este primer informe tiene como objetivo que los estudiantes realicen una evaluación experimental de distintos algoritmos de ordenamiento y de multiplicación de matrices. El propósito es que los estudiantes implementen algunos de los algoritmos más conocidos para estos problemas y contrasten su funcionamiento con implementaciones provistas por los lenguajes de programación. Además, esta primera tarea permitirá a los estudiantes familiarizarse con herramientas de *profiling* y con la creación de códigos que les permitan medir las características solicitadas.

## Entrega

La entrega de esta tarea consistirá en un informe escrito (en formato `.pdf`) y los códigos asociados a los experimentos reportados en el informe. Estos códigos deben estar disponibles públicamente en un repositorio como Bitbucket o GitHub, y estar correctamente referenciados dentro del informe.

## Algoritmos para Benchmarks

### Algoritmos de Ordenamiento

Los algoritmos mínimos a ser considerados para los *benchmarks* de ordenamiento son:

- Un algoritmo cuadrático de ordenamiento (Selection Sort, Bubble Sort, Insertion Sort u otro).
- Mergesort.
- Quicksort.
- Función de *sorting* implementada en la biblioteca estándar del lenguaje de programación.

### Algoritmos de Multiplicación de Matrices

Los algoritmos mínimos a ser considerados para los *benchmarks* de multiplicación de matrices son:

- Algoritmo iterativo cúbico tradicional.
- Algoritmo iterativo cúbico optimizado para mantener la localidad de los datos (transponiendo la segunda matriz).
- Algoritmo de Strassen.

## Generación y Formato de Datos

Los juegos de datos (*Datasets*) deberán ser generados por cada estudiante, utilizando el método que considere oportuno. Se aconseja generar conjuntos de datos diversos que varíen en tamaño y características (e.g., semi ordenados, parcialmente ordenados, multiplicación de matrices cuadradas de la misma dimensión vs matrices de distintas dimensiones, etc). Los juegos de datos deben ser guardados en archivos (binario o texto) en un formato estándar. Cada algoritmo evaluado deberá tomar la entrada en el formato estándar especificado e imprimir el resultado en un formato de salida, también estándar y definido por el estudiante.

## Secciones Solicitadas en el Informe

### Introducción

- Breve reseña de todo el trabajo realizado.
- Descripción a alto nivel de los problemas y algoritmos (implementados y provistos por bibliotecas).
- Herramientas, fuentes de datos y conclusiones preliminares.

### Descripción de los Algoritmos a Ser Comparados

- Entrega de todos los códigos como adjuntos al documento o enlaces a dónde encontrarlos en el mismo.
- El código debe estar documentado y seguir algún estándar de codificación adoptado por el estudiante.
- Para cada algoritmo, especificar una descripción general y consignar el costo del mejor y peor caso.
- Reseñar las funciones de bibliotecas estándar utilizadas: ¿Qué algoritmos funcionan por debajo y cuáles son sus costos?

### Descripción de los Datasets

- Listado de los conjuntos de datos utilizados y su caracterización (tamaño del *dataset*, valores límites u otras características consideradas).
- Especificar el tipo de archivos utilizado para la entrada y salida, así como el formato de los mismos.

### Resultados Experimentales

- Mostrar los resultados comparativos de los distintos algoritmos en forma de tablas y gráficos.
- Comentar observaciones relevantes dentro del texto que se consideren importantes resaltar en las tablas/gráficos.

### Conclusiones

- Observaciones, comentarios y sentencias que evalúen el trabajo realizado y los resultados obtenidos.
- Discusión sobre el poder predictivo del análisis asintótico del peor/mejor caso.
- Importancia de aspectos relacionados con la implementación (e.g., algoritmos *in-place* vs no *in-place*, preservación de la localidad de los datos, entre otros) en los resultados experimentales.
