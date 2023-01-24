#include <iostream>
#include <fstream>
#include <string>
#include "robot.h"

using namespace std;
robot myRobot;

void outputLog(std::string output1, std::ofstream &logfile)
{
    logfile << output1 << '\n';
}
int main()
{
    std::ifstream myfile;
    myfile.open("instructions.txt"); //file program will read from
    std::ofstream outfile;
    outfile.open("log.txt"); //file program will write to
    std::string instruction;

    if (myfile.is_open())
    {
        while (myfile)
        {
            std::getline(myfile, instruction); //read each line
            if (instruction.substr(0,1) == "D") //read the first letter of each instruction
            {
                string drive_grid = instruction.substr(1);
                string val = myRobot.drive(stoi(drive_grid));
                outputLog("Drove: " + val, outfile);
            }
            else if (instruction.substr(0,1) == "T")
            {
                string turn_grid = instruction.substr(1);
                string val = myRobot.turn(stoi(turn_grid));
                outputLog("Turn: " + val, outfile);
            }
            else if (instruction.substr(0,1) == "S") //if instruction starts with S, move
                                                     //to next letter in string
            {
                string speed = instruction.substr(1,1);
                if (speed == "S")
                {
                    string lin_speed = instruction.substr(2);
                    string val = myRobot.setLinSpeed(std::stof(lin_speed));
                    outputLog("Linear Speed: " + val, outfile);
                }
                else if (speed == "T")
                {
                    string ang_speed = instruction.substr(2);
                    string val = myRobot.setAngSpeed(std::stof(ang_speed));
                    outputLog("Angular Speed: " + val, outfile);
                }
                else
                {
                    outputLog(myRobot.stop(), outfile);
                }
            }
            else if (instruction.substr(0,1) == "E")
            {
                outputLog(myRobot.eStop(), outfile);
            }
            else if (instruction.substr(0,2) == "UL")
            {
                float dist_value = stoi(instruction.substr(2));
                if (dist_value < 1)
                {
                    myRobot.turn(1);
                    outputLog("Object too close, turn", outfile);
                }
                else {
                   outputLog("Object far away, keep going", outfile);  
                }
            }
            else {
                outputLog("Unknown instruction", outfile);
            }
        }
    }
    myfile.close();
    outfile.close();
}