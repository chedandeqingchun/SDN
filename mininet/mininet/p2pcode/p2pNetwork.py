#!/usr/bin/python

from __future__ import print_function

from mininet.net import Mininet
#from mininet.node import node
from mininet.node import OVSSwitch, Controller, RemoteController
from mininet.cli import CLI
from mininet.log import lg
from mininet.topolib import TreeTopo
from mininet.topolib import TreeNet


##class LinuxRouter(Node):
#    "A Node with IP forwarding enabled."
#
#    def config(self, **params):
#        super(LinuxRouter, self).config(**params)
#        # Enable forwarding on the router
#        self.cmd('sysctl net.ipv4.ip_forward=1')
#
#    def terminate( self ):
#        self.cmd('sysctl net.ipv4.ip_forward=0')
#        super(LinuxRouter, self).terminate()



if __name__ == '__main__':
    class SingleSwitch(OVSSwitch):
        def start(self, controllers):
            return OVSSwitch.start(self, [cmap[self.name]])

    lg.setLogLevel('info')
    c0 = RemoteController('c0', ip='127.0.0.1', port=6633)
    cmap = {'s1':c0, 's2':c0, 's3':c0, 's4':c0}

    topo = TreeTopo(depth=2, fanout=2)
    net = Mininet(topo=topo, switch=SingleSwitch, build=False)
    net.addController(c0)
    net.build()
    #h3 = net.hosts[3]
    #h3.setDefaultRoute('via %s' % '10.0.0.1')

    # Add NAT connectivity
    #net.addNAT().config(mac=None, ip=h3.IP(), defaultRoute=None, lo='up')
    #net.addNAT().config(mac=None, defaultRoute=None, lo='up')
    net.addNAT().configDefault()
    net.start()
    print("*** Hosts are running and should have internet connectivity")
    print("*** Type 'exit' or control-D to shut down network")
    CLI(net)
    # Shut down NAT
    net.stop()
