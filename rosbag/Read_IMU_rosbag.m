%% Reading IMU message
clc
%% ROS
rosshutdown ;

setenv('ROS_IP','10.1.1.71') ;
setenv('ROS_MASTER_URI','http://10.1.1.33:11311') ;

% Start the nodeclear

rosinit ;

Fusion = ahrsfilter('SampleRate',300) ;
viewer = HelperOrientationViewer('Title',{'AHRS Filter'});

%%
try
    delete(MTLB_node) ;
catch
    disp("No prior node") ;
end
MTLB_node = ros.Node("/Matlab_IMU2") ;

% MTLB_sub = ros.Subscriber(MTLB_node,'/IMU','amr/grove_10dof',@ShowIMU) 
sub2 = rossubscriber('/rosout');

MTLB_sub = rossubscriber('/IMU') ;

while(1)
    IMU_msg = receive(MTLB_sub,1) ;
    
    Quat = Fusion(IMU_msg.AccelVal',...
                  IMU_msg.GyroVal',...
                  IMU_msg.MagVal') ;
              
    viewer(Quat) ;
end
    
%%

% %% ROSBAG
% IMU_bag = select(rosbag('2020-11-06-00-39-32.bag'),'Topic','/IMU') ;
% IMU_msgs = readMessages(IMU_bag,'DataFormat','struct') ;
% 
% Fusion = ahrsfilter() ;
% viewer = HelperOrientationViewer('Title',{'AHRS Filter'});
% 
% for msg_no = 1:length(IMU_msgs)
%    
% [Quat,R] = step(Fusion,IMU_msgs{msg_no}.AccelVal',...
%             IMU_msgs{msg_no}.GyroVal',...
%             IMU_msgs{msg_no}.MagVal') ;
%         
% viewer(Quat) 
% end

%% Functions
function ShowIMU(msg)

end