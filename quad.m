syms n w t ;

T = 2;
F = 1/T;
w = 2*pi*F;

f = @(t) t.^2;

a0 = 2/T*int(f,t,[-1 1]);

an = int(f.*cos(n*w*t),t,[-1 1]);

n = 1;
a1=eval(an);
n = 2;
a2=eval(an);
n = 3;
a3=eval(an);
n = 4;
a4=eval(an);
n = 5;
a5 = eval(an);

g = a0/2 + a1*cos(w*t) + a2*cos(2*w*t) + a3*cos(3*w*t) + a4*cos(4*w*t) + a5*cos(5*w*t);

t = 0:1/100:20;

geval = eval(g);

figure(1)
plot(t,geval)

%figure(2)
transf = fft(geval);
transf(1) = [];
transf(end) = [];

% suponiendo que la señal dura 20 segundos
% y la cantidad de muestras es el largo del vector
% entonces la frecuencia de sampleo es la cantidad
% de muestras dividido el tiempo total
fs = floor(length(geval)/t(end));
figure(3)
n = length(transf);
% power = abs(transf(1:floor(n/2))).^2; % power of first half of transform data
power = abs(transf)/n^2;
maxfreq = 2;                   % 2*2*1/T = 2 por nyquist otro 2 por tener ambos espectros neg y pos
% freq = (1:n/2)/(n/2)*maxfreq;    % equally spaced frequency grid
maxfre = 2^nextpow2(length(geval));
freq = (-n/2:floor(n/2))/(n)*maxfreq;
plot(freq,power)
xlabel('Frecuencia')
ylabel('Potencia')
%%
figure(4)
pts = 2^nextpow2(length(geval));
spec2 = fft(geval,pts);
%spec2(1) = [];
plot(abs(fftshift(spec2))/pts^2);
xlabel('muestra o posición en el vector')

y2 = ifft(spec2);
figure (5);
plot(t,geval,'b*',t,y2(1:2001),'r');
title('El espectro de la señal original - FFT')
xlabel('frecuencias $\left[\frac{1}{s}\right]$','Interpreter','latex','Fontsize',15);
