function [yn y]=convc(xn,x,hn,h)
%check
if(length(xn)==length(x) && length(hn)==length(h))
min_yn= xn(1)+hn(1);
l_yn= length(xn)+length(hn)-1;
yn=min_yn:min_yn+l_yn-1;
xt=[x zeros(1,length(yn)-length(x))];
ht=[h zeros(1,length(yn)-length(h))];

for i=1:length(yn) %convolution
    y(i)= sum(xt(1:1:i).*ht(i:-1:1));
end
else
    disp('Invalid inputs');
end
