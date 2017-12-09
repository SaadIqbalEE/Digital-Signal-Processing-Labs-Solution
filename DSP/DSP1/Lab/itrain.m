function [yn y]=itrain(N,k)
yn_min=k(1)*N-1;
yn_max=k(end)*N+1;
yn=yn_min:yn_max;
y=0;
for i=1:length(k)-1
    y=cat(2,y,[1 zeros(1,N-1)]);
end
y=cat(2,y,[1 0]);