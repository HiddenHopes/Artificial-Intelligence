/*P-67(2)*/
combine1([],[],[]).
combine1([H1|T1],[H2|T2],[H1,H2|T3]):- combine1(T1,T2,T3).