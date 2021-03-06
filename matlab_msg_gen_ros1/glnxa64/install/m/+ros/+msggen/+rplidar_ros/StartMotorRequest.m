
classdef StartMotorRequest < ros.Message
    %StartMotorRequest MATLAB implementation of rplidar_ros/StartMotorRequest
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'rplidar_ros/StartMotorRequest' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = 'bd160db0cb9e838a10809e84d876d07a' % The MD5 Checksum of the message definition
        PropertyList = { 'Pwm' } % List of non-constant message properties
        ROSPropertyList = { 'pwm' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.std_msgs.UInt16' ...
			 } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Pwm
    end
    methods
        function set.Pwm(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.UInt16'};
            validateattributes(val, validClasses, validAttributes, 'StartMotorRequest', 'Pwm')
            obj.Pwm = val;
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.rplidar_ros.StartMotorRequest.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.rplidar_ros.StartMotorRequest;
            obj.reload(strObj);
        end
    end
end
