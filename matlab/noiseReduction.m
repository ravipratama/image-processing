function hasil = noiseReduction(citra)
    [n, m] = size(citra);
    hasil = citra;
    
    for x = 2: n -1
        for y = 2: m -1
            data = [hasil(x-1, y-1), hasil(x-1, y), hasil(x-1, y+1)...
                    hasil(x, y-1), hasil(x, y), hasil(x, y+1)...
                    hasil(x+1, y-1), hasil(x+1, y), hasil(x+1, y+1)];
            hasilUrut = bubbleSort(data);
            nilaiTengah = median(hasilUrut);
            hasil(x, y) = nilaiTengah;
        end;
    end;
end