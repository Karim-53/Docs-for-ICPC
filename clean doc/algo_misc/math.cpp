~ <=> defini <=> !=-1
doubles can never give you more than 15 decimal digits of precision

//On x86, all types except 16-bit (which is slow) are equally fast
base: 10^x
Maximum val for char: 2.10 u:2.41 size:1
Maximum val for short: 4.52 u:4.82 size:2
Maximum val for int: 9.33 u:9.63 size:4
Maximum val for ll: 18.96 u:19.27 size:8


#Syntaxe
###############################################################
scanf: %x %o %e
setprecision() fait deja l'arrondi




Pi=2*acos(0)
//nbre de digit
(int) floor(1+ log10( (double)a) ) 
si on veux le nbre de case pour la base 2
il faudra mettre log2
//racine n eme de a:
pow(a,1.0/n)
ne fait pas les a<0

nombre de diviseur en moyenne log(n) | complexité gcd log(n)
ln(10^6) = 13.8 | EPS 1e-9
les func trigo prennent des val en radian


##########################################################
Un coefficient binomial {{m} {n}}} est divisible par un nombre premier p si et seulement si
au moins un chiffre de n en base p est plus grand que le chiffre correspondant de m.


######################################
#Get Divisors
######################################
vector<ll> getdiv(ll g ){
set<ll> s;
ll q = (ll) sqrt(g);
for (ll i=1; i< q; ++i ){
if (g%i==0){
s.insert(i);
s.insert(g/i);
}
}
if (q*q==g) s.insert(q);
return vector<ll>(s.begin(),s.end() ) ;
}


##########################################################
Geo
##############################################################
// 2D rotation
void rotate(double &x, double &y, double theta) {
    double tx = cos(theta) * x - sin(theta) * y;
    double ty = sin(theta) * x + cos(theta) * y;
    x = tx, y = ty;
}


//p est à l'interieur du triangle => l'aire des 3 ptit triange == aire du triangle
eq droite 2D: ax + by+ c = 0
à partir de 2 point: (u,v) (u`,v`)

a = v`-v
b = u-u-u
c = -(bv+au)
intersection 2 droite (à verif)
ax + by+ c = 0
a`x + b`y+ c` = 0
y = (c+ c`*a/a`) / (b`*a/a`-b)
x = (-b*y-c)/a
(ne pas div par zero!)
