function [data, info] = wheel
%wheel gives an empty data for amr/wheel
% Copyright 2019-2020 The MathWorks, Inc.
data = struct();
[data.header, info.header] = ros.internal.ros.messages.std_msgs.header;
info.header.MLdataType = 'struct';
[data.setpoint_speed, info.setpoint_speed] = ros.internal.ros.messages.ros.default_type('double',1);
[data.encoder_speed, info.encoder_speed] = ros.internal.ros.messages.ros.default_type('double',1);
[data.PID_speed, info.PID_speed] = ros.internal.ros.messages.ros.default_type('double',1);
[data.dt, info.dt] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'amr/wheel';
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
info.MatPath{7} = 'setpoint_speed';
info.MatPath{8} = 'encoder_speed';
info.MatPath{9} = 'PID_speed';
info.MatPath{10} = 'dt';
