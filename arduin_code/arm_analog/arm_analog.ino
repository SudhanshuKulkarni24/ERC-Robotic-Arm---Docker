#include <ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Point32.h>
#include <Servo.h>


#define DIR1 8               
#define PWM1 7
#define DIR2 4               
#define PWM2 5
#define DIR3 11              
#define PWM3 10

Servo myservo;  // create servo object to control a servo

int pos=0;

ros::NodeHandle nh;
geometry_msgs::Point32;
void messageCb( const geometry_msgs::Point32& msg){
  int motor1 = int(msg.x);
  int motor2 = int(msg.y);
  int motor3 = int(msg.z);


  if(msg.y<0){
    digitalWrite(DIR2,LOW);
    analogWrite(PWM2,-motor2) ;   
  }
  else{
    digitalWrite(DIR2,HIGH);
    analogWrite(PWM2,motor2) ; 
  }

  if(msg.x<0){
    digitalWrite(DIR1,LOW);
    analogWrite(PWM1,-motor1) ;   
  }
  else{
    digitalWrite(DIR1,HIGH);
    analogWrite(PWM1,motor1) ; 
  }

  if(msg.z<0){
    digitalWrite(DIR3,LOW);
    analogWrite(PWM3,-motor3) ;   
  }
  else{
    digitalWrite(DIR3,HIGH);
    analogWrite(PWM3,motor3) ; 
  }
  
}

void messageCb2( const geometry_msgs::Point32& msg){
  myservo.write(msg.x);              // tell servo to go to position in variable 'pos'
}

ros::Subscriber<geometry_msgs::Point32> sub("control1", &messageCb );
ros::Subscriber<geometry_msgs::Point32> sub2("gripper", &messageCb2 );


void setup()
{
  pinMode(DIR1,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(DIR3,OUTPUT);
  pinMode(PWM3,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  nh.initNode();

  nh.subscribe(sub);
  nh.subscribe(sub2);
  nh.getHardware()->setBaud(57600);
  // analogWrite(PWM1, 50);
}

void loop()
{ 
  // digitalWrite(DIR1,LOW);
  // delay(100);
  // digitalWrite(DIR1,HIGH);
  // delay(100);
  nh.spinOnce();
  
  delay(1);
}