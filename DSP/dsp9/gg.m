clc;
clear all;
n=0:149;
xx= 5*cos(0.3*pi*n)+22*cos(0.44*pi*n-pi/3)+22*cos(0.7*pi*n-pi/4);
stem(n,xx)