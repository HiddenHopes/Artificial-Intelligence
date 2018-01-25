twice([a,b],[a,a,b,b]).

twice([],[]).
twice([H1|T1],[H1,H2|T2]):-twice(T1,T2).