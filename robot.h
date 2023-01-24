#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class robot {
    int MAX_X=20;
    int MAX_Y=20;
    int x_pos=0;
    int y_pos=0;
    float robot_drive_speed=0;
    float robot_turn_speed=0;
    
    enum ROBOT_STATE {
    DRIVE,
    TURN,
    ULTRASONIC,
    PAUSE,
    IDLE
    }; 
    ROBOT_STATE robotState = IDLE;

    public:
    string drive(int num_cells);
    bool is_goal_walkable(int num_cells);
    string turn(int num_rotation);
    string stop();
    string eStop();
    string setLinSpeed(float grid_sec);
    string setAngSpeed(float turn_sec);
};
