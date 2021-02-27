#include "tic_tac_toe_game.h"


void drawTicTac() {

    drawLine();
    draw_sprite(spritesPool[SELECTED_SPRITE]);


    draw_sprite(spritesPool[FIELD_SPRITE]);
    drawTicTacField();
    drawScoreTicTac();

}
/*
 * Line when win game
 */
void drawLine() {
    if(isLineNum) {
        switch (lineType) {

            case VERTICAL:
                spritesPool[LINE_SPRITE]->rotate = 0;
                spritesPool[LINE_SPRITE]->scaley = ONE;

                if(isLineNum == 1)
                    sprite_set_position(spritesPool[LINE_SPRITE],115,7);
                if(isLineNum == 2)
                    sprite_set_position(spritesPool[LINE_SPRITE],201,7);
                if(isLineNum == 3)
                    sprite_set_position(spritesPool[LINE_SPRITE],286,7);
                break;
            case HORIZONTAL:
                spritesPool[LINE_SPRITE]->rotate = ONE * 90;
                spritesPool[LINE_SPRITE]->scaley = ONE;

                if(isLineNum == 1)
                    sprite_set_position(spritesPool[LINE_SPRITE],320,37);
                if(isLineNum == 2)
                    sprite_set_position(spritesPool[LINE_SPRITE],320,120);
                if(isLineNum == 3)
                    sprite_set_position(spritesPool[LINE_SPRITE],320,203);
                break;
            case DIAGONAL:
                spritesPool[LINE_SPRITE]->scaley = ONE + ONE / 2;
                if(isLineNum == 1) {
                    spritesPool[LINE_SPRITE]->rotate = ONE * -45;
                    sprite_set_position(spritesPool[LINE_SPRITE],85,7);

                }
                if(isLineNum == 2) {
                    spritesPool[LINE_SPRITE]->rotate = ONE * 45;
                    sprite_set_position(spritesPool[LINE_SPRITE],324,5);

                }
                break;
        }
        draw_sprite(spritesPool[LINE_SPRITE]);
    }

}
/*
 * Drawing score
 */
void drawScoreTicTac() {

    sprite_set_position(spritesPool[CROSS_SPRITE],14,50);
    spritesPool[CROSS_SPRITE]->scalex = ONE / 2;
    spritesPool[CROSS_SPRITE]->scaley = ONE / 2;
    draw_sprite(spritesPool[CROSS_SPRITE]);
    spritesPool[CROSS_SPRITE]->scalex = ONE;
    spritesPool[CROSS_SPRITE]->scaley = ONE;


    sprite_set_position(spritesPool[CIRCLE_SPRITE],14,170);
    spritesPool[CIRCLE_SPRITE]->scalex = ONE / 2;
    spritesPool[CIRCLE_SPRITE]->scaley = ONE / 2;
    draw_sprite(spritesPool[CIRCLE_SPRITE]);
    spritesPool[CIRCLE_SPRITE]->scalex = ONE;
    spritesPool[CIRCLE_SPRITE]->scaley = ONE;

    FntPrint(fontCrossId,"%d",scoreCross);
    FntFlush(fontCrossId);



    FntPrint(fontCircleId,"%d",scoreCircle);
    FntFlush(fontCircleId);

}

/*
 * Drawing tictac field
 */
void drawTicTacField() {
    for (indexI = 0; indexI < 3; ++indexI) {
        for (indexJ = 0; indexJ < 3; ++indexJ) {
            struct Point p = pos[indexI][indexJ];
            if(fieldInfo[indexI][indexJ] == CROSS) {
                sprite_set_position(spritesPool[CROSS_SPRITE],p.x,p.y);

                draw_sprite(spritesPool[CROSS_SPRITE]);
            } else if(fieldInfo[indexI][indexJ] == CIRCLE) {
                sprite_set_position(spritesPool[CIRCLE_SPRITE],p.x,p.y);

                draw_sprite(spritesPool[CIRCLE_SPRITE]);
            }
        }
    }

}

