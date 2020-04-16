//tank drive
    /*if (brakeVar == 0){
       
      //setDriveBack((getAnalog(RIGHT_AXIS_Y))-((getAnalog(RIGHT_AXIS_X))*-1));
      setDriveLF((getAnalog(LEFT_AXIS_Y))-(getAnalog(LEFT_AXIS_X))*-0.5);
      setDriveLB((getAnalog(LEFT_AXIS_Y))-(getAnalog(LEFT_AXIS_X))*0.5);
      setDriveRF((getAnalog(RIGHT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X))*0.5);
      setDriveRB((getAnalog(RIGHT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X))*-0.5);
      

      //H-Drive Tank (uncomment)
      //setDriveH(hSpeed*((0.5*(getAnalog(LEFT_AXIS_X)))+(0.5*(getAnalog(RIGHT_AXIS_X)))));

      //Mechanum Tank (uncomment)
      //strafeMech(hSpeed*((0.5*(getAnalog(LEFT_AXIS_X)))+(0.5*(getAnalog(RIGHT_AXIS_X)))));
    }*/
    //arcade drive
    //if (brakeVar == 1){
      /*setDriveLeft(straightSpeed*(getAnalog(LEFT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X)*-1*turnSpeed));
      setDriveRight(straightSpeed*(getAnalog(LEFT_AXIS_Y))-(getAnalog(RIGHT_AXIS_X)*turnSpeed));*/
      

      //H-Drive Arcade (uncomment)
      //setDriveH(hSpeed*(getAnalog(LEFT_AXIS_X)));

      //Mechanum Arcade (uncomment)
      //strafeMech(mechSpeed*(getAnalog(LEFT_AXIS_X)));
    //}*/

    //Mechanum Arcade Code
    /*double getAnalogRArcade = getAnalog(LEFT_AXIS_Y) - getAnalog(RIGHT_AXIS_X);
    double getAnalogLArcade = getAnalog(LEFT_AXIS_Y) - ((getAnalog(RIGHT_AXIS_X))*-1);
    setDriveLF((getAnalogLArcade)-(getAnalog(LEFT_AXIS_X))*-1);
    setDriveLB((getAnalogLArcade)-(getAnalog(LEFT_AXIS_X))*1);
    setDriveRF((getAnalogRArcade)-(getAnalog(LEFT_AXIS_X))*1);
    setDriveRB((getAnalogRArcade)-(getAnalog(LEFT_AXIS_X))*-1);*/