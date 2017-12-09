clc;
clear all;

w= -pi:pi/200:pi; 
K= .5.*exp(1i*1.5*w).*(cos(0.5*w)+cos(1.5*w));
subplot(2,1,1);
plot(w, abs(K))
subplot(2,1,2);
plot(w, angle(K))
xlabel('Normalized Radian Frequency')