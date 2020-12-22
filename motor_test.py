import rospy
import odrive
from odrive.enums import *

import time

odrive_board = odrive.find_any()



# Getting motor params
A0 = odrive_board.axis0
M0 = A0.motor
M0_enc = A0.encoder

# A1 = odrive_board.axis1
# M1 = A1.motor
# M1_enc = A1.encoder

# sets control mode
A0.controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL
# A1.controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL
# Set state to close loop control
A0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
# A1.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
error0 = 0
error1 = 0

for speed in range(-5,5,1):
    # Must be an int
    A0.controller.input_vel = speed/10 + error0
    # A1.controller.input_vel = speed/10 + error1
    # Velocity estimate can be used to compute error
    print("Desired speed = %.2f rev/s" % (speed/10)) 
    time.sleep(3)
    print("Measured speed M0= %.5f rev/s" % (A0.encoder.vel_estimate))
    # print("Measured speed M1= %.5f rev/s" % (A1.encoder.vel_estimate))
    error0 = abs(speed/10) - abs(A0.encoder.vel_estimate)
    # error0 = abs(speed/10) - abs(A1.encoder.vel_estimate)
    print("Error correction M0= %.5f \n" % error0)
    # print("Error correction M1= %.5f \n" % error1)
    
    

A0.controller.input_vel = 0
A0.requested_state = AXIS_STATE_IDLE

# A1.controller.input_vel = 0
# A1.requested_state = AXIS_STATE_IDLE