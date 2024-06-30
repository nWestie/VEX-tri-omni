/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       westn                                                     */
/*    Created:      6/28/2024, 10:47:14 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "Vec2D.h"
#include <math.h>
#include <vex.h>

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// Convert boolean to direction - forward is true
directionType fwdBack(bool dir) { return dir ? forward : reverse; }

// define your global instances of motors and other devices here
int main() {
    controller control;

    motor m1(1);
    motor m2(2);
    motor m3(3);

    Vec2D motor1Dir(0, 1);
    Vec2D motor2Dir = motor1Dir.rotate(2 * M_PI / 3);
    Vec2D motor3Dir = motor2Dir.rotate(2 * M_PI / 3);

    while (true) {
        // get joystick values(-100 to 100)
        int32_t joystickX = control.Axis1.position();
        int32_t joystickY = control.Axis2.position();
        int32_t spin = control.Axis4.position();

        Vec2D joystickPos(joystickX, joystickY);
        double m1Power = motor1Dir.dotProd(joystickPos);
        double m2Power = motor2Dir.dotProd(joystickPos);
        double m3Power = motor3Dir.dotProd(joystickPos);

        m1Power += spin;
        m2Power += spin;
        m3Power += spin;

        Brain.Screen.printAt(10, 50, "%.2f,%.2f,%.2f     ", m1Power, m2Power, m3Power);
        double maxPower = fmax(fmax(fabs(m1Power), fabs(m2Power)), fabs(m3Power));
        if (maxPower > 100) {
            m1Power * 100 / maxPower;
            m2Power * 100 / maxPower;
            m3Power * 100 / maxPower;
        }
        Brain.Screen.printAt(10, 80, "%.2f,%.2f,%.2f     ", m1Power, m2Power, m3Power);
        
        // double angle = atan2(joystickY, joystickX);
        // double speedVector = sqrt(joystickY + joystickY);
        // calculate motor powers

        // m1.spin(fwdBack(m1Power), fabs(m1Power), velocityUnits::pct);
        // m2.spin(fwdBack(m2Power), fabs(m2Power), velocityUnits::pct);
        // m3.spin(fwdBack(m3Power), fabs(m3Power), velocityUnits::pct);
    }
}
