#include "robot.h"

using namespace std;

//determines if the drive value is within the grid
bool robot::is_goal_walkable(int num_cells)
{
    x_pos = x_pos + num_cells;
    y_pos = y_pos + num_cells;
    if (x_pos < MAX_X)
    {
        return true;
    }
    else
        return false;
}
string robot::setLinSpeed(float grid_per_sec)
{
    robot_drive_speed = grid_per_sec;
    return to_string(grid_per_sec);
}
string robot::setAngSpeed(float quarter_turn_per_sec)
{
    robot_turn_speed = quarter_turn_per_sec;
    return to_string(quarter_turn_per_sec);

}
string robot::drive(int num_cells)
{
    if (is_goal_walkable(num_cells))
    {
        // calculate position
        int drive_time = num_cells / robot_drive_speed;
    }
    else{
        turn(1);
        //return
    }
    return to_string(num_cells);
    
}

string robot::turn(int num_quarter_rotation)
{
    int turns;
    if (num_quarter_rotation == 3 || num_quarter_rotation == -3)
        turns = -1;
    if (num_quarter_rotation > 2 || num_quarter_rotation < -2)
    {
        turns = num_quarter_rotation % 4;
        if (turns == 3)
            turns = -1;
    }
    else{
        turns = num_quarter_rotation;
        int turn_time = num_quarter_rotation / robot_turn_speed;
    }
    return to_string(turns);
}
string robot::stop()
{
    // delay(1000);
    return "Pause for one sec";
}

string robot::eStop()
{
    return "Program ended";
}
