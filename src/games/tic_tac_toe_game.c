#include "tic_tac_toe_game.h"


void drawTicTac() {

    drawLine();
    draw_sprite(selectedSprite);


    draw_sprite(fieldSprite);
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
                lineSprite->rotate = 0;
                lineSprite->scaley = ONE;

                if(isLineNum == 1)
                    sprite_set_position(lineSprite,115,7);
                if(isLineNum == 2)
                    sprite_set_position(lineSprite,201,7);
                if(isLineNum == 3)
                    sprite_set_position(lineSprite,286,7);
                break;
            case HORIZONTAL:
                lineSprite->rotate = ONE * 90;
                lineSprite->scaley = ONE;

                if(isLineNum == 1)
                    sprite_set_position(lineSprite,320,37);
                if(isLineNum == 2)
                    sprite_set_position(lineSprite,320,120);
                if(isLineNum == 3)
                    sprite_set_position(lineSprite,320,203);
                break;
            case DIAGONAL:
                lineSprite->scaley = ONE + ONE / 2;
                if(isLineNum == 1) {
                    lineSprite->rotate = ONE * -45;
                    sprite_set_position(lineSprite,85,7);

                }
                if(isLineNum == 2) {
                    lineSprite->rotate = ONE * 45;
                    sprite_set_position(lineSprite,324,5);

                }
                break;
        }
        draw_sprite(lineSprite);
    }

}
/*
 * Drawing score
 */
void drawScoreTicTac() {

    sprite_set_position(crossSprite,14,50);
    crossSprite->scalex = ONE / 2;
    crossSprite->scaley = ONE / 2;
    draw_sprite(crossSprite);
    crossSprite->scalex = ONE;
    crossSprite->scaley = ONE;


    sprite_set_position(circleSprite,14,170);
    circleSprite->scalex = ONE / 2;
    circleSprite->scaley = ONE / 2;
    draw_sprite(circleSprite);
    circleSprite->scalex = ONE;
    circleSprite->scaley = ONE;

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
                sprite_set_position(crossSprite,p.x,p.y);

                draw_sprite(crossSprite);
            } else if(fieldInfo[indexI][indexJ] == CIRCLE) {
                sprite_set_position(circleSprite,p.x,p.y);

                draw_sprite(circleSprite);
            }
        }
    }

}

void updateTicTac() {
    if(!isLockUpdate) {
        pad_update();
        if(pad_check(Pad1Right)) {
            isLockUpdate = 10;
            Cursor.x++;
            if(Cursor.x >=3) {
                Cursor.x = 2;
            }
        }
        if(pad_check(Pad1Left)) {
            isLockUpdate = 10;
            Cursor.x--;
            if(Cursor.x < 0) {
                Cursor.x = 0;
            }
        }

        if(pad_check(Pad1Down)) {
            isLockUpdate = 10;
            Cursor.y++;
            if(Cursor.y >=3) {
                Cursor.y = 2;
            }
        }
        if(pad_check(Pad1Up)) {
            isLockUpdate = 10;
            Cursor.y--;
            if(Cursor.y < 0) {
                Cursor.y = 0;
            }
        }

        if(pad_check(Pad1Cross)) {
            isLockUpdate = 10;

            setField(CROSS);

        }
        if(pad_check(Pad1Circle)) {
            isLockUpdate = 10;
            setField(CIRCLE);

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

    sprite_set_position(selectedSprite,85 + Cursor.x * 85,7 + Cursor.y *85);
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
        waitCpuPlacedFigure = 10;

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

    cd_read_file("FIELD.TIM", &dataTim[0]);
    cd_read_file("SELECTED.TIM", &dataTim[1]);
    cd_read_file("CROSS.TIM", &dataTim[2]);
    cd_read_file("CIRCLE.TIM", &dataTim[3]);
    cd_read_file("LINE.TIM", &dataTim[4]);
    cd_close();

    sprite_create((u_char *) dataTim[0], 80, 0, &fieldSprite);
    sprite_create((u_char *) dataTim[1], 85, 7, &selectedSprite);
    sprite_create((u_char *) dataTim[2], 85, 7, &crossSprite);
    sprite_create((u_char *) dataTim[3], 85, 7, &circleSprite);
    sprite_create((u_char *) dataTim[4], 85, 7, &lineSprite);

    for (indexI = 0; indexI < 5; ++indexI) {
        free3(dataTim[indexI]);
    }

}