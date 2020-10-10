#include<ros.h>
#include<std_msgs/Int16.h>

// ROS node
ros::NodeHandle FT_node ;

//Publisher message and declaration
std_msgs::Int16 loop_var ;
ros::Publisher Freq_pub("R2A_FreqTest", &loop_var) ;

int loop_no ;

void setup() {
  // put your setup code here, to run once:
  FT_node.initNode() ;
  FT_node.advertise(Freq_pub) ;
  loop_no = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_no ++ ;
  loop_var.data = loop_no ;
  Freq_pub.publish(&loop_var) ;
  FT_node.spinOnce();
  delay(10) ;
}
