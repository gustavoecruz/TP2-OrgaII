# Enmascarador

Con el objetivo de comparar la performance de las instrucciones SIMD con las instrucciones aritméticas y lógicas de la ALU, se desarrolló una aplicación de línea de comandos que combina dos imágenes usando una máscara de selección. Se implementaron dos versiones de esta operación, una en lenguaje C y otra utilizando instrucciones SIMD en el lenguaje ensamblador.

# Herramientas

Para desarrollar la aplicación se utilizaron las siguentes herramientas:
- GraphicsMagick: para la conversión de imáganes a extensión RGB
- XnViewMP: para redimensionar las imágenes
- NASM para assembler
- GCC para C

# Desarrollo

El desarrollo de la aplicación cuenta con 3 partes importantes que se pueden diferenciar facilmente: las funciones de lectura y escritura de los archivos RGB, la función de enmascarar_c y la función de enmascarar_asm.

Por otro lado, se tiene un programa general también escrito en C que contiene estas funciones mencionadas. Primero el programa se ejecuta pasándole como parámetros las imágenes a combinar, la máscara y el ancho y alto de las mismas. Una vez guardado los parámetros se llama a la función de lectura de los archivos RGB que se encargará de guardar en el buffer los datos correspondientes. Luego se ejecuta la función de enmascarar (_c o _asm) y por último se genera un nuevo archivo de salida (_c o _asm) con la información almacenada en el buffer.

# Comparaciones


# Problemas

- A la hora de implementar la función de enmascarar_asm se obtuvo un primero resultado no del todo satisfactorio. En la imagen de salida se podía oberservar las imágenes bien combinadas por la máscara pero también, por diferentes lugares, se podían observar pequeños pixeles azules que no pertenecían a ninguna de las dos imágenes.

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/tree/main/Imágenes de problema/salida_asm.JPG)

Este problema se pudo solucionar gracias a la ayuda de los docentes agregando la instrucción: PXOR XMM0, XMM2.

![](https://raw.githubusercontent.com/gustavoecruz/TP2-OrgaII/blob/main/Imágenes de problema/salida_asm.JPG)
