a) while(i > 0) k = 2 * k;  --- Endlosschleife, i wird nie geaendert.
b) while(i != 0) i = i - 2; --- Ist i ungerade oder kleiner 0, tritt im Programm eine Endlosschleife auf.
c) while(n != i) { ++i; n = 2 * i; } --- Ist i ungleich -1 ->Endlosschleife. 