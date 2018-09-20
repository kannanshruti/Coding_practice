% Problem Objective:
% This script performs pattern matching in the function find_kernel_pix
% Your objective is to make a function find_kernel_pix_faster which
% improves the processing speed while giving the same output as find_kernel_pix_faster
% Modify only the function find_kernel_pix_faster. 

% Pointers: You are free to use whatever means possible to make the code faster. 
% 

function code_optimization_2()
    for ii_loop = 1:10
        [org_im kernel] = read_image_kernel();

        tic 
        xypix = find_kernel_pix(org_im,kernel);
        Timetaken(ii_loop) = toc;

        tic 
        xypix_faster = find_kernel_pix_faster(org_im,kernel);
        Timetaken_faster(ii_loop) = toc;
        if abs(sum(xypix - xypix_faster)) >= 5 % Difference between algorithms should not exceed 5 pixs
            fprintf('Answer between the algorithms are different \n');
        end
    end
    % figure, 
    plot(Timetaken,'g'); hold on; plot(Timetaken,'r*');
    plot(Timetaken_faster,'b');hold on; plot(Timetaken_faster,'r*');
    fprintf(' Mean time taken by Current algo = %d \n',mean(Timetaken));
    fprintf(' Mean time taken by Faster algo = %d \n',mean(Timetaken_faster));
end

function [org_im kernel] = read_image_kernel();
    org_im = imread([pwd '\000000000_B11C2.bmp']);
    kernel = imread([pwd '\kernel.jpg']);
    if rand < 0.3
        org_im = fliplr(org_im);
        kernel = fliplr(kernel);
    elseif rand > 0.7
        org_im = flipud(org_im);
        kernel = flipud(kernel); 
    end
end


function xypix = find_kernel_pix(org_im,kernel)
    temp   = normxcorr2(kernel,org_im);
    figure(101), imshow(temp,[]); hold on;
    max_value = 0;
    for ii = 1:size(temp,1)
        for jj = 1:size(temp,2)
           curr_val = temp(ii,jj);
           max_store(ii,jj) = curr_val;
           if curr_val > max_value
               max_value = curr_val;
               max_ii = ii;
               max_jj = jj;
           end
        end
    end

    figure(102), imshow(org_im,[]); hold on;
    plot(max_jj,max_ii,'r*','linewidth',10)
    xypix = [max_jj,max_ii ];
end

function xypix = find_kernel_pix_faster(org_im,kernel)
    temp   = normxcorr2(kernel,org_im);
    figure(103), imshow(temp,[]); hold on;
    [val1, rows] = max(temp); % For every column, which row has highest value
    [val2, max_jj] = max(val1); % For the above result, which column has highest value
    max_ii = rows(val1 == val2); % Corresponding row of the higest element

    figure(104), imshow(org_im,[]); hold on;
    plot(max_jj,max_ii,'r*','linewidth',10)
    xypix = [max_jj,max_ii ];   
end
    