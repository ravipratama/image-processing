clc;
clear;

citra = imread('lenanoise.jpg');

%paksakan menjadi satu layer
citra = citra(:,:,1);


h = [1/9 1/9 1/9; 1/9 1/9 1/9; 1/9 1/9 1/9];

hasil = imfilter(citra, h, 'conv');

subplot(1,2,1),imshow(citra),title('citrak asli');   
subplot(1,2,2),imshow(hasil),title('citra hasil operasi');   