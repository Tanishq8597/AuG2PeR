function [data, info] = iMU_10dof
%IMU_10dof gives an empty data for amr/IMU_10dof
% Copyright 2019-2020 The MathWorks, Inc.
data = struct();
[data.header, info.header] = ros.internal.ros.messages.std_msgs.header;
info.header.MLdataType = 'struct';
[data.gyro_val, info.gyro_val] = ros.internal.ros.messages.ros.default_type('double',3);
[data.accel_val, info.accel_val] = ros.internal.ros.messages.ros.default_type('double',3);
[data.mag_val, info.mag_val] = ros.internal.ros.messages.ros.default_type('double',3);
[data.temp, info.temp] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'amr/IMU_10dof';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,10);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'gyro_val';
info.MatPath{8} = 'accel_val';
info.MatPath{9} = 'mag_val';
info.MatPath{10} = 'temp';
