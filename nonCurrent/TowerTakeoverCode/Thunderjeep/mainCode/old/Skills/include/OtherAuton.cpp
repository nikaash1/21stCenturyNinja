/*//cube 1
        intakeMove(FORWARD, FAST, 350);
        intakeBrake();
        intakeSpin(FORWARD, 70);
        //cube 2
        //goOldPID(4.3, 1.5, 0.15, 40, 0.25);
        //goEncoder(FORWARD, 30, 4.3);
        goo(FORWARD, 20, 10.3, 3.5, 0);
        upMove(FORWARD, FAST, 400);
        //goOldPID(6, 1.3, 0.2, 40, 0.25);
        //wait(200);
        upMove(BACKWARD, FAST, 200);
        intakeMove(BACKWARD, FAST, 90);
        routine(FAST);
        intakeSpin(FORWARD, 50);
        //wait(50);
        //intakeBrake();
        //cube 3-6
        upMove2(FORWARD, FAST, 710);
        goOldPID(21.25, 1, 0.105, 80, 0.05);
        upMove(BACKWARD, FAST, 100);
        intakeMove(BACKWARD, FAST, 470);
        upMove(BACKWARD, 90, 760);
        goSides(FORWARD, FORWARD, 30, 30, 1.5, 1.5);
        intakeMove(FORWARD, FAST, 470);
        intakeSpin(FORWARD, 70);
        upMove(FORWARD, MEDIUM, 200);
        goOldPID(-27, -1, 0.12, 80, 0.05);
        turnEncoder(RIGHT, 32, 100);
        goOldPID(30.25, 1.1, 0.15, 80, 0.05);
        upMove(BACKWARD, 70, 130);
        goSides(FORWARD, FORWARD, 30, 30, 3, 3);
        upMove(BACKWARD, 60, 100);
        intakeMove(BACKWARD, FAST, 530);
        upMove(FORWARD, 30, 100);
        goOldPID(-4, -1.3, 0.15, 40, 0.25);
        stopEverything();


//cube 1
        intakeMove(FORWARD, FAST, 350);
        intakeBrake();
        intakeSpin(FORWARD, 70);
        //cube 2
        //goOldPID(4.3, 1.5, 0.15, 40, 0.25);
        //goEncoder(FORWARD, 30, 4.3);
        goo(FORWARD, 20, 10.3, 3.5, 0);
        upMove(FORWARD, FAST, 400);
        //goOldPID(6, 1.3, 0.2, 40, 0.25);
        //wait(200);
        upMove(BACKWARD, FAST, 200);
        intakeMove(BACKWARD, FAST, 90);
        routine(FAST);
        intakeSpin(FORWARD, 50);
        //wait(50);
        //intakeBrake();
        //cube 3-6
        upMove2(FORWARD, FAST, 710);
        goOldPID(21.25, 1, 0.105, 80, 0.05);
        upMove(BACKWARD, FAST, 100);
        intakeMove(BACKWARD, FAST, 470);
        upMove(BACKWARD, 90, 760);
        goSides(FORWARD, FORWARD, 30, 30, 1.5, 1.5);
        intakeMove(FORWARD, FAST, 470);
        intakeSpin(FORWARD, 70);
        //wait(50);
        //intakeBrake();
        upMove(FORWARD, 70, 300);
        //score
        wait(200);
        turnEncoder(RIGHT, 32, 142);
        //goOldPID(52, 1.1, 0.1, 80, 0.05);
        goo(FORWARD, 56, 46, 35, 0);
        goH(RIGHTH, 100, 4);
        while(LF.isSpinning()){
          wait(1);
        }
        //goSides(FORWARD, BACKWARD, 60, 0, 10, 0);
        //turnEncoder(LEFT, 30, 20);
        //goSides(BACKWARD, BACKWARD, 70, 50, 10, 4);
        wait(300);
        //goSides(FORWARD, FORWARD, 30, 6, 16, 4);
        upMove(BACKWARD, 70, 130);
        intakeMove(BACKWARD, FAST, 530);
        upMove(FORWARD, 30, 100);
        goOldPID(-4, -1.3, 0.15, 40, 0.25);
        stopEverything();

        intakeMove(FORWARD, FAST, 420);
        intakeBrake();
        intakeSpin(FORWARD, 20);
        goOldPID(3.5, 1.5, 0.2, 40, 0);
        upMove(FORWARD, FAST, 400);
        goOldPID(5, 1.5, 0.2, 40, 0);
        wait(200);
        upMove(BACKWARD, FAST, 200);
        routine(FAST);
        intakeSpin(FORWARD, 20);
        wait(50);
        intakeBrake();
        goOldPID(5, 1.5, 0.2, 40, 0);
        routine(FAST);
        intakeSpin(FORWARD, 20);
        wait(50);
        intakeBrake();
        goOldPID(5, 1.5, 0.2, 40, 0);
        routine(FAST);
        intakeSpin(FORWARD, 20);
        wait(50);
        intakeBrake();
        goOldPID(5, 1.5, 0.2, 40, 0);
        routine(FAST);
        intakeSpin(FORWARD, 20);
        wait(50);
        intakeBrake();


















        skills

         //cube 1
        intakeMove(FORWARD, FAST, 350);
        intakeBrake();
        intakeSpin(FORWARD, 70);
        //cube 2
        //goOldPID(4.3, 1.5, 0.15, 40, 0.25);
        //goEncoder(FORWARD, 30, 4.3);
        goo(FORWARD, 20, 10.3, 3.5, 0);
        upMove(FORWARD, FAST, 400);
        //goOldPID(6, 1.3, 0.2, 40, 0.25);
        //wait(200);
        upMove(BACKWARD, FAST, 200);
        intakeMove(BACKWARD, FAST, 90);
        routine(FAST);
        intakeSpin(FORWARD, 50);
        //wait(50);
        //intakeBrake();
        //cube 3-6
        upMove2(FORWARD, FAST, 710);
        goOldPID(21.25, 1, 0.105, 80, 0.05);
        upMove(BACKWARD, FAST, 100);
        intakeMove(BACKWARD, FAST, 470);
        upMove(BACKWARD, 90, 760);
        goSides(FORWARD, FORWARD, 30, 30, 1.5, 1.5);
        intakeMove(FORWARD, FAST, 470);
        intakeSpin(FORWARD, 70);
        //wait(50);
        //intakeBrake();
        upMove(FORWARD, 70, 300);
        //score
        wait(200);
        turnEncoder(LEFT, 32, 142);
        //goOldPID(52, 1.1, 0.1, 80, 0.05);
        goo(FORWARD, 50, 46, 35, 0);
        //goH(LEFTH, 100, 3);
        while(LF.isSpinning()){
          wait(1);
        }
        //goSides(FORWARD, BACKWARD, 60, 0, 10, 0);
        //turnEncoder(LEFT, 30, 20);
        //goSides(BACKWARD, BACKWARD, 70, 50, 10, 4);
        wait(300);
        //goSides(FORWARD, FORWARD, 30, 6, 16, 4);
        upMove(BACKWARD, 70, 130);
        intakeMove(BACKWARD, FAST, 530);
        upMove(FORWARD, 30, 100);
        goOldPID(-10, -1.3, 0.15, 40, 0.25);
        upMove(BACKWARD, 90, 400);
        
      
        //reset against wall
        //goOldPID(-5, -1.2,  0.11, 40, 0.25);
        goSides(FORWARD, BACKWARD, 20, 70, 5, 27);
        govolt(BACKWARD, MEDIUM, 1000);
        //tower1
        goH(RIGHTH, 100, 5);
        upMove(BACKWARD, 75, 70);
        goOldPID(45, 1.2,  0.15, 40, 0.25);
        intakeMove(FORWARD, FAST, 450);
        intakeSpin(FORWARD, 50);
        goOldPID(-5, -1.2,  0.11, 40, 0.25);
        upMove(FORWARD, 70, 850);
        goOldPID(8, 1.2,  0.11, 40, 0.05);
        upMove(BACKWARD, 60, 50);
        intakeMove(BACKWARD, FAST, 100);
        upMove(FORWARD, 60, 50);
        goOldPID(-8, -1.2,  0.11, 40, 0.25);
        upMove(BACKWARD, 70, 850);
        intakeMove(BACKWARD, FAST, 250);
        //tower 2
        goH(RIGHTH, 100, 77);
        goOldPID(6, 1.2,  0.11, 40, 0.25);
        intakeMove(FORWARD, FAST, 450);
        intakeSpin(FORWARD, 50);
        goOldPID(-5, -1.3,  0.11, 40, 0.25);
        upMove(FORWARD, 70, 1300);
        goOldPID(8, 1.2,  0.11, 40, 0.05);
        upMove(BACKWARD, 60, 50);
        intakeMove(BACKWARD, FAST, 100);
        upMove(FORWARD, 60, 50);
        goOldPID(-5, -1.2,  0.11, 40, 0.25);
        upMove(BACKWARD, 70, 1190);
        intakeMove(BACKWARD, FAST, 250);
        //tower 3
        goH(RIGHTH, 100, 78);
        goOldPID(5, 1.1,  0.11, 40, 0.25);
        intakeMove(FORWARD, FAST, 450);
        intakeSpin(FORWARD, 50);
        goOldPID(-5, -1.5,  0.2, 40, 0.25);
        upMove(FORWARD, 70, 850);
        goOldPID(5, 1.2,  0.11, 40, 0.05);
        upMove(BACKWARD, 60, 50);
        intakeMove(BACKWARD, FAST, 100);
        upMove(FORWARD, 60, 50);
        goOldPID(-5, -1.2,  0.11, 40, 0.25);
        upMove(BACKWARD, 70, 850);
        goH(RIGHTH, 100, 76);
        stopEverything();



















        blue?? 7
        //cube 1
        intakeMove(FORWARD, FAST, 350);
        intakeBrake();
        intakeSpin(FORWARD, 70);
        //cube 2
        goo(FORWARD, 20, 12.8, 3.5, 0);
        upMove(FORWARD, FAST, 400);
        upMove(BACKWARD, FAST, 200);
        intakeMove(BACKWARD, FAST, 90);
        routine(FAST);
        intakeSpin(FORWARD, 50);
        //cube 3-6
        upMove2(FORWARD, FAST, 710);
        goOldPID(21.25, 1, 0.105, 80, 0.05);
        upMove(BACKWARD, FAST, 100);
        intakeMove(BACKWARD, FAST, 470);
        upMove(BACKWARD, 90, 760);
        goSides(FORWARD, FORWARD, 30, 30, 1.5, 1.5);
        intakeMove(FORWARD, FAST, 470);
        intakeSpin(FORWARD, 70);
        upMove(FORWARD, MEDIUM, 400);
        wait(200);
        //cube 7
        turnEncoder(RIGHT, 32, 132);
        goo(FORWARD, 50, 46, 35, 0);
        while(LF.isSpinning()){
          wait(1);
        }
        wait(600);
        //place cubes
        upMove(BACKWARD, 70, 130);
        intakeMove(BACKWARD, FAST, 530);
        upMove(FORWARD, 30, 100);
        goOldPID(-4, -1.3, 0.15, 40, 0.25);
        stopEverything();









































        //blue (red style)
        //cube 1
        intakeMove(FORWARD, FAST, 350);
        intakeBrake();
        intakeSpin(FORWARD, 70);
        //cube 2
        goo(FORWARD, 20, 13.3, 3.5, 0);
        upMove(FORWARD, FAST, 400);
        upMove(BACKWARD, FAST, 200);
        intakeMove(BACKWARD, FAST, 90);
        routine(FAST);
        intakeSpin(FORWARD, 50);
        //cube 3-6
        upMove2(FORWARD, FAST, 710);
        goOldPID(21.25, 1, 0.105, 80, 0.05);
        upMove(BACKWARD, FAST, 100);
        intakeMove(BACKWARD, FAST, 470);
        upMove(BACKWARD, 90, 760);
        goSides(FORWARD, FORWARD, 30, 30, 1.5, 1.5);
        intakeMove(FORWARD, FAST, 470);
        intakeSpin(FORWARD, 70);
        upMove(FORWARD, MEDIUM, 400);
        wait(200);
        //cube 7
        turnEncoder(RIGHT, 32, 132);
        goo(FORWARD, 50, 46, 35, 0);
        while(LF.isSpinning()){
          wait(1);
        }
        wait(600);
        //place cubes
        upMove(BACKWARD, 70, 130);
        intakeMove(BACKWARD, FAST, 530);
        upMove(FORWARD, 30, 100);
        goOldPID(-4, -1.3, 0.15, 40, 0.25);
        stopEverything();








*/