% single sinosidal
function [xx tt]=one_cos(amplitude,omega,phase,dur)
tt=0:(2*pi)/(omega*20):dur;
xx=amplitude*cos(omega*tt+phase);
stem(tt,xx);