/*************************************************************************
	> File Name: drivercontrol.h
	> Author: yanbo
	> Mail: 
	> Created Time: 
 ************************************************************************/

#ifndef _DRIVERCONTROL_H
#define _DRIVERCONTROL_H
//#include <vector>

// ROS lib 
#include "ros/ros.h"
#include "ros/time.h"

#include <vector>
// lib

// Custom message includes. Auto-generated from msg/ directory.
#include "ivdrivercontrol/ivdrivercontrol.h"
#include "ivdrivercontrol/ivdriverdebug.h"
#include "ivactuator/ivactuator.h"
#include "ivobjectfusion/ivobjfus.h"
#include "ivobjectfusion/fusionobject.h"
#include "ivsteercontrol/ivsteercontrol.h"
#include "ivcogmatrix/ivcogmatrix.h"
#include "ivpathplanner/pathplanner.h"
#include "ivpathplanner/roadpoint.h"
#include "ivpathplanner/pathfeedback.h"
#include <math.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include "drivercontrol.h"
#include "ivpathplanner/roadpoint.h"  
#include "ivpathplanner/pathplanner.h"   
#include "ivsensorultra/ivsensorultraobj.h"
#include "ivsensorultra/ultraobject.h"
#include "ivapp/ivapp.h"
#define SUB_TOPIC_ULTRA 	"ivsensorultraobj"
using namespace std;
// # define 
typedef struct sObsMsg
{
    double distance;
    double speed;
    double relspeed;
    double classification;
    double laneinfo;
}sObsMsg;

class drivercontrol
{
    public:
    drivercontrol(ros::NodeHandle nh);
    ~drivercontrol();
	void run();

    private:
    int  loopFrep;
    int  cartype;
    double  sbjspeed;
    double sbjspeed_last;
    double  distance;
    double  relspeed;
    double ci_relspeed;
    double ci_distance;
    double acel_temp1;
    double acel_temp2;
    double torque_temp_last;//eggcar;
    double scspeedlimit;
    int controlstate;
    int controlstate_last;
    double acel_temp_last;
    double relspeed_cc_last;
    int cc_trigger; 
    double cruisespeed;
    double virtualspeed;
    double virtualspeed_last;
    double acel_esp;
    double mode_counter_cc;
    double mode_counter_acc;
    unsigned char sys_status;
    unsigned char road_curvelevel;
    double THW;
    double Dsafe;
    double acel_req;
    unsigned char Counter_Kinc;
    unsigned char Counter_Kdec;
    unsigned char loadtype_change_counter;
    unsigned char lanchang_flag;
    double Accel_cmd_lc;
    unsigned char cruise_lc_flag;
    double cruisespeed_lc;
    int Driverflag;
    int Brakeflag;
    int roadtype;
    unsigned char speedlost_cnt;
    unsigned char shiftposition;
    unsigned char drivercommand;            
    double distancestop;           
    unsigned char reverse_delay;
    double distance_PK;
    int distance_PK_cnt;
    unsigned char apporder;
    unsigned char apporder_last;
    int mapid;
    double actuator_control_BQ(double speed_cc,double accel_command);
    double drcontrol_BQ();
    double actuator_control_YD(double speed_cc,double accel_command);
    double drcontrol_YD();
    double actuator_control_FY(double speed_cc,double accel_command);
    double drcontrol_FY();
    double actuator_control_RC(double speed_cc,double accel_command);
    double drcontrol_RC();
    double THW_following();
    double adaptive_speed(double virspeed_cc);
    void objselect();
    void datarecord();
    void sbjspeedfilter();
    double ramp_adp_kps();
    void timerCallback(const ros::TimerEvent& event);
    void subCallback_actuator(const ivactuator::ivactuator::ConstPtr &msg);
    void subCallback_fusionobject(const ivobjectfusion::ivobjfus::ConstPtr &msg);
    void subCallback_steercontrol(const ivsteercontrol::ivsteercontrol::ConstPtr &msg);
    void subCallback_cogmatrix(const ivcogmatrix::ivcogmatrix::ConstPtr &msg);
    void subCallback_currentroad(const ivpathplanner::pathplanner::ConstPtr &msg);
    void subCallback_lanchang(const ivpathplanner::pathfeedback::ConstPtr &msg);
    void chatterCallbackUltra(const ivsensorultra::ivsensorultraobj::ConstPtr &msg);
    void chatterCallbackapp(const ivapp::ivapp::ConstPtr &msg);
    void forwardBackward();  
    void dataProcess();
    ivpathplanner::pathplanner     landpoint; 
    ivdrivercontrol::ivdrivercontrol msg_control;
    ivdrivercontrol::ivdriverdebug msg_debug;
    std::vector<sObsMsg>  realobs; 
    std::vector<sObsMsg>  virobs;
    ivsensorultra::ivsensorultraobj       ultraobj;
    ros::Timer      timer_;
    ros::Publisher  pub_;
    ros::Publisher  pub_debug;
    ros::Subscriber sub_actuator;
    ros::Subscriber sub_fusionobject;
    ros::Subscriber sub_steercontrol;
    ros::Subscriber sub_cogmatrix;
    ros::Subscriber sub_currentroad;
    ros::Subscriber sub_lanchang;
    ros::Subscriber  sub_ultra;
    ros::Subscriber  sub_app;


};

#endif  // _DRIVERCONTROL_h
