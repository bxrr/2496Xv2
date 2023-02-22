#ifndef __AUTON__
#define __AUTON__

#include "main.h"
#include "global.h"
#include "pid.h"
#include "aut_func.h"
#include "lib/auton_obj.h"
#include <vector>
#include <string>

using namespace pros;
using namespace pid;
using namespace glb;
using namespace auf;


//testing !

void skills()
{
    // shoot 2 preloads 
    fw_spin(340);
    delay(1000);
    shoot(3); //was set to -40
    
    //get 3 discs
    fw_spin(-80);
    open_intake();
    turn_to(90, 1500);
    fw_spin(0);
    
    drive(560, 1000);
    close_intake();
    intake_vel();
    delay(800);
   
    //shoot 3 discs
    turn_to(25.7, 700);
    drive(-1500, 1100);
    intake_stop();
    fw_spin(300);
    turn_to(-6, 550);
    shoot(3);
    fw_spin(-80);

    //get 3 on side of barrier
    turn_to(90, 700);
    intake_vel();
    drive_const(1850, 60);
    fw_spin(310);
    intakeP.set(true); //prevent 4disc
    drive(230, 400);
    
    
    //shoot 3 at corner barrier
    turn_to(47, 500);
    intake_stop();
    intakeP.set(false);
    // delay(300);
    shoot(3, -80);
    fw_spin(-80);
    
    //get 3 on side of barrier
    turn_to(-178.5, 850);
    fw_stop();
    intake_vel();
    drive_const(1710, 80);
    drive(350, 500); // brian was here 
    fw_spin(292);
    
    //shoot 3 from barrier tape
    open_intake();
    turn_to(98, 700);
    shoot(3);
    fw_stop();
    turn_to(84, 550);
    close_intake();
    intake_stop();

    // get roller 1
    intake_vel(-127);
    drive(2400, 1800);
    fw_stop();
    turn_to(180, 800);
    intake_vel(127);
    drive_const(700, 50, 900);

    // get 3
    drive(-270, 500);
    intake_stop();
    turn(180, 1000);
    open_intake(); // other brian was here
    drive(500, 800);
    close_intake();
    intake_vel();
    drive(580, 800);
    turn_to(90, 800);
    open_intake();

    //get roller 2
    intake_vel(127);
    drive_const(800, 100, 800);
    drive_const(1200, 40, 1000);
   
    // // shoot
    // drive(-320, 700);
    // turn(85.6, 1000);
    // fw_spin(295);
    // drive(-2240, 1600);
    // shoot(3);
    // close_intake();

    // // get 3 barrier
    // fw_spin(-70);
    // turn_to(-74, 800);
    // fw_stop();
    // intake_vel();
    // drive_const(2220, 60, 1500);
    // fw_spin(317);
    // intakeP.set(true); //prevent 4disc
    // drive(520, 700);

    // //shoot 3 corner shot
    // turn_to(-131.5, 700);
    // intake_stop();
    // shoot(3, -80);
    // fw_spin(-85);

    // //Get 3 in a line
    // intakeP.set(false);
    // intake_vel();
    // drive(150, 400);
    // turn_to(-45, 700);
    // drive(1665, 1500);

    // //shoot 3
    // fw_spin(310);
    // turn_to(-126, 700);
    // intake_stop();
    // drive(-1550, 1200);
    // turn_to(-81, 700);
    // shoot(3);
    // fw_spin(-80);

    // //get 3 along barrier
    // turn_to(160, 800);
    // fw_stop();
    // intake_vel();
    // drive_const(1880, 80, 1500);
    // fw_spin(322);
    // drive(370, 560);
    // intake_stop();

    // // shoot 3 at corner
    // open_intake();
    // turn_to(-136, 650);
    // shoot(3, -90);

    // // get 3
    // fw_stop();
    // turn(-56, 700);
    // drive(-1120, 900);
    // turn_to(-90, 800);
    // drive(1810, 1200);
    // close_intake();
    // intake_vel();
    // delay(500);

    // // roller 3
    // drive_const(1000, 100, 700);
    // open_intake();
    // drive_const(1200, 40, 1100);
    // // intake_vel(-127);

    // //shoot 3
    // fw_spin(446);
    // drive_const(-300);
    // intake_stop();
    // drive(-1050,900);
    // turn_to(-103, 650);
    // shoot(3, -50);

    // // roller 4
    // turn_to(0, 700);
    // drive_const(600, 100, 800);
    // intake_vel();
    // fw_stop();
    // drive_const(1440, 40, 900);

    // // end game
    // drive(-1260, 900);
    // turn_to(-45, 700);
    // drive(520, 550);
    // glb::sideExpandP.toggle();
    // for(int i = 0; i < 5; i++)
    // {
    //     glb::expansionP.toggle();
    //     pros::delay(200);
    // }
}

