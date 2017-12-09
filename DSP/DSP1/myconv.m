function myconv()
x=[1 2 1 2];
xn=-1:2;
h=[0 1 2 4 1 1];
hn=-2:3;

% t=conv(x,h);
% stem(t)
n=length(x)+length(h);
for i=1;n-1
    y(i)=x(i)h(n-i);
    y()