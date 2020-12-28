#! /usr/bin/env python3


class PID_controller_wheel:
    def __init__(self,name,limits,gains):
        # self.last_call_time = rospy.get_time()
        self.name = name
        self.upper_limit,self.lower_limit = limits
        # print(self.upper_limit,self.lower_limit)
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
        limiter = self.in_bounds(correction+set_point)
        # print(limiter)
        # print("Correction = %.4f"%correction)

        return correction #limiter-set_point#*self.in_bounds(correction)

    def in_bounds(self,value):
        if  value == 0:
            return value
        elif value > self.upper_limit:
            return value-self.upper_limit
        elif  value < self.lower_limit:
            return value-self.lower_limit
        else:
            return value