void updateTicTac() {
    if(!isLockUpdate) {
        pad_update();
        if(pad_check(playerMove > 0 ? Pad2Right : Pad1Right)) {
            isLockUpdate = 10;
            Cursor.x++;
            if(Cursor.x >=3) {
                Cursor.x = 2;
            }
        }
        if(pad_check(playerMove > 0 ? Pad2Left : Pad1Left)) {
            isLockUpdate = 10;
            Cursor.x--;
            if(Cursor.x < 0) {
                Cursor.x = 0;
            }
        }

        if(pad_check(playerMove > 0 ? Pad2Down : Pad1Down)) {
            isLockUpdate = 10;
            Cursor.y++;
            if(Cursor.y >=3) {
                Cursor.y = 2;
            }
        }
        if(pad_check(playerMove > 0 ? Pad2Up : Pad1Up)) {
            isLockUpdate = 10;
            Cursor.y--;
            if(Cursor.y < 0) {
                Cursor.y = 0;
            }
        }

        if(gameType == 1 || currentFigureTicTac == -1) {
            if(pad_check(Pad1Cross)) {
                isLockUpdate = 10;
                setField(CROSS);
            }
            if(pad_check(Pad1Circle)) {
                isLockUpdate = 10;
                setField(CIRCLE);
            }
        } else {
            if(pad_check(playerMove > 0 ? Pad2Cross : Pad1Cross)) {
                isLockUpdate = 10;
                setField(CROSS);
            }
            if(pad_check(playerMove > 0 ? Pad2Circle : Pad1Circle)) {
                isLockUpdate = 10;
                setField(CIRCLE);
            }
        }

    }
    if(waitForClearField > 0) {
        waitForClearField--;
        if(waitForClearField == 0) {
            clearField();
        }
    }
    if(waitCpuPlacedFigure > 0) {
        waitCpuPlacedFigure--;
        if(waitCpuPlacedFigure == 0) {
            addToRandomEmptyPlace();
            checkWinCombination(currentFigureTicTac == CIRCLE ? CROSS : CIRCLE);
        }

    }


    if(isLockUpdate > 0) {
        isLockUpdate--;
    }

    sprite_set_position(spritesPool[SELECTED_SPRITE],85 + Cursor.x * 85,7 + Cursor.y *85);
}

void clearField() {
    isLineNum = 0;
    for (indexI = 0; indexI < SIZE_FIELD; ++indexI) {
        for (indexJ = 0; indexJ < SIZE_FIELD; ++indexJ) {
            fieldInfo[indexI][indexJ]=0;
        }
    }
}
void winGame(int typeFigure) {
    if(typeFigure == CROSS) {
        scoreCross++;
    }
    if(typeFigure == CIRCLE) {
        scoreCircle++;
    }

    // delay for field clear
    waitForClearField = 60;
    isLockUpdate = 60;
    currentFigureTicTac = -1;
}
/*
 * Checked when win circles or crosses
 */
void checkWinCombination(int figure) {
    // check lines vertical
    for (indexI = 0; indexI < SIZE_FIELD; ++indexI) {
        int checkedFigure = fieldInfo[indexI][0];
        if(checkedFigure > 0 && checkedFigure == figure) {
            int isWin = 1;
            for (indexJ = 1; indexJ < SIZE_FIELD; ++indexJ) {
                if(checkedFigure != fieldInfo[indexI][indexJ]) {
                    isWin = 0;
                    break;
                }
            }
            if(isWin) {
                lineType = VERTICAL;
                isLineNum = indexI + 1;
                winGame(checkedFigure);
            }
        }
    }
    // check lines horizontal
    for (indexI = 0; indexI < SIZE_FIELD; ++indexI) {
        int checkedFigure = fieldInfo[0][indexI];
        if(checkedFigure > 0 && checkedFigure == figure) {
            int isWin = 1;
            for (indexJ = 1; indexJ < SIZE_FIELD; ++indexJ) {
                if(checkedFigure != fieldInfo[indexJ][indexI]) {
                    isWin = 0;
                    break;
                }
            }
            if(isWin) {
                lineType = HORIZONTAL;
                isLineNum = indexI + 1;
                winGame(checkedFigure);
            }
        }
    }
    // check lines diagonal 1

    {
        int checkedFigure = fieldInfo[0][0];
        if(checkedFigure > 0 && checkedFigure == figure) {
            int isWin = 1;
            for (indexJ = 1; indexJ < SIZE_FIELD; ++indexJ) {
                if(checkedFigure != fieldInfo[indexJ][indexJ]) {
                    isWin = 0;
                    break;
                }
            }
            if(isWin) {
                lineType = DIAGONAL;
                isLineNum = 1;
                winGame(checkedFigure);
            }
        }
    }
    // check lines diagonal 2
    {
        int maxRight = SIZE_FIELD-1;
        int checkedFigure = fieldInfo[maxRight][0];
        if(checkedFigure > 0 && checkedFigure == figure) {
            int isWin = 1;
            for (indexJ = 1; indexJ < SIZE_FIELD; ++indexJ) {
                maxRight--;

                if(checkedFigure != fieldInfo[maxRight][indexJ]) {
                    isWin = 0;
                    break;
                }
            }
            if(isWin) {
                lineType = DIAGONAL;
                isLineNum = 2;
                winGame(checkedFigure);
            }
        }
    }
}

