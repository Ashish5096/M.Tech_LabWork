
echo Enter the no of terms
read n

a=0
b=1

for ((i=0;i<n;i++))
do
    if [ $i -le 1 ]
    then
        c=$i
    else
        c=$(( a + b ))
        a=$b
        b=$c
    fi
    echo -n $c " "
done
echo
