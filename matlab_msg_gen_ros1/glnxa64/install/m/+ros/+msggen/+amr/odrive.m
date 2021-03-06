
classdef odrive < ros.Message
    %odrive MATLAB implementation of amr/odrive
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'amr/odrive' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = 'fee1aba673a70a9570d354c2566343f8' % The MD5 Checksum of the message definition
        PropertyList = { 'Header' 'LeftVel' 'RightVel' } % List of non-constant message properties
        ROSPropertyList = { 'header' 'left_vel' 'right_vel' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.std_msgs.Header' ...
			 '' ...
			 '' ...
			 } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Header
        LeftVel
        RightVel
    end
    methods
        function set.Header(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Header'};
            validateattributes(val, validClasses, validAttributes, 'odrive', 'Header')
            obj.Header = val;
        end
        function set.LeftVel(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'odrive', 'LeftVel');
            obj.LeftVel = int16(val);
        end
        function set.RightVel(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'odrive', 'RightVel');
            obj.RightVel = int16(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.amr.odrive.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.amr.odrive;
            obj.reload(strObj);
        end
    end
end
