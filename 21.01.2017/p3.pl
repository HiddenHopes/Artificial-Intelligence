numeral(0).

numeral(succ(X)) :- numeral(X).

sum(0,Y,Y).

sum(succ(X),Y,succ(Z)):-sum(X,Y,Z).