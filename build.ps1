ccpsx -Xo0x80010000 -Wall -O2 ..\src\main.c ..\src\controller.c ..\src\core.c ..\src\games\tic_tac_toe_game.c ..\src\engine.c ..\src\screen_selector.c -l LIBDS.LIB -o main.cpe
cpe2x /ce main.cpe
.\mkpsxiso\mkpsxiso.exe -o .\cdimage\game.iso -y ..\cuesheet.xml