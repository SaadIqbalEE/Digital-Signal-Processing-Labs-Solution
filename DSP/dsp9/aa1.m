clc;
clear all;

w= -pi:pi/200:pi;
bb1=[1 -2*cos(0.44*pi) 1];
bb2=[1 -2*cos(0.7*pi) 1];

HH1= freqz(bb1,1,w);
HH2= freqz(bb2,1,w);
HH = HH1.*HH2;
subplot(2,3,1);
plot(w, abs(HH1))
subplot(2,3,4);
plot(w, angle(HH1))
xlabel('Normalized Radian Frequency of H1');

subplot(2,3,2);
plot(w, abs(HH2))
subplot(2,3,5);
plot(w, angle(HH2))
xlabel('Normalized Radian Frequency of H2');

subplot(2,3,3);
plot(w, abs(HH))
subplot(2,3,6);
plot(w, angle(HH))
xlabel('Normalized Radian Frequency of H');
