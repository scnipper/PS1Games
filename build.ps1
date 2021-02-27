ccpsx -Xo0x80010000 -Wall -O2 ..\src\main.c ..\src\start_screen\screen_selector.c ..\src\start_screen\screen_selector.h ..\src\controller.c ..\src\core.c ..\src\games\tic_tac_toe_game.c ..\src\games\tic_tac_screen.c ..\src\engine.c -l LIBDS.LIB -o main.cpe
cpe2x C:\psyq\projects\simple_ps1_games\build\main.cpe
.\mkpsxiso\mkpsxiso.exe -o .\cdimage\game.iso -y ..\cuesheet.xml