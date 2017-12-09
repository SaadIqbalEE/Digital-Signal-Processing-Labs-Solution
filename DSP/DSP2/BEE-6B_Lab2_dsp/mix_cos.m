tt_temp=0:1/2048:2;       
%generating 3 sinosidals for dur 2sec
x1=real(10*exp(2*pi*100*j*tt_temp));
x2=real(180*exp(2*pi*250*j*tt_temp));
x3=real(100*exp(2*pi*175*j*tt_temp));
xx=[x1 x2 x3];
spectrogram(xx,128,100,128,2048);
