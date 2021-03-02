#! /bin/bash
m=500
n=$((m / 20))
for A in $(eval echo {$(expr $n + 1)..$(expr $m - $n + 1)..$n}) 
do
    B=$(expr $A + $n - 1)
    cp ./IntegralityTest.cpp ./IntegralityTest$A.cpp 
    sed -i "s/AAA/$A/g" ./IntegralityTest$A.cpp
    sed -i "s/BBB/$B/g" ./IntegralityTest$A.cpp
    sed -i "s/mmm/$m/g" ./IntegralityTest$A.cpp
    g++ -o IntegralityTest$A ./IntegralityTest$A.cpp -lgmpxx -lgmp
    rm ./IntegralityTest$A.cpp
    screen -S IT$A -d -m ./IntegralityTest$A
done
