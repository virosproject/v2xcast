#!/bin/sh
DEVICE=$1
ADDR=$2
OPTION=$3
SSH_COMMAND="ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null root@$ADDR"
if [ $OPTION = "snapshot" ]
then
    $SSH_COMMAND "/usr/bin/log_archive.sh"
    $SSH_COMMAND "tar -zcvf log_archive.tar.gz /home/unex/log_archive/snapshot/"
    scp -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null root@$ADDR:/home/root/log_archive.tar.gz ../${DEVICE}_log_archive.tar.gz
    $SSH_COMMAND "rm /home/root/log_archive.tar.gz"
    $SSH_COMMAND "rm /home/unex/log_archive/snapshot/*"
elif [ $OPTION = "status" ]
then
    ../bin/v2xcast_manager $ADDR/poti_status
    ../bin/v2xcast_manager $ADDR/gn_status
else
    echo "Wrong Arguments!"
fi