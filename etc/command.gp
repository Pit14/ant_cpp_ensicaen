set ylabel "data"
set xlabel "nombre de jours"
set title "simulation"

set grid

plot '../etc/evolution.txt' using 1:2 with lines title 'Ant', '../etc/evolution.txt' using 1:3 with lines title 'Food'
