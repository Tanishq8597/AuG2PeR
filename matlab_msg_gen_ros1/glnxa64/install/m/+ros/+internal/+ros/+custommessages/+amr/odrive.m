function [data, info] = odrive
%odrive gives an empty data for amr/odrive
% Copyright 2019-2020 The MathWorks, Inc.
data = struct();
[data.header, info.header] = ros.internal.ros.messages.std_msgs.header;
info.header.MLdataType = 'struct';
[data.left_vel, info.left_vel] = ros.internal.ros.messages.ros.default_type('int16',1);
[data.right_vel, info.right_vel] = ros.internal.ros.messages.ros.default_type('int16',1);
info.MessageType = 'amr/odrive';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,8);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'left_vel';
info.MatPath{8} = 'right_vel';
