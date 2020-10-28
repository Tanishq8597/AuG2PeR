import rospy
import odrive
from odrive.enums import *

import time

odrive_board = odrive.find_any()



# Getting motor params
A0 = odrive_board.axis1
M0 = A0.motor
M0_enc = A0.encoder

# sets control mode
A0.controller.config.control_mode = CONTROL_MODE_VELOCITY_CONTROL
# Set state to close loop control
A0.requested_state = AXIS_STATE_CLOSED_LOOP_CONTROL
error = 0

for speed in range(-5,5,1):
    # Must be an int
    A0.controller.input_vel = speed + error
    # Velocity estimate can be used to compute error
    print("Desired speed = %d rev/s" % (speed)) 
    time.sleep(3)
    print("Measured speed = %.5f rev/s" % (A0.encoder.vel_estimate))
    error = abs(speed) - abs(A0.encoder.vel_estimate)
    print("Error correction = %.5f \n" % error)
    
    

A0.controller.input_vel = 0
A0.requested_state = AXIS_STATE_IDLE