/*
 * Place figure on field
 */
void setField(int typeFigure) {
    if( currentFigureTicTac == -1) {
        currentFigureTicTac = typeFigure;
    }
    if(currentFigureTicTac == typeFigure && fieldInfo[Cursor.x][Cursor.y] == 0) {
        fieldInfo[Cursor.x][Cursor.y] = typeFigure;
        checkWinCombination(currentFigureTicTac);

        isLockUpdate = 10;
        if(gameType == 1) {
            waitCpuPlacedFigure = 10;
        } else {
            if(currentFigureTicTac == CIRCLE) {
                currentFigureTicTac = CROSS;
            } else if(currentFigureTicTac == CROSS) {
                currentFigureTicTac = CIRCLE;
            }

            if(playerMove == 0) playerMove = 1;
            else if(playerMove == 1) playerMove = 0;
            printf("player move: %d\n",playerMove);
        }

    }

}

void addToRandomEmptyPlace() {
    if(countEmptySlot() > 0) {

        int randx = 0;
        int randy = 0;
        srand(GsGetVcount());

        do {
            randx = rand() % 3;
            randy = rand() % 3;
        } while (fieldInfo[randx][randy] > 0);


        fieldInfo[randx][randy] = currentFigureTicTac == CROSS ? CIRCLE : CROSS;
    } else {
        clearField();
    }


}
/*
 * Count empty slots
 */
int countEmptySlot() {
    int count = 0;
    for (indexI = 0; indexI < 3; ++indexI) {
        for (indexJ = 0; indexJ < 3; ++indexJ) {
            if(fieldInfo[indexI][indexJ] == 0) count++;
        }
    }

    return count;
}

void initTicTac() {


    Color *bg;
    color_create(0, 140, 255, &bg);
    set_background_color(bg);

    playerMove = 0;

    currentFigureTicTac = -1;

    scoreCircle = 0;
    scoreCross = 0;
    FntLoad(960, 256);
    fontCrossId = FntOpen(25, 80, 30, 30, 0, 512);
    fontCircleId = FntOpen(25, 200, 30, 30, 0, 512);

    for (indexI = 0; indexI < 3; ++indexI) {
        for (indexJ = 0; indexJ < 3; ++indexJ) {
            pos[indexI][indexJ].x = 90 + indexI * 85;
            pos[indexI][indexJ].y = 7 + indexJ *85;
        }
    }

    cd_open();

    cd_read_file("FIELD.TIM", &dataPool[FIELD_SPRITE]);
    cd_read_file("SELECTED.TIM", &dataPool[SELECTED_SPRITE]);
    cd_read_file("CROSS.TIM", &dataPool[CROSS_SPRITE]);
    cd_read_file("CIRCLE.TIM", &dataPool[CIRCLE_SPRITE]);
    cd_read_file("LINE.TIM", &dataPool[LINE_SPRITE]);
    cd_close();

    sprite_create((u_char *) dataPool[FIELD_SPRITE], 80, 0, &spritesPool[FIELD_SPRITE]);
    sprite_create((u_char *) dataPool[SELECTED_SPRITE], 85, 7, &spritesPool[SELECTED_SPRITE]);
    sprite_create((u_char *) dataPool[CROSS_SPRITE], 85, 7, &spritesPool[CROSS_SPRITE]);
    sprite_create((u_char *) dataPool[CIRCLE_SPRITE], 85, 7, &spritesPool[CIRCLE_SPRITE]);
    sprite_create((u_char *) dataPool[LINE_SPRITE], 85, 7, &spritesPool[LINE_SPRITE]);

    for (indexI = 0; indexI < 5; ++indexI) {
        free3(dataPool[indexI]);
    }

}