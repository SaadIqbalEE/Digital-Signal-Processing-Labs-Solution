function [y]=diffequ(a,x,i) %x starting from zero index
for m=1:length(x) %impliment difference function
    y(m)=a*i+x(m);
    i=y(m);
    end
end