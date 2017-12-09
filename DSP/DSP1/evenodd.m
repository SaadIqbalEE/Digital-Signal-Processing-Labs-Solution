function evenodd()
clc;
clear all;

n=-5:5;
x=[zeros(1,5) 2 3 -1 2 -3 0];

for i=1:length(n)

odd(i)= (x(i)-x(length(n)+1-i))/2;

even(i)= (x(i)+x(length(n)+1-i))/2;

end
length(n)
odd
even
subplot(3,1,1)
stem(n,odd)

subplot(3,1,2)
stem(n,even)

subplot(3,1,3)
stem(n,x)

