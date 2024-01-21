#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

//defining pins for display
#define TFT_SCK    18
#define TFT_MOSI   23
#define TFT_MISO   19
#define TFT_CS     5
#define TFT_DC     21
#define TFT_RST    22
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST, TFT_MISO);




//block movement max borders
#define TOP_BORDER 20
#define BOTTOM_BORDER 310
#define RIGHT_BORDER 190
#define LEFT_BORDER -40


#define NASOBENI 10



//defining pins for buttons
#define UP 16
#define DOWN 4
#define LEFT 17
#define RIGHT 15


//colours
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0
#define WHITE    0xFFFF
#define BROWN    0xCC09


//initial spawn positions
#define INITIALSPAWNPOSITIONX 100
#define INITIALSPAWNPOSITIONY 50

int frameSpeed = 600;
unsigned long lastFrame = 0;
int score;
bool stop;
int colors[6] = {BLUE, RED, GREEN, CYAN, MAGENTA, YELLOW};
int blocks[2][5];
int board[25][25];

//for collision check
int blockPosition[4][2];

//making individual tetrominos
int pieces[7][4][5][5] =
        {
//square
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        }
                },

//I
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 1, 1},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
//L
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
//L mirrored
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 1, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
//Z
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        },

                        {
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
//Z mirrored
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 0, 1, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                },
//T
                {
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                        }
                }
        };
//saving blocks
void saveBlockSettings(int placeToSave, int x, int y, int kind, int rotation, int color) {
    int saved[5] = {x, y, kind, rotation, color};
    for (byte i = 0; i < 5; i++) {
        blocks[placeToSave][i] = saved[i];

    }


}

//collision test
void collisionTest(int x, int y, int arrayPosition) {
    blockPosition[arrayPosition][0] = x;
    blockPosition[arrayPosition][1] = y;
}

//drawing up the tetromino
void drawBlock(int x, int y, int kind, int rotate, int color, bool collision) {
    int pocet = 0;
    for (int i = 4; i > -1; i--) {
        for (int j = 0; j < 5; j++) {
            if (pieces[kind][rotate][i][j] == 1) {
                tft.fillRect(x + (NASOBENI * j), y + (NASOBENI * i), pieces[kind][rotate][i][j] * NASOBENI,
                             pieces[kind][rotate][i][j] * NASOBENI, color);
                if (collision) {
                    collisionTest(x + (NASOBENI * j), y + (NASOBENI * i), pocet);
                    pocet++;
                }

            }
        }
    }
}

//collision function
int collision() {

    for (byte i = 0; i < 4; i++) {
        int col = blockPosition[i][0] / NASOBENI;
        int row = (blockPosition[i][1] / NASOBENI) - 5;
        if (board[row][col] != 0) return true;


    }
    return false;
}

//death function
bool death() {
    for (byte i = 0; i < 25; i++) {
        if (board[0][i] != 0) return true;
    }

    return false;
}

//
void addToBoard() {

    for (byte i = 0; i < 4; i++) {
        int col = blockPosition[i][0] / NASOBENI;
        int row = (blockPosition[i][1] / NASOBENI) - 6;
        board[row][col] = blocks[0][4];
    }
}

//
void changeBoard(int row) {
    for (byte i = row; i > 0; i--) {
        for (byte j = 0; j < 25; j++) {
            board[i][j] = board[i - 1][j];
        }
    }
}

//function for checking score
int checkScore() {
    int point = 0;
    for (byte i = 0; i < 25; i++) {
        for (byte j = 0; j < 25; j++) {
            if (board[i][j] != 0) point++;
            if (point == 24 && i != 24) {
                return i;

            }
        }
        point = 0;
    }
    Serial.println(point);
    return 0;

}

int randomNumber(int range) {
    return random(range);
}

//creates a bottom line to prevent blocks from spawning there
void fillBoard() {
    for (byte i = 0; i < 25; i++) {
        for (byte j = 0; j < 25; j++) {
            if (i == 24) board[i][j] = BROWN;
            else board[i][j] = 0;
        }
    }
}

//drawing up the board
void drawBoard() {
    for (byte i = 0; i < 25; i++) {
        for (byte j = 0; j < 25; j++)
            tft.fillRect(0 + (NASOBENI * j), 60 + (NASOBENI * i), NASOBENI, NASOBENI, board[i][j]);

    }
}

//creating the tetromino
void createBlock() {
    (blocks[1][1] == 0) ? saveBlockSettings(0, INITIALSPAWNPOSITIONX, INITIALSPAWNPOSITIONY, randomNumber(7), 0,
                                            colors[randomNumber(6)]) :
    saveBlockSettings(0, INITIALSPAWNPOSITIONX, INITIALSPAWNPOSITIONY, blocks[1][2], blocks[1][3], blocks[1][4]);

    saveBlockSettings(1, 0, 10, randomNumber(7), 0, colors[randomNumber(6)]);
    drawBlock(blocks[0][0], blocks[0][1], blocks[0][2], blocks[0][3], blocks[0][4], true);
    tft.fillRect(0, 20, 50, 40, BROWN);
    drawBlock(blocks[1][0], blocks[1][1], blocks[1][2], blocks[1][3], blocks[1][4], false);
}

//movement of the tetromino
void moveBlock(int x, int y, int kind, int rotate, int color, int xChange, int yChange) {
    drawBlock(x, y, kind, rotate, BLACK, false);
    int posY = y;
    int posX = x;
    posX += NASOBENI * xChange;
    posY += NASOBENI * yChange;
    drawBlock(posX, posY, kind, rotate, color, true);
    saveBlockSettings(0, posX, posY, kind, rotate, color);

}

//rotation of the tetromino
void rotateBlock(int x, int y, int kind, int rotate, int color) {
    drawBlock(x, y, kind, rotate, BLACK, false);
    int rotationState = rotate;
    rotationState++;
    if (rotationState > 3) rotationState = 0;
    drawBlock(x, y, kind, rotationState, color, true);
    saveBlockSettings(0, x, y, kind, rotationState, color);

}

//topbar menu
void menu() {
    tft.fillRect(0, 0, 250, 60, BROWN);
    tft.fillRect(185, 20, 50, 2, WHITE);
    tft.setCursor(0, 0);
    tft.print("next");
    tft.setCursor(80, 0);
    tft.print("TETRIS");
    tft.setCursor(180, 0);
    tft.print("score");

}

//rewriting the score
void writeScore(int score) {
    tft.fillRect(200, 30, 30, 20, BROWN);
    tft.setCursor(200, 30);
    tft.print(score);
}

//the menu after losing
void defeatMenu() {
    tft.fillScreen(BLACK);
    tft.setTextColor(WHITE, BLACK);
    tft.setCursor(60, 60);
    tft.println("You lost!");
    tft.setCursor(40, 80);
    tft.println("Your score was:");
    tft.setCursor(120, 110);
    tft.println(score);
    tft.setCursor(20, 140);
    tft.print("Press UP button to retry");


}

//function that starts the game
void play() {
    stop = false;
    score = 0;
    tft.setTextColor(WHITE, BROWN);
    tft.setTextSize(2);
    menu();
    fillBoard();
    writeScore(score);
    drawBoard();
    createBlock();

}


//move
void IRAM_ATTR

up() {
    //Serial.println("UP");
    if (stop == false) rotateBlock(blocks[0][0], blocks[0][1], blocks[0][2], blocks[0][3], blocks[0][4]);
    else play();
}

void IRAM_ATTRFF

left() {
    //Serial.println("LEFT");
    if (blocks[0][0] > LEFT_BORDER && stop == false)
        moveBlock(blocks[0][0], blocks[0][1], blocks[0][2], blocks[0][3], blocks[0][4], -1, 0);

}

void IRAM_ATTR

right() {
    //Serial.println("RIGHT");
    if (blocks[0][0] < RIGHT_BORDER && stop == false)
        moveBlock(blocks[0][0], blocks[0][1], blocks[0][2], blocks[0][3], blocks[0][4], 1, 0);


}

void down() {
    if (digitalRead(DOWN)) {

        Serial.println("DOWN");
        frameSpeed = 600;
    } else {
        Serial.println("DOWN NOT");

        frameSpeed = 100;
    }
}

//pin and display setup
void setup() {
    Serial.begin(115200);
    pinMode(UP, INPUT_PULLUP);
    pinMode(LEFT, INPUT_PULLUP);
    pinMode(RIGHT, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    attachInterrupt(UP, up, FALLING);
    attachInterrupt(LEFT, left, FALLING);
    attachInterrupt(RIGHT, right, FALLING);

    tft.begin();
    play();


}

//loops all the functions in order for the game to run
void loop() {
    if (stop == false) {
        if (millis() > lastFrame + frameSpeed) {
            if (!collision()) {
                down();
                moveBlock(blocks[0][0], blocks[0][1], blocks[0][2], blocks[0][3], blocks[0][4], 0, 1);
                lastFrame = millis();
            }

            if (collision()) {
                frameSpeed = 600;
                addToBoard();
                if (checkScore() > 0) {
                    score += 1;
                    writeScore(score);
                    changeBoard(checkScore());
                }
                drawBoard();
                createBlock();

            }
        }

    }
    if (death()) {

        if (stop == false) defeatMenu();

        stop = true;
    }

}


