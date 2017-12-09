clc;
clear all;

w= -pi:pi/200:pi;
a=0.8;
M=9;
bb1= a.^(0:M);
HH1= freqz(bb1,1,w);
% subplot(2,2,1);
% plot(w, abs(HH1))
% subplot(2,2,3);
% plot(w, angle(HH1))
% xlabel('Normalized Radian Frequency of H1');

bb2= [1 -a];
HH2= freqz(bb2,1,w);
% subplot(2,2,2);
% plot(w, abs(HH2))
% subplot(2,2,4);
% plot(w, angle(HH2))
% xlabel('Normalized Radian Frequency of H2');

HH=HH1.*HH2;
subplot(2,1,1);
plot(w, abs(HH))
subplot(2,1,2);
plot(w, angle(HH))
xlabel('Normalized Radian Frequency');