void none()
{
    turn(15);
}

void test_shoot()
{
    fw_spin(500);
    delay(2500);
    index();
    fw_stop();
    turn(180);
}

void turns()
{
    turn_to(-180);
    turn_to(0);
    delay(500);
    turn_to(135);
    turn_to(0);
    delay(500);
    turn_to(90);
    turn_to(0);
    delay(500);
    turn_to(45);
    turn_to(0);
    delay(500);
    turn_to(30);
    turn_to(0);
    delay(500);
    turn_to(9);
    turn_to(0);
    delay(500);
}

void drives()
{
    drive(3000);
    drive(-3000);
    delay(500);
    drive(1000);
    drive(-1000);
    delay(500);
    drive(500);
    drive(-500);
    delay(500);
    drive(250);
    drive(-250);
    delay(500);
    drive(100);
    drive(-100);
}

void solo_awp()//pmuller@tustin.k12.ca.us
{
    drive_const(100, 70, 200);
    fw_spin(445);
    intake_dist(-200);
    delay(200);
    drive(-200, 800);
    intake_dist(300);
    delay(100);
    // index(2, 300, 1800);
    fw_spin(395);

    intakeP.set(true);
    turn_to(-127.5, 1500);
    intake_vel();
    drive(1200, 1500);
    intakeP.set(false);
    delay(500);
    turn_to(-11.7);
    intake_vel(0);
    intakeP.set(true);
    // index(3, 300, 1800);
    fw_spin(333);

    turn_to(-132, 1600);
    intakeP.set(false);
    intake_vel(127);
    drive_const(4600);
    intake_vel(0);
    chas.spin_left(112);
    chas.spin_right(34);

    intakeP.set(true);
    delay(500);
    chas.spin(30);
    delay(300);
    intake_dist(-350);
    delay(500);
    chas.stop();
}

void ml_half_awp()
{
    drive_const(100, 127, 300);
    intake_dist(-200);
    delay(100);
    drive(-300, 500);
    // fw_spin(500);
    // index(2, 1000);
    // index(2, 600);
    // delay(150);
    // open_intake();
    // turn_to(-135, 1500);
    // drive(1250, 1200);
    // intake_vel();
    // close_intake();
    // delay(800);
    // fw_spin(480);
    // turn_to(-22, 1100);
    // delay(500);
    // intake_stop();
    // index(3, 600);
    // turn_to(-135, 1100);
    // drive(750, 900);
    // open_intake();
    // turn_to(90, 1100);
    // drive(600, 900);
    // intake_vel();
    // close_intake();
    // delay(500);
    // fw_spin(490);
    // drive(-600, 900);
    // turn_to(-15, 1100);
    // index(3, 500);
}

void nml_half_awp()
{
    fw_spin(480);
    drive(1160, 1500);
    turn_to(99, 1500);
    // index(2, 300, 2500);
    
    fw_stop();
    turn_to(90, 1300);
    drive_const(300, 70, 300);
    intake_dist(-250);
    delay(400);

    drive(-150, 1000);
    turn_to(-144);
    intake_vel();
    drive(3550);

    fw_spin(440);
    turn_to(138.9, 2000);
    delay(500);
    intake_vel(0);
    // index(3, 300, 2500);
    delay(900);
    fw_stop();
}

// AUTON LIST: CREATE AUTON OBJECTS WITH (NAME, FUNCTION) AS PARAMETERS TO BE USED IN AUTON SELECTOR
std::vector<Auton> autons
{
    Auton("skills", skills),
    Auton("none", none),
    Auton("test shoot", test_shoot),
    Auton("turns", turns),
    Auton("drives", drives),
    Auton("solo awp", solo_awp),
    Auton("ml half awp", ml_half_awp),
    Auton("nml half awp", nml_half_awp),
};


#endif