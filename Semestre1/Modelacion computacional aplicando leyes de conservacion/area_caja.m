% Main 
[w, l, h] = read();
area_calc(w, l, h);

% box_area
% Receives the width, length, and height to determine the area
% Input: width, length, height
% Output: area
function area_calc(w, l, h)
    area = (2 * w * h) + (2 * w * l) + (2 * h * l);
    fprintf("The area of the box is %.2f", area);
end

% Function read
% Asks the user for the width, lenght, and height
% Input: none
% Output: width, length, height
function [w, l, h] = read()
    w = input("Enter de width: ");
    l = input("Enter de length: ");
    h = input("Enter de height: ");
end