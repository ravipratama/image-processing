function hasil = bubbleSort(array)
    n = length(array);
    hasil = array;
    for i=1 : n-1
        for j=1 : n-1
            if (hasil(j) > hasil(j+1))
                temp = hasil(j);
                hasil(j) = hasil(j+1);
                hasil(j+1) = temp;
            end
        end;
    end;
end