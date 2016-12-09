#!/usr/bin/python
# -*- coding: UTF-8 -*-
import thread
import time
import threading

def func():
	print 'hello timer!'
#	gg_nFlags=0 
#	timer = threading.Timer(2, func)
#	timer.start()
	
timer = threading.Timer(10, func)
timer.start()

timer = threading.Timer(2, func)
timer.start()

while 1:
	pass