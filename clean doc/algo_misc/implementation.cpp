assert
binary search
bit
iterator operations
map 
priorityQ
set unordered_set
slice
slice (gslice)
sort
sort (index sort)
stream
switch case
tuple
var 
vector

###############################
# assert
###############################
assert(length >= 0); // die if length is negative.
assert(length >= 0 && "Whoops, length can't possibly be negative! (didn't we just check 10
lines ago?) Tell jsmith");
// BAD
assert(x++);
// GOOD
assert(x);
x++;
// Watch out! Depends on the function:
assert(foo());
// Here's a safer way:
int ret = foo();
assert(ret);
/////////////////////////////
int &ret=mem[i][w0];
if( ret !=-1 )return ret;
return ret=( ... ;
auto lambda = [](int x, int y) {return x + y;}; // C++11 --- had to specify type of x and y


###################################################################
Binary
###################################################################
This is called reducing the original problem to a decision (yes/no) problem.
call the main theorem states that binary search can be used if and only if for all x in S, p(x) implies p(y) for all y > x.
getting a yes answer for some potential solution x means that you’d also get a yes answer for any element after x. Similarly, if you got a no answer, you’d get a no answer for any element before x


bool p(int j){
    return (get<0>(g[i][j])) > wp ;
}


int bs( int lo, int hi, bool (*p)(int) ){
while (lo < hi)
    int mid = lo + (hi-lo)/2;    // peut causer des prob avec un tab 2 elmt {no, yes} à verif :/
    if (p(mid))
        hi = mid;
    else
        lo = mid+1;

    if (!p(lo))
        return -1;//complain:  p(x) is false for all x in S! !!!!!!!!!!!!!!!!!!

    return lo; // lo is the least x for which p(x) is true
}
----
Implementing binary search on reals is usually easier than on integers, because you don’t
need to watch out for how to move bounds:
binary_search(lo, hi, p){
while we choose not to terminate:
mid = lo + (hi-lo)/2
if p(mid) == true:
hi = mid
else:
lo = mid
return lo // lo is close to the border between no and yes
}
just use a few hundred iterations, this will give you the best possible precision without
too much thinking. 100 iterations will reduce the search space to approximately (hi-lo)/2^
100
Binary search in standard libraries
C++’s Standard Template Library implements binary search in algorithms lower_bound,
upper_bound, binary_search and equal_range, depending exactly on what you need to do.


##########################################################
# BIT
##########################################################
//print
cout<<  bitset<20>(x)  <<endl;

// IMG 1 @01
//Exemple
unsigned int x = 4376;
00000000000000000001000100011000

__builtin_clz(x) = 19	count leading 0-bits		x==0 => returns an undefined value.
__builtin_clzll(x)=51	cas x ull (on ajoute le suffixe ll pour travailler avec les ull)
__builtin_ctz(x) = 3	count trailing 0-bits 
__builtin_ffs(x) = 4 	find first set (1er bit à 1)
__builtin_popcount(x)=4	nombre de bit à 1


//Code Gray
printf("%d\n", k^(k>>1));//Original To code Gray

// code Gray  To Original
long grayInverse(long n) {
    	long ish=1, ans=n, idiv;
    	while(1) {
    		idiv = ans >> ish;
    		ans ^= idiv;
    		if (idiv <= 1 || ish == 32) return ans;
    		ish <<= 1; // double le nb de shifts la prochaine fois
    	}
}

##########################################################
#Iterator operations:
#######################################
advance
Advance iterator (function template )
distance
Return distance between iterators (function template )
begin
Iterator to beginning (function template )
end
Iterator to end (function template )
prev
Get iterator to previous element (function template )
next
Get iterator to next element (function template )

##########################################################
map
##############################################################
auto s=m.find(make_pair(k, t1)); //map.find("key")
if ( s !=m.end() )// found
{//cerr<<"("<< get<0>(s->first) <<" " << get<1>(s->first) <<" "<< (*s).second <<")";
return s->second;//valeur ~
}




##########################################################
#PriorityQ
##########################################################
//{
priority_queue<int , vector<pair<int,int>>, greater<pair<int,int>> >
trié selon, tiré dans l ordre DESC ( default )
v
priority_queue<int , vector< pair<int,int> >, greater<int> > q ;
q.push(make_pair(1,2));
q.push(make_pair(10,4));
q.push(make_pair(0,3));
pair<int,int> s;
s= q.top() ;
cout << s.fi;// val de priority
q.pop();
s= q.top() ;
cout << s.fi;
q.pop();
s= q.top() ;
cout << s.fi;
q.pop();
trié selon 1ere var , tiré dans l'ordre CROISSANT
v
priority_queue<int , vector<pair<int,int>>, greater<pair<int,int>> > q ;
//}



###################################################################
Set
###################################################################
set<int> s( vec.begin(), vec.end() ); vec.assign( s.begin(), s.end() );

multiset.erase(it) mara bark
multiset.erase(40) efface tt les occ de 40
insertion set : O(log n) or const with a hint
insertion unsorted_set O(n)
unsorted multiset O(1) -> O(n) worst
------
unordered_set<int> s(53);// n'affecte pas le nb 53 à la 1ere case nooooooo!  unordered_set( size_type bucket_count, ...)
// erasing from set
int main ()
{
std::set<int> myset;
std::set<int>::iterator it;
// insert some values:
for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
it = myset.begin();
++it; // "it" points now to 20
myset.erase (it);
myset.erase (40);
it = myset.find (60);
myset.erase (it, myset.end());
std::cout << "myset contains:";
for (it=myset.begin(); it!=myset.end(); ++it)
std::cout << ' ' << *it;
std::cout << '\n';
return 0;
}
// set::lower_bound/upper_bound
int main ()
{
std::set<int> myset;
std::set<int>::iterator itlow,itup;
for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
itlow=myset.lower_bound (30); // ^
itup=myset.upper_bound (60); // ^
myset.erase(itlow,itup); // 10 20 70 80 90
std::cout << "myset contains:";
for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
std::cout << ' ' << *it;
std::cout << '\n';
return 0;
}


##########################################################
#slice
##########################################################    
int main ()
{
  std::valarray<int> foo (12);
  for (int i=0; i<12; ++i) foo[i]=i*100;
int idx_start = 2;
int size = 3;
int pas = 4;
  std::valarray<int> bar = foo[std::slice(idx_start,size,pas)];

  std::cout << "slice(2,3,4):";
  for (std::size_t n=0; n<bar.size(); n++)
	  std::cout << ' ' << bar[n];
  std::cout << '\n';

  return 0;
}
#result ::     slice(2,3,4): 200 600 1000

##########################################################
#gslice    ;*
##########################################################       


##########################################################
#sort (index sort)
##########################################################
int a[100], p[100];// receive input
for (int i = 0; i < n; ++i) scanf("%d", &a[i]), p[i] = i;
sort(p, p+n, [=](int i, int j) { return a[i] < a[j]; });
##########################################################
#sort:
##########################################################
// using default comparison (operator <):
std::sort (myvector.begin(), myvector.begin()+4);
// using function as comp
std::sort (myvector.begin()+4, myvector.end(), myfunction);
//{
vector<double> tableau;
tableau.push_back(8);// comme _Array_Add()
tableau.pop_back(); //Et hop ! la dernière case a sauté
tableau.size() // Ubound(tab)
//Une fonction recevant un tableau d'entiers en argument
void fonction(vector<int> a)
void fonction(vector<int> const& a)
vector<double> encoreUneFonction(int a)
//-----------------------------------------
//Notez qu'il est aussi possible de créer des tableaux multi-dimensionnels de taille
variable en utilisant les vectors. Pour une grille 2D d'entiers, on devra écrire :
vector<vector<int> > grille;
grille.push_back(vector<int>(5)); //On ajoute une ligne de 5 cases à notre grille
grille.push_back(vector<int>(3,4)); //On ajoute une ligne de 3 cases contenant chacune le
nombre 4 à notre grille
//Chaque ligne peut donc avoir une longueur différente. On peut accéder à une ligne en utilisant les crochets:
grille[0].push_back(8); //Ajoute une case contenant 8 à la première ligne du tableau
grille[2][3] = 9; //Change la valeur de la cellule (2,3) de la grille
/*
Les tableaux multi-dimensionnels utilisant des vector ne sont pas la meilleure manière
d'accéder efficacement à la mémoire et ne sont pas très optimisés. On préférera donc
utiliser des tableaux multi-dimensionnels statiques à moins que le fait de pouvoir changer
la taille de la grille en cours de route soit un élément essentiel.
*/
vect.clear(); // reinitialise tab (size 0)
//A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to calling this function. A typical alternative that forces a reallocation is to
vector<T>().swap(x); // clear x reallocating
//}



##########################################################
# STREAM
##########################################################
//prend vect resultat qu'elle va reinitialiser
// return vect.size
char readline(vector<ll> &r)
{
std::string line;
std::getline(std::cin, line); //  <-----------------------------
std::istringstream line_buffer(line);
//std::vector<ll> r; //resultat à retourner
ll x;
r.clear(); // vide tab
op = '\0';
if (line_buffer.peek()!=EOF) {line_buffer >> op;
//r.push_back( (ll) x);
}
while(line_buffer.peek()!=EOF )
        {
            line_buffer >> x;
            line_buffer >> std::ws;  // eat up any leading white spaces



            //cout << x<<" , ";// traitement
            r.push_back(x);
        }

        return op;
}



#Switch case
#######################################
//galere ce truc
int main()
{ int i = 2;
switch (i) {
case 1: std::cout << "1";
case 2: std::cout << "2"; //execution starts at this case label
case 3: std::cout << "3";
case 4:
case 5: std::cout << "45";
break; //execution of subsequent statements is terminated
case 6: std::cout << "6";
}
std::cout << '\n';
switch (i) {
case 4: std::cout << "a";
default: std::cout << "d"; //there are no applicable constant_expressions
//therefore default is executed
}
std::cout << '\n';
switch (i) {case 4: std::cout << "a"; //nothing is executed
}
// when enumerations are used in a switch statement, many compilers
// issue warnings if one of the enumerators is not handled
enum color {RED, GREEN, BLUE};
switch(RED) {
case RED: std::cout << "red\n"; break;
case GREEN: std::cout << "green\n"; break;
case BLUE: std::cout << "blue\n"; break;
-3-
C:\Users\Karim\Desktop\base.cpp lundi 13 février 2017 22:39
}
// pathological examples
// the statement doesn't have to be a compound statement
switch(0)
std::cout << "this does nothing\n";
// labels don't require a compound statement either
switch(int n = 1)
case 0:
case 1: std::cout << n << '\n';
// Duff's Device: http://en.wikipedia.org/wiki/Duff's_device
}//Exemple 2
char keystroke = getch();
switch( keystroke ) {
case 'a':
case 'b':
KeyABPressed();
break;
default:
UnknownKeyPressed();
break;
}


#tuple
#######################################
tie(a, std::ignore, c) = oTuple;
// ne sont pas syncho: changer a ou oTuple n'affectera pas l'autre


#########################################
#VAR
register int x; // le compilateur choisira surement de placer la var dans le registre
memset (str,'-',6);
void func ( void (*f)(int) );




##########################################################
#VECTOR
##########################################################
segmentation fault core dumped --> acces en dehors du vector
vector<int> some_list { 1, 2, 3, 4, 5 }; // oui c++11
//vector< vector< bool > >
vector< vector< bool > > myvector( cols, vector<bool>( rows, false ) );
(!) .size est un size_t ==> pas d'operation pour le rendre negatif ça peut mal se passer
v.emplace_back(a,b); // shorter and faster than pb(mp(a,b))
// 2D
vector< vector< bool > > myvector( loula, vector<bool>( thenia, false ) );//ligne/col vérifié
vector.resize et non pas vector.reserve
Rq: tab multidim plus rapide que struct

std::reverse(copy.begin(), copy.end());


int myArray[3][3];
for(auto& rows: myArray) // Iterating over rows
{
for(auto& elem: rows)
{
// do some stuff
}
}
