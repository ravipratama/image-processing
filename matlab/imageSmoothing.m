function hasilOperasi = imageSmoothing(citra)

    
    citra = double(citra);
    [n, m] = size(citra); %extraks baris kolom
    
    for x = 2: n-1
        for y = 2: m-1
            temp = citra(x-1, y-1) + citra(x-1, y) + citra(x-1, y-1)...
                 + citra(x, y-1) + citra(x, y) + citra(x, y-1)...
                 + citra(x+1, y-1) + citra(x+1, y) + citra (x+1, y-1);
             
            hasilOperasi(x, y) = temp / 9;
        end;
    end;
    hasilOperasi = uint8(hasilOperasi);
end
    
  
        