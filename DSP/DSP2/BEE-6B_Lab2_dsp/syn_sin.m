%SYN_SIN Function to synthesize a sum of cosine waves
function [xx,tt] = syn_sin(fk, Xk, fs, dur, tstart)

if(nargin==4)
    tstart= 0;
end
if(length(fk)==length(Xk))
tt=tstart:1/fs:tstart+dur;
xx=zeros(1,length(tt));
for i=1:length(fk)
temp=(real(Xk(i)*exp(j*2*pi*fk(i)*tt)));
xx=temp+xx;
end
stem(tt,xx);
else
    disp('Input are invalid');
end