function tengah = median(array)
    n = length(array);
    h = mod(n, 2);
    if (h == 1)
        k = (n+1) /2; %jumlah data ganjil
        tengah = array(k);
    else
        k = n / 2; %jumlah data genap
        tengah = (array(k) + array(k+1)) /2;
    end;
end