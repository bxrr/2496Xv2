#ifndef __AUT_FUNC__
#define __AUT_FUNC__

#include "main.h"
#include "global.h"
#include "pid.h"
#include "driver.h"
#include "lib/chassis.h"


namespace auf
{
    void auton_expand()
    {
        for(int i = 0; i < 5; i++)
        {
            glb::expansionP.toggle();
            pros::delay(200);
        }
    }
    void intake_vel(double speed=127)
    {
        glb::intakeL.move(-speed);
        glb::intakeR.move(-speed);
    }

    void intake_dist(double distance, double speed=600)
    {
        glb::intakeL.move(0);
        glb::intakeR.move(0);
        glb::intakeL.move_relative(-distance, speed);
        glb::intakeR.move_relative(-distance, speed);
    }
    inline void roller(double distance, double tdelay = 0, double speed = 600)
    {
        if (tdelay == 0) tdelay = abs(distance);
        chas.spin(25);
        glb::intakeL.move_relative(-distance, speed);
        glb::intakeR.move_relative(-distance, speed);
        delay(tdelay);
        chas.stop();
    }

    void intake_stop()
    {
        glb::intakeL.brake();
        glb::intakeR.brake();
    }

     void open_intake() 
     {
        intakeP.set(true);
    }
    
    void close_intake() 
    {
        intakeP.set(false);
    }

    void index(int num_discs=3, int ms_delay=pid::fw::flywheel_target / 500 * 650)
    {
        for(int i = 0; i < num_discs; i++)
        {
            pid::fw::force_recover = true;
            intake_dist(num_discs == 0 ? -360 : -320);
            pros::delay(150);
            pid::fw::force_recover = false;
            if(i < num_discs-1) 
            {
                pros::delay(ms_delay-150);
            }
        }
        pid::fw::force_recover = false;
        delay(200);
    }

    void pid_index(int num_discs=3, int timeout=4000)
    {
        int time = 0;
        int shot = 0;
        int last_time = -507;

        while(time < timeout && shot < num_discs)
        {
            if(abs(pid::fw::error) < 2 && time - last_time > 350)
            {
                intake_dist(num_discs == 0 ? -340 : -320);
                last_time = time;
                // pid::fw::force_recover = true;
                pros::delay(150);
                // pid::fw::force_recover = false;
                time += 150;
                shot++;
            }
            time += 10;
            pros::delay(10);
        }
        pid::fw::force_recover = false;
        delay(250);
    }

    void shoot(int num_discs=3, double shoot_speed=-79)
    {
        delay(300);
        intake_vel(shoot_speed);
        int time = 0;
        while(time < num_discs * 350)
        {
            time += 10;
            pros::delay(10);
            if(glb::disc_sensor1.get() > 85) 
            {
                break;
            }
        }
        delay(200);
        intake_vel(0);
    }
}


#endif