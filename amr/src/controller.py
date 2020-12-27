#! /usr/bin/env python3


class PID_controller_wheel:
    def __init__(self,name,limits,gains):
        # self.last_call_time = rospy.get_time()
        self.name = name
        self.upper_limit,self.lower_limit = limits
        self.KP,self.KI,self.KD = gains

    def effort(self,set_point,measured,dt):
        error = set_point - measured 
        # if set_point < 0:
        #     error*-1
        # print("Set Point = %.4f"%set_point)
        # print("Encoder = %.4f"%measured)
        # P gain
        p = self.KP*error
        # print("P = %.4f"%p)
        # I gain 
        i = self.KI*error*dt
        # print("I = %.4f"%i)
        # D gain
        d = self.KD*error/dt
        # print("D = %.4f"%d)

        correction = p + i + d #+ measured
        # print("Correction = %.4f"%correction)
        return correction#*self.in_bounds(correction)

    def in_bounds(self,value):
        if value is None or value == 0:
            return value
        elif value is not None and value > self.upper_limit:
            return self.upper_limit/value
        elif value is not None and value < self.lower_limit:
            return self.lower_limit/value
        else:
            return 1
