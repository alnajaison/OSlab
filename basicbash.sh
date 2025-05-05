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


#find factorial
#!/bin/bash
echo Enter a number:
read n
fact=1
for((i=n;i>0;i--))
do
	fact=$((fact*i))
done
echo Factorial of $n is $fact


#check if armstrong
#!/bin/bash
echo enter a number
read n
t=$n
s=0
while [ $n -gt 0 ]
do
	d=`expr $n % 10`
	s=$((s + d * d * d))
	#s=`expr $s + $d \* $d \* $d`
	n=`expr $n / 10`
done
if [ $s -eq $t ]
then
	echo it is armstrong
else
	echo it is not armstrong
fi


#check if prime
#!/bin/bash
echo enter a number
read n
count=0
for ((i=2;i<=n;i++))
do
	if [ $((n%i)) -eq 0 ]
	then
		count=`expr $count + 1`
	fi
done
if [ $count == 1 ]
then
	echo prime
else
	echo not prime
fi


#reverse number
#!/bin/bash
echo Enter a number:
read n
rev=0
while [ $n -gt 0 ]
do
	d=`expr $n % 10`
	rev=$((rev*10+d))
	n=`expr $n / 10`
done
echo $rev


#fibonacci series
#!/bin/bash
echo "Enter the number of terms: "
read n
a=0
b=1
echo "Fibonacci sequence:"
for (( i=0; i<n; i++ ))
do
  echo -n "$a "
  # Calculate the next term
  fn=$((a + b))
  a=$b
  b=$fn
done
echo
