#!/bin/sh

if [ -n "$1" ]; then
    eth_name=$1
else
    eth_name="eth0"
fi

i=0

send_o=`ifconfig $eth_name | grep bytes | awk '{print $6}' | awk -F : '{print $2}'`
recv_o=`ifconfig $eth_name | grep bytes | awk '{print $2}' | awk -F : '{print $2}'`
send_n=$send_o
recv_n=$recv_o

while [ $i -le 100000 ]; do
    send_l=$send_n
    recv_l=$recv_n

    sleep 1

    send_n=`ifconfig $eth_name | grep bytes | awk '{print $6}' | awk -F : '{print $2}'`
    recv_n=`ifconfig $eth_name | grep bytes | awk '{print $2}' | awk -F : '{print $2}'`

    i=`expr $i + 1`
    send_r=`expr $send_n - $send_l`
    recv_r=`expr $recv_n - $recv_l`
    total_r=`expr $send_r + $recv_r`

    send_ra=`expr $send_n - $send_o`
    send_ra=`expr $send_ra / $i`
    recv_ra=`expr $recv_n - $recv_o`
    recv_ra=`expr $recv_ra / $i`
    total_ra=`expr $send_ra + $recv_ra`

    sendn=`ifconfig $eth_name | grep bytes | awk -F "(" '{print $3}' | awk -F ")" '{print $1}'`
    recvn=`ifconfig $eth_name | grep bytes | awk -F "(" '{print $2}' | awk -F ")" '{print $1}'`
    clear

#    echo  "Last second  :   Send rate: $send_r Bytes/sec  Recv rate: $recv_r Bytes/sec  Total rate: $total_r Bytes/sec"
#    echo  "Average value:   Send rate: $send_ra Bytes/sec  Recv rate: $recv_ra Bytes/sec  Total rate: $total_ra Bytes/sec"
#    echo  "Total traffic after startup:    Send traffic: $sendn  Recv traffic: $recvn"

    send_r=`expr 8 \* $send_r`
    recv_r=`expr 8 \* $recv_r`

    echo "$eth_name:"

    if [ $send_r -lt 1024 ]; then
        echo  "Send rate: $send_r bps"
    elif [ $send_r -lt 1048576 ]; then
        send_r=`expr $send_r / 1024`
        echo  "Send rate: $send_r Kbps"
    else
        send_r=`expr $send_r / 1048576`
        echo  "Send rate: $send_r Mbps"
    fi

    if [ $recv_r -lt 1024 ]; then
        echo  "Recv rate: $recv_r bps"
    elif [ $recv_r -lt 1048576 ]; then
        recv_r=`expr $recv_r / 1024`
        echo  "Recv rate: $recv_r Kbps"
    else
        recv_r=`expr $recv_r / 1048576`
        echo  "Recv rate: $recv_r Mbps"
    fi
done

