clc;
clear all;
bb = [0.25, 0.25 0.25, 0.25]; %-- Filter Coefficients
ww = -pi:(pi/200):pi; %-- omega hat
HH = freqz(bb, 1, ww);
subplot(2,1,1);
plot(ww, abs(HH))
subplot(2,1,2);
plot(ww, angle(HH))
xlabel('Normalized Radian Frequency')
