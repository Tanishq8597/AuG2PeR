function [data, info] = startMotorRequest
%StartMotor gives an empty data for rplidar_ros/StartMotorRequest
% Copyright 2019-2020 The MathWorks, Inc.
data = struct();
[data.pwm, info.pwm] = ros.internal.ros.messages.std_msgs.uInt16;
info.pwm.MLdataType = 'struct';
info.MessageType = 'rplidar_ros/StartMotorRequest';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,2);
info.MatPath{1} = 'pwm';
info.MatPath{2} = 'pwm.data';
