
% Problem Background:
% This script performs a binary closing on a shape with a hole at the center  
% Ideally the area (pixel count) of the shape after the closing operation
% should remain the same, irrespective of any translation performed on the shape along the x or y-axis. 
% However, because of a bug in the 'buggy_imclose' function, the area changes for
% particular shifts along the x and y axis

% Problem Objective:
% Modify the script given below such that, for a given square size, 
% the area remains the same for all shifts performed


% Pointers: 
% You are free to use whatever means possible with the following constraints
% 1. The image has to go through all the shifts given in the script
% 2. You cannot modify the buggy_imclose function

% BUG FIXED, EXPLANATION:
% In this case, the structuring element is always a single array of elements.
% Hence, we add columns while dilating and remove columns while eroding. The 
% erosion operator removes a pixel if, when the structuring element is centered
% on the pixel, has background '0's corresponding to the element. But in this
% case, this was not happening, since after dilation, the pixels were at the 
% edge of the image, hence resulting in a bigger array, at the last shift.
% To overcome this, I padded the input array with a corresponding number of 
% 0s, which lets the structuring element erode the pixels at the edge and 
% return the correct shape again, while filling the hole in between.


all_square_sizes = [50,100,250];
for ii = 1:length(all_square_sizes)
    square_size = all_square_sizes(ii);
    half_square_size = square_size/2;
    original_mat = zeros(square_size*2);
    original_mat(half_square_size:half_square_size+square_size-1,half_square_size:half_square_size+square_size-1) = ones(square_size);
    
    hole_size = round(half_square_size/10);
    original_mat(square_size-hole_size:square_size+hole_size,square_size-hole_size:square_size+hole_size) = zeros(hole_size*2+1);
    
    shift_incr = half_square_size/5;
    all_areas = [];
    for shift1 = [0:shift_incr:half_square_size]
        for shift2 = [0:shift_incr:half_square_size]
            inp = padarray(circshift(original_mat,[shift2 shift1]), [0,4*hole_size-2]); % Padding added
            closed_mat = buggy_imclose(inp,ones(1,4*hole_size));
            all_areas = [all_areas sum(closed_mat(:))];
        end
    end
    
    try 
        assert(all(all_areas == square_size*square_size))
        disp('All areas equal. Success!')
    catch
        error('All areas not equal. Try again.')
    end
end




    