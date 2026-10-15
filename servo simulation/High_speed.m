cp = 0.24;
cv = 0.82;
Jm = 0.000054;
Ng = 1;
psi = 0.002;
wL = 94.2;
%Pick NL value (5.5 or 9)
NL = 5; %NL = 9;
%Load parameters KL, JL, DL
JL = NL*(Ng^2)*Jm;
KL = (wL^2)*JL;
DL = 2*psi*sqrt(KL*JL);
%Position loop gain Kp and velocity loop gain Kv
Kp = cp*wL;
Kv = cv*wL;
Kvg = (Jm+JL/Ng^2)*Kv;
sim ('High_speed_sim');
plot(yout.Time,yout.Data,yout2.Time,yout2.Data,'LineWidth',2)
grid on

