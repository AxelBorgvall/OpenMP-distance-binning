The problem this project was written to solve is to read a file of particle positions, compute the distances between them, and count the number of pair each distance apart. The main challenge arises from the potentially very large number of particles, much more than what can fit in memory. The number of distances to be computed also scales as N^2, requiring efficient parallelization. 

The input is read from a file of the format:
+01.330 -09.035 +03.489
-03.718 +02.517 -05.995
+09.568 -03.464 +02.645
-09.620 +09.279 +08.828
+07.630 -02.290 +00.679
+04.113 -03.399 +05.299
-00.994 +07.313 -06.523
+03.376 -03.614 -06.657
+01.304 +09.381 -01.559
-04.238 -07.514 +08.942

This fixed format allowed for optimizing file reading by not searching for and seperating values at spaces, but rather using the known positions of the values in the file to more quickly load chunks of it into memory. The output is printed to the terminal in the format:03.00 1
05.54 1
05.85 1
05.91 1
06.07 1
06.54 1
...

The fixed precision of the output at 2 decimals and the memory constraint of large input lead to the choice of eschewing floating point numbers for a fixed point integer representation. This allowed larger chunks of the input to be kept in memory simultaneously. The program also uses OpenMP for parallelization when processing the loaded chunks. 
