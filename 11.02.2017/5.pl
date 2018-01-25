length([],0).
length([H|T],L):-length(T,W),L is W+1.