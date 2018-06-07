from time import sleep
from mininet.net import *


print "Starting test..."
h1 = net.get('h1')
result = h1.cmd('ifconfig')
print result

h1.cmd("while true; do date; sleep 1; done > /tmp/date.out &")
sleep(10)
print "Stopping test..."
