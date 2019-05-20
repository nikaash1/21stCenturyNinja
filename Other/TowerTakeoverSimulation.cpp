#define ORANGE 1
#define PURPLE 2
#define GREEN 3

int score = 0;

int torange = 22;
int tpurple = 22;
int tgreen = 22;

int highstack = 7;

int sorange = 0;
int spurple = 0;
int sgreen = 0;

void cubeUsed(int color){

    if (color == 1){
        torange += -1;
    }
    if (color == 2){
        tpurple += -1;
    }
    if (color == 3){
        tgreen += -1;
    }

}

void zonePointsGained(int color){

    if (color == 1){
        sorange++;
    }
    if (color == 2){
        spurple++;
    }
    if (color == 3){
        sgreen++;
    }

}

void cubeZoned(int color){

    cubeUsed(color);
    zonePointsGained(color);

}

void cubeStacked(int color){

    highstack += -1;
    cubeUsed(color);
    

}







score = sorange+spurple+sgreen