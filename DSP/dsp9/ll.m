clc;
clear all;

h1=[1 -2*cos(0.44*pi) 1];
h2=[1 -2*cos(0.7*pi) 1];
h= firfilt(h1,h2);
n=0:149;
xx= 5*cos(0.3*pi*n)+22*cos(0.44*pi*n-pi/3)+22*cos(0.7*pi*n-pi/4);

KK= firfilt(h,xx);

stem(KK(1:40));

