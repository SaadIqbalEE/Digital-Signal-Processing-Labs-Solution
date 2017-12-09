function [even odd] =evenodd(in_indexes, values)
%Check
if(max(in_indexes)==abs(min(in_indexes)) && length(in_indexes)== 2*max(in_indexes)+1)
for i=1:length(in_indexes)    
odd(i)= (values(i)-values(length(in_indexes)+1-i))/2;   %odd part
even(i)= (values(i)+values(length(in_indexes)+1-i))/2;  %even part
end

subplot(3,1,1)
stem(in_indexes,values)
title('Original')

subplot(3,1,2)
stem(in_indexes,even)
title('Even part')
subplot(3,1,3)
stem(in_indexes,odd)
title('Odd part')

else
    disp('Inputs are invalid')
end
