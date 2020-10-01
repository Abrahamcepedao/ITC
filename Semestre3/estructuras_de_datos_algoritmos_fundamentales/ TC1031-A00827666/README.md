# TC-1031 - A00827666
Este repositorio contienen todos los entregables relacionados a la materia (Estructuras de datos y algoritmos fundamentales)

## Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales
### Situación
1. Abre el archivo de entrada llamado "bitacora.txt", lee todos los registros y almacena los datos en un vector.
    * Crea una estructura de datos (**struct**) para almacenar todos los campos del archivo.
2. Ordene la información por fecha para la realización de las búsquedas.
    * Apóyate con métodos, atributos y/o sobre carga de operadores en tu estructura para manejar el ordenamiento de los registros del archivo.
    * Utiliza uno de los algoritmos de ordenamiento que hiciste en la actividad 1.2.
3. Solicite al usuario las fecha y hora de inicio y fin de búsqueda de información.
    * Solicite al usuario las fecha y hora de inicio y fin de búsqueda de información.
4. Despliegue los registros correspondientes a esas fechas.
5. Almacenar en un archivo el resultado del ordenamiento.
6. Realizar una investigación y reflexión en forma individual de la importancia y eficiencia del uso de los diferentes algoritmos de ordenamiento y búsqueda en una situación problema de esta naturaleza, generando un documento llamado **"ReflexAct1.3.pdf"**

### Solución
* Se hizo una sobrecarga de operadores (**>, >=**) en la **struct** para poder hacer el ordenamiento de los datos de entrada
* Se utilizó el método de **Quick Sort** para ordenar los datos de entrada
* Se utilizó una busqueda binaria para encontrar el índice inicial y final de un elemento
    * Por ejemplo: Si el usuario ingresa el mes **Jun** se  encontraría tanto el primer como el útlimo índice que contiene este mes. Esto con el objetivo de que al buscar el día, se reduzca el rango de búsqueda a únicamente ese mes. Este proceso se lleva a cabo hasta llegar a la búsqueda de los segundos.
