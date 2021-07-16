clc;
clear;

citra = imread('lenanoise.jpg');

%paksakan menjadi satu layer
citra = citra(:,:,1);



hasil = medfilt2(citra, [3, 3]);

subplot(1,2,1),imshow(citra),title('citrak asli');   
subplot(1,2,2),imshow(hasil),title('citra hasil operasi');   