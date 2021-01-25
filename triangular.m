% Datos de la función
A = 1;
T = 1;
f = 1/T;
w = 2*pi*f;

% cantidad de términos dependientes de t
term = 2;
syms t;

% primer término de la función
g = A/2;

% generamos la función
for k=1:1:term
	% Sin Simplificar
	% g = g +2*A/pi^2/(2*k-1)^2 * (cos((2*k-1)*pi)-1)*cos((2*k-1)*w*t) ;
	% Simplificada
	g = g -4*A/pi^2/(2*k-1)^2 * cos((2*k-1)*w*t) ;
end
g
t = 0:T/20:3;
plot(t,eval(g))
texto=sprintf('Función con %d términos dependientes de t',2*k-1);
title(texto)