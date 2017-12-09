% C_header.m - header for inclusion of filter or array coefficients in C file
%
% Usage: C_header(filename, h_name, h_order, h, L, fmt)
%        C_header(filename, h_name, h_order, h, L)         default fmt = '% 1.15f'
%        C_header(filename, h_name, h_order, h)            default L = length(h), fmt = '% 1.15f'
%
% filename = enter filaname in single quotes, e.g., 'h.dat'
% h_name   = name of filter coefficents in the C file in single quotes, e.g., 'h'
% h_order  = symbol for filter order in single quotes, e.g., 'M' or 'D', where M=length(h)-1 
% h        = MATLAB array holding filter coefficients (row or column)
% L        = total number of coefficients to be saved, pad zeros if L>length(h)
% fmt      = number format, e.g., '% g', '% 2.6e', '% .15g', etc.                
%
% Example: fs = 16; fc = 3.15; wc = 2*pi*fc/fs;
%          M = 100; n = 0:M;
%          wind = 0.54 - 0.46*cos(2*pi*n/M);
%          h = wind .* sinc(wc/pi*(n-M/2)) * wc/pi;   
%          C_header('h.dat', 'h', 'M', h);
%
%          the generated file is then included in the C program by
%
%          #include "h.dat"     whose contents are:   #define M 100   
%         
%                                                     float h[M+1] = {
%                                                        -0.000423463996252,
%                                                        -0.000419060708929,
%                                                        -0.000692713873539,
%                                                            --- etc.---
%                                                        -0.000419060708929,
%                                                        -0.000423463996252
%                                                        };
%

% S. J. Orfanidis - 332:348 DSP Lab - Spring 2011

function C_header(filename, h_name, h_order, h, L, fmt)

if nargin==0, help C_header; return; end
if nargin==4, L = length(h); fmt = '% 1.15f'; end
if nargin==5, fmt = '% 1.15f'; end 

h = [h(:); zeros(L-length(h),1)];    % pad zeros to length L
h = h(1:L);

M = L-1;                             % filter or array order

fp = fopen(filename, 'wt');

fprintf(fp, '// %s  -  filter or array coefficients\n', filename);
fprintf(fp, '// exported from MATLAB using C_header.m\n\n');

fprintf(fp, ['#define ', h_order, ' %d        // filter or array order\n\n'], M);

fprintf(fp, ['float %s[',h_order,'+1] = {\n'], h_name);

for i=1:M
   fprintf(fp, ['   ',fmt,',\n'], h(i));                         % '   % g,\n', h(i));
end

fprintf(fp, ['   ',fmt,'\n'], h(end));                           % '   % g\n', h(end));
fprintf(fp, '   };\n');

fclose(fp);
