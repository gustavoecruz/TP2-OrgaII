nasm -f win32 enmascarador.asm
gcc enmascarador.c enmascarador.obj -o enmascarador.exe
enmascarador.exe img1.rgb img2.rgb mask.rgb 1280 720
gm convert -size 1280x720 -depth 8 salida_c.rgb win:
gm convert -size 1280x720 -depth 8 salida_asm.rgb win:
