#to print even numbers between 1 to 100
#!/bin/bash
i=1
while [ $i -le 100 ]
do
	if [ `expr $i % 2` = 0 ]   
	then
	echo $i
	fi
	i=`expr $i + 1`
done

