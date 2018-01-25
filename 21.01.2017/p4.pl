
contain(katarina,olga).
contain(olga,natsha).
contain(natsha,irina).

in(X,Y):-contain(X,Y).
in(X,Y):-contain(X,Z),in(Z,Y).