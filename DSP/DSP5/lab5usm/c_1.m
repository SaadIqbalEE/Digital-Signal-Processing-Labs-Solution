clear all;
clc;

myimg = ones(400,1)*cos(2*pi*(0:399)/80);
myimg_final = myimg.';

imshow(myimg_final)