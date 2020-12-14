# Enmascarador

Con el objetivo de comparar la performance de las instrucciones SIMD con las instrucciones aritméticas y lógicas de la ALU, se desarrolló una aplicación de línea de comandos que combina dos imágenes usando una máscara de selección. Se implementaron dos versiones de esta operación, una en lenguaje C y otra utilizando instrucciones SIMD en el lenguaje ensamblador.

# Herramientas

Para desarrollar la aplicación se utilizaron las siguentes herramientas:
- GraphicsMagick: para la conversión de imágenes a extensión RGB
- XnViewMP: para redimensionar las imágenes
- NASM para assembler
- GCC para C

# Desarrollo

El desarrollo de la aplicación cuenta con 3 partes importantes que se pueden diferenciar facilmente: las funciones de lectura y escritura de los archivos RGB, la función de enmascarar_c y la función de enmascarar_asm.

Por otro lado, se tiene un programa general también escrito en C que contiene estas funciones mencionadas. Primero el programa se ejecuta pasándole como parámetros las imágenes a combinar, la máscara y el ancho y alto de las mismas. Una vez guardado los parámetros se llama a la función de lectura de los archivos RGB que se encargará de guardar en el buffer los datos correspondientes. Luego se ejecuta la función de enmascarar (_c o _asm) y por último se genera un nuevo archivo de salida (_c o _asm) con la información almacenada en el buffer.

# Resultados

Luego de generar la funcionalidad correspondiente para aplicar la máscara a las imágenes, se obtuvo el siguiente resultado en general para todas las dimensiones

- Salida de enmascarar_c

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/main/Resultado/salida_c.JPG)

- Salida de enmascarar_asm

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/main/Resultado/salida_asm.JPG)

# Comparaciones

Por motivos de tiempo no se llegó a completar la tarea de comparación en gráficos. Lo que si se puedo hacer es generar salidas por consola con los tiempos de las funciones enmascarar_c y enmascarar_asm. Los resultados fueron los siguientes:

- 420x236

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/main/Comparaciones/420x236.JPG)

- 1280x720

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/main/Comparaciones/1280x720.JPG)

- 1821x1024

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/main/Comparaciones/1821x1024.JPG)

# Problemas

- A la hora de implementar la función de enmascarar_asm se obtuvo un primer resultado no del todo satisfactorio. En la imagen de salida se podía oberservar las imágenes bien combinadas por la máscara pero también, por diferentes lugares, se podían observar pequeños pixeles azules que no pertenecían a ninguna de las dos imágenes.

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/main/Problemas/salida_asm.JPG)

Este problema se pudo solucionar gracias a la ayuda de los docentes agregando la instrucción: PXOR XMM0, XMM2.

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/main/Problemas/salida_asm_ok.JPG)

- Por otro lado, fuera de la implementación, surgieron problemas personales que nos impidieron el avance del desarrollo. Estos sin dudas generaron el retraso de la entrega y la falta de funcionalidad requerida como por ejemplo: la generación de los gráficos comparativos y los threads.

# Conclusión 

En este informe describimos el desarrollo de un programa que cumple con la función de enmascarar dos imágenes. El desarrollo no fue libre de problemas y estos generaron la dificultad de la competitud del mismo. Pero sin dudas, el trabajo realizado permitió expandir ampliamente los conocimientos del lenguaje ensamblador y las ventajas de las instrucciones SIMD. Se pudo observar que las instrucciones SIMD de assembler tienen mejores tiempos de respuestas que las de c. Además en los resultados también se identifica como en salida_asm los bordes de la máscara están menos pixelados a comparación de salida_c. A favor de c, queda inconcluso que hubiese pasado si las funciones se implementaban con hilos. 
