
classdef Tag < ros.Message
    %Tag MATLAB implementation of ros_decawave/Tag
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'ros_decawave/Tag' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '2c5d53ffcbf3427d3ef936e7e3b87a10' % The MD5 Checksum of the message definition
        PropertyList = { 'Header' 'X' 'Y' 'Z' 'Qf' 'NAnchors' } % List of non-constant message properties
        ROSPropertyList = { 'header' 'x' 'y' 'z' 'qf' 'n_anchors' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.std_msgs.Header' ...
			 '' ...
			 '' ...
			 '' ...
			 '' ...
			 '' ...
			 } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Header
        X
        Y
        Z
        Qf
        NAnchors
    end
    methods
        function set.Header(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Header'};
            validateattributes(val, validClasses, validAttributes, 'Tag', 'Header')
            obj.Header = val;
        end
        function set.X(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Tag', 'X');
            obj.X = double(val);
        end
        function set.Y(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Tag', 'Y');
            obj.Y = double(val);
        end
        function set.Z(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Tag', 'Z');
            obj.Z = double(val);
        end
        function set.Qf(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Tag', 'Qf');
            obj.Qf = double(val);
        end
        function set.NAnchors(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'Tag', 'NAnchors');
            obj.NAnchors = int16(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.ros_decawave.Tag.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.ros_decawave.Tag;
            obj.reload(strObj);
        end
    end
end
