%Low speed
wL = 7;
cp1 = 0.24;
Kp1 = cp1*wL;

sim('Low_speed_sim');
plot(yout.Time,yout.Data,'LineWidth',2)
grid on


