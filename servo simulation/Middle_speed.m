%Middle speed
wL = 50;
cp2 = 0.24;
cv2 = 0.96;
Kp2 = cp2*wL;
Kv2 = cv2*wL;

sim('Middle_speed_sim');
plot(yout.Time,yout.Data,'LineWidth',2)
grid on
