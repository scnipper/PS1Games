ccpsx -Xo0x80010000 -Wall -O2 main.c -l LIBDS.LIB -o main.cpe
cpe2x /ce main.cpe
.\mkpsxiso\mkpsxiso.exe -o cdimage\game.iso -y .\cuesheet.xml


