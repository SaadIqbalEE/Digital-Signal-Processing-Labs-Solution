function [convu, convu_n] = convolute(x, x_n, h, h_n)

h_flip = fliplr(h);
hn_flip = fliplr(h_n*-1);

convu_start = x_n(1)+h_n(1);
hn_start = hn_flip+convu_start;

tot = length(x)+length(h)-1;

convu_n = convu_start:convu_start+tot-1;
convu = zeros(1,tot);

for iter1 = 1:tot
    inter = intersect(hn_start,x_n);
    check = 0;
    for iter2 = 1:length(inter)
        inter_check = inter(iter2);
        
        num_h = find(hn_start==inter_check);
        num_x = find(x_n==inter(iter2));
        
        conv_check = h_flip(num_h)*x(num_x);
        check = check+conv_check;
    end
    convu(iter1) = check;
    
    convu_start = convu_start+1;
    hn_start = hn_start+1;
end

stem(convu_n,convu)
title('Convolution of x[n] and h[n]')