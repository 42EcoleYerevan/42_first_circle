#!/bin/bash

wall '#Architecture : '`uname -svrm`'
#CPU physical : '`nproc`'
#vCPU : '`cat /proc/cpuinfo | grep processor | wc -l`'
#Memory Usage : '`free -m | grep Mem | awk '{printf("%s/%sMB (%.2f%%)"), $3, $2, ($3/$2)*100}'`'
#Disk Usage : '`df -h / | sed -n '2p' | awk '{printf("%s/%s (%s)"), $4, $2, $5}'`'
#CPU load : '`top -bn1 | grep Cpu | awk '{printf("%.1f%%"), $2 + $4}'`'
#Last boot : '`who -b | awk '{print $3, $4}'`'
#LVM use : '`lsblk | grep lvm | wc -l | awk '{if ($1 > 0) {print "yes"} else {print "no"}}'`'
#Connections TCP : '`grep TCP /proc/net/sockstat | awk '{print $3}'`' ESTABILISHED
#User log : '`who | wc -l`'
#Network IP : '`hostname -I`'('`ip addr | tail -n 5 | sed -n '1p' | awk '{print $2}'`')
#Sudo : '`sudo grep 'USER=root' /var/log/auth.log | wc -l`
