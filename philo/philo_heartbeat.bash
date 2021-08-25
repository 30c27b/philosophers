#!/bin/bash

#         _     _ _         _                     _   _                _
#        | |   (_) |       | |                   | | | |              | |
#   _ __ | |__  _| | ___   | |__   ___  __ _ _ __| |_| |__   ___  __ _| |_
#  | '_ \| '_ \| | |/ _ \  | '_ \ / _ \/ _` | '__| __| '_ \ / _ \/ _` | __|
#  | |_) | | | | | | (_) | | | | |  __/ (_| | |  | |_| |_) |  __/ (_| | |_
#  | .__/|_| |_|_|_|\___/  |_| |_|\___|\__,_|_|   \__|_.__/ \___|\__,_|\__|
#  | |
#  |_|.bash

DEATH_TIME=410
EATING_TIME=200
SLEEPING_TIME=200
PHILO_SIZES=(100)
ITERATIONS=5

for size in ${PHILO_SIZES[@]}; do
    echo "Trying for size $size"
    survival_times=()
    for i in $(seq $ITERATIONS); do
        echo -n "starting iteration $i .."
        start_timestamp=$(date +%s)
        # ./philo $size $DEATH_TIME $EATING_TIME $SLEEPING_TIME >/dev/null
        sleep 5 &
        PID=$!
        j=1
        sp="/-\|"
		echo -n '  '
        while [ -n "$(ps -p $PID -o pid=)" ]; do
            printf "\b${sp:j++%${#sp}:1}"
        done
		echo 'Done'
        end_timestamp=$(date +%s)
        survival_time=`expr $end_timestamp - $start_timestamp`
        echo "survival time: $survival_time"
        survival_times+=($survival_time)
    done
    echo "survival times are: ${survival_times[*]}"
    sum=0
    for i in ${survival_times[@]}; do
        let sum+=$i
    done
    avg=`expr $sum / $ITERATIONS`
    echo "average is $avg"
done

