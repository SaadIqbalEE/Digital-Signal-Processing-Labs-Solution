function diffequ(a,x,i)
format long
l=length(x)
for m=1:l
    y(m)=a*i+x(m);
    i=y(m);
end
y