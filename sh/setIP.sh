#!/bin/bash
SOURCE_ADDR=192.168.1.3
TARGET_ADDR=192.168.2.3
SOURCE_DHCP=192.168.1.1
TARGET_DHCP=192.168.2.1

DIR_PATH=/etc/network
INTERFACES="$DIR_PATH/interfaces"
UDHCPD="$DIR_PATH/udhcpd.conf"

reboot(){
    $SSH_COMMAND "/sbin/reboot"

    echo "Restart device(about 30s)...if there is no response, please press ctrl+c"
    while :
        do
            ping -c1 $TARGET_ADDR > /dev/null && break
        done
    echo "\nRestart completed!"
    echo "The device IP has been changed from $SOURCE_ADDR to $TARGET_ADDR"
}

if [ "$1" = "reset" ]
then
    TEMP=$SOURCE_ADDR
    SOURCE_ADDR=$TARGET_ADDR
    TARGET_ADDR=$TEMP

    TEMP=$SOURCE_DHCP
    SOURCE_DHCP=$TARGET_DHCP
    TARGET_DHCP=$TEMP

    # ssh-keygen -f "/home/$USER/.ssh/known_hosts" -R "$SOURCE_ADDR"
    SSH_COMMAND="ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null root@$SOURCE_ADDR"
    $SSH_COMMAND "sed -i 's/$SOURCE_ADDR/$TARGET_ADDR/g' $INTERFACES;\
                  sed -i 's/$SOURCE_DHCP/$TARGET_DHCP/g' $UDHCPD"
    reboot
elif [ "$1" = "" ]
then
    # ssh-keygen -f "/home/$USER/.ssh/known_hosts" -R "$SOURCE_ADDR"
    SSH_COMMAND="ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null root@$SOURCE_ADDR"
    $SSH_COMMAND "sed -i 's/$SOURCE_ADDR/$TARGET_ADDR/g' $INTERFACES;\
                  sed -i 's/$SOURCE_DHCP/$TARGET_DHCP/g' $UDHCPD"
    reboot
else
    echo "Wrong Arguments!"
fi



