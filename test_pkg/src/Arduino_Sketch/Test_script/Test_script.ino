#include <ros.h>
#include <std_msgs/String.h>

//Create a ROS node
ros::NodeHandle ros_node ;

// Creating message type variable
std_msgs::String msg_out;
char template_msg[] = "I recieved " ;

//Publisher
ros::Publisher outgoing_msg("ROS2ArduinoPub", &msg_out);

//Callback function
void string_CB(const std_msgs::String &incoming_msg)
{
  msg_out.data = template_msg  ;
  outgoing_msg.publish(&msg_out);
  msg_out.data = incoming_msg.data ;
  outgoing_msg.publish(&msg_out);
}

// Subscriber
ros::Subscriber<std_msgs::String> incoming_sub("ROS2ArduinoSub", &string_CB) ;


void setup() {
  // put your setup code here, to run once:
  //    Serial.begin(57600) ;
  ros_node.initNode();
  ros_node.advertise(outgoing_msg);
  ros_node.subscribe(incoming_sub);
}

void loop() {
  // put your main code here, to run repeatedly:
  ros_node.spinOnce();
  delay(10);
}
