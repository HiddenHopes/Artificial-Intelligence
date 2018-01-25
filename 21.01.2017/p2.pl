child(babor,humayun).
child(humayun,akbar).
child(akbar,jahangir).
child(jahangir,shahajahan).

descendant(X,Y):-child(X,Y).
descendant(X,Y):-child(X,Z),descendant(Z,Y).