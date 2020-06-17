va0 = 100;
vb0 = 0;

ma1 = 10;
mb1 = 10;
vaf1 = ((ma1 - mb1) / (ma1 + mb1)) * va0;
vbf1 = ((2 * ma1) / (ma1 + mb1)) * va0;
fprintf("Vaf1: %.2f", vaf1);
fprintf("Vbf1: %.2f", vbf1);

ma2 = 1000;
mb2 = 0;
vaf2 = ((ma2 - mb2) / (ma2 + mb2)) * va0;
vbf2 = ((2 * ma2) / (ma2 + mb2)) * va0;
fprintf("Vaf2: %.2f", vaf2);
fprintf("Vbf2: %.2f", vbf2);

ma3 = 0;
mb3 = 1000;
vaf3 = ((ma3 - mb3) / (ma3 + mb3)) * va0;
vbf3 = ((2 * ma3) / (ma3 + mb3)) * va0;
fprintf("Vaf3: %.2f", vaf3);
fprintf("Vbf3: %.2f", vbf3);

x1 = 100;
y1 = vaf1;
plot(x1, y1);
